#!/usr/bin/env python3
# read2.py
# Mon, 02.18.19 23:17hrs
# If one tries to open a file that doesn't exist,
# the interpreter will raise a FileNotFound Error.
# To handle this, we wrap the code in a try block
# so we can handle a FileNotFound exception
try:
    with open("foo.txt", "r", encoding="utf-8") as f:
        text = f.read()
except FileNotFoundError:
    text = None

print(text)