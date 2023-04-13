#!/usr/bin/env python3
# read1.py
# Opening a file with the "with" keyword,
# ensures that the file is closed automatically
# after the statements in the with block have been
# executed
with open("text.txt", mode = "r", encoding = "utf-8") as f:
    print(f.readl())