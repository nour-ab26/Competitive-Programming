#!/usr/bin/env python3

import webbrowser



urls = [url.strip() for url in open("urls.txt", "r").readlines()]


for url in urls:
    webbrowser.open(url)