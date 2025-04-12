import os
from PIL import Image


dir = "DS2"


for d in os.listdir(dir):
    sub_dir = dir+"/"+d
    for i in os.listdir(sub_dir):
        img = sub_dir+"/"+i
        try:
            Image.open(img)
        except:
            os.remove(img)