#!/usr/bin/env python3

from time import sleep
from tkinter import Tk 
from tkinter.filedialog import askopenfilename
import os
import platform



os_name = platform.uname().system




print("""
███╗ ██████╗ ███╗    ██████╗  █████╗ ██╗   ██╗     ██████╗ ██╗   ██╗████████╗██████╗ ██╗      █████╗ ██╗   ██╗
██╔╝██╔═████╗╚██║    ██╔══██╗██╔══██╗╚██╗ ██╔╝    ██╔═══██╗██║   ██║╚══██╔══╝██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝
██║ ██║██╔██║ ██║    ██║  ██║███████║ ╚████╔╝     ██║   ██║██║   ██║   ██║   ██████╔╝██║     ███████║ ╚████╔╝ 
██║ ████╔╝██║ ██║    ██║  ██║██╔══██║  ╚██╔╝      ██║   ██║██║   ██║   ██║   ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  
███╗╚██████╔╝███║    ██████╔╝██║  ██║   ██║       ╚██████╔╝╚██████╔╝   ██║   ██║     ███████╗██║  ██║   ██║   
╚══╝ ╚═════╝ ╚══╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝        ╚═════╝  ╚═════╝    ╚═╝   ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝


                            ██████╗ ██╗   ██╗██████╗ ███████╗██╗  ██╗███████╗
                            ██╔══██╗╚██╗ ██╔╝╚════██╗██╔════╝╚██╗██╔╝██╔════╝
                            ██████╔╝ ╚████╔╝  █████╔╝█████╗   ╚███╔╝ █████╗  
                            ██╔═══╝   ╚██╔╝  ██╔═══╝ ██╔══╝   ██╔██╗ ██╔══╝  
                            ██║        ██║   ███████╗███████╗██╔╝ ██╗███████╗
                            ╚═╝        ╚═╝   ╚══════╝╚══════╝╚═╝  ╚═╝╚══════╝
                                                 


""")




Tk().withdraw()
while 1:
    file_path = askopenfilename(title="Choose the Python File")
    if input("[*] Do you want to add icon (yes/no) : ").lower() in ["y", "yes"]:
        print("[+] Choose Icon for the EXE\n\n") 
        sleep(1)
        icon = askopenfilename(title="Choose Icon")
        if icon.split(".")[-1] != "ico":    
            print("[!] Please Choose Ico file.\n\n")
            continue
        os.system(f'pyinstaller --onefile -i {icon} {file_path}')
    elif input("[*] Do you want to embed a file (yes/no) : ").lower() in ["y", "yes"]:
        embeded_file = askopenfilename(title="Choose File to Embed")
        os.system(f'pyinstaller --onefile -i {icon} {file_path} --add-data "{embeded_file};."')

    else:
        os.system(f'pyinstaller --onefile {file_path}')
    if os_name == "Windows":
        os.system("move .\\dist\\*.exe .\\") 
        os.system("rmdir /S /Q dist")
        os.system("rmdir /S /Q build")
        os.system("del *.spec")
    else: # any Unix based system
        os.system("mv ./dist/* ./") 
        os.system("rm -rf dist")
        os.system("rm -rf build")
        os.system("rm -rf *.spec")
    break

