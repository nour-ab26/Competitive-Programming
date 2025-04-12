#!/usr/bin/env python3

from pytube import YouTube
import requests


urls = {}
while 1:
    print("[+] Type Done When you finish from URLS.")
    url = input("Enter a Valid URL > ")
    if url.lower() == "done":
        break
    file_name = input("Enter the name of the video > ")
    print("Checking ...")
    if requests.get(url).status_code == 200 :
        try :
            yt = YouTube(url)
            urls[url] = (yt, file_name)
        except Exception:
            print("[!] Please Enter a Valid URL.")
            continue
    else :
        print("[!] Please Enter a Valid URL.")
        continue

save_path = input("Where you want To save the Videos > ")

for link in urls:
    print("[*] Downloading ...")
    d_video = urls[link][0].streams.get_highest_resolution()
    try:
        d_video.download(output_path=save_path, filename=urls[link][1])
        print(f'[+] "{urls[link][1]}" Has Been Downloaded Successfully.')
    except Exception:
        print("[!] Error.")

