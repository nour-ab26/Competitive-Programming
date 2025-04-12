import requests as req
import os



def url_extracter(f):
    with open(f) as file:
        urls = file.readlines()
    return [u.split()[1] for u in urls]

def file_extracter(f):
    with open(f) as file:
        urls = file.readlines()
    return [u.split()[0] for u in urls]


def download_file(u, df):
    img_data = req.get(u).content
    with open(df, "wb") as img:
        img.write(img_data)


yoga_dir = "yoga_dataset_links"

zdo = [
    "Child_Pose_or_Balasana_",
    "Cobra_Pose_or_Bhujangasana_",
    "Downward-Facing_Dog_pose_or_Adho_Mukha_Svanasana_",
    "Low_Lunge_pose_or_Anjaneyasana_",
    "Warrior_II_Pose_or_Virabhadrasana_II_",
    "Warrior_I_Pose_or_Virabhadrasana_I_",
    "Warrior_III_Pose_or_Virabhadrasana_III_"
]

zdo = [x+".txt" for x in zdo]

files = os.listdir(yoga_dir)

for f in files:
    if f not in zdo:
        continue
    fx = f"{yoga_dir}/{f}"
    urls = url_extracter(fx)
    filenames = file_extracter(fx)
    for i, file in enumerate(filenames):
        dir = file.split("/")[0]
        curr_file = file.split('/')[1]
        print(f"[*] Trying to download {curr_file}...")
        try:
            os.mkdir("DS2/"+dir)
        except Exception:
            pass
        try:
            download_file(urls[i], "DS2/"+file)
            print(f"[+] File : {curr_file} has been downloaded successfully.")
        except Exception:
            print(f"[!] Invalid URL to download {curr_file}.")
            pass