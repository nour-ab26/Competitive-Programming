import requests as req
import os
import time



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

files = os.listdir(yoga_dir)[64:]

for f in files: 
    try:
        fx = f"{yoga_dir}/{f}"
        urls = url_extracter(fx)
        filenames = file_extracter(fx)
        for i, file in enumerate(filenames):
            dir = file.split("/")[0]
            curr_file = file.split('/')[1]
            print(f"[*] Trying to download {curr_file}...")
            try:
                os.mkdir("DS/"+dir)
            except Exception:
                pass
            try:
                download_file(urls[i], "DS/"+file)
                print(f"[+] File : {curr_file} has been downloaded successfully.")
            except Exception:
                print(f"[!] Invalid URL to download {curr_file}.")
                pass
    except Exception:
        continue