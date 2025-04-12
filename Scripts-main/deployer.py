import os
from tkinter import *
from tkinter import filedialog
import shutil


root = Tk()
root.withdraw()

my_dir = filedialog.askdirectory(title="Choose the source directory")
dir = filedialog.askdirectory(title="Choose the target directory")

os.chdir(dir)
target_content = os.listdir()

exceptions = [".", "..", ".git", ".gitignore", "deployer.py"]

for file in target_content:
    if file not in exceptions:
        try:
            os.remove(file)
        except Exception:
            shutil.rmtree(file)

os.chdir(my_dir)
content = os.listdir()

for file in content:
    if file not in exceptions:
        try:
            shutil.copy2(file, dir)
        except PermissionError:
            shutil.copytree(file, f"{dir}/{file}")  
        print(f"[o] File {file} has been moved.")



print("\n\n[+] Pushing for the remote website...\n")
os.chdir(dir)
os.system("git add .")
os.system(f"git commit -m \"{input('[*] Commit: ')}\"")
os.system("git push")


print("\n\n[+] Pushing for my GitHub...\n")
os.chdir(my_dir)
os.system("git add .")
os.system(f"git commit -m \"{input('[*] Commit: ')}\"")
os.system("git push")