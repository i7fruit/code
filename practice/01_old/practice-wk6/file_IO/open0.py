#!/usr/bin/env python3
# open0.py
# Mon, 02.11.19 20:28hrs
# This program opens a file for reading
# saves the read data into a buffer, and
# prints it to the screen

# The open() function creates a file object
# and assigns to the name specified
f = open("text.txt", encoding="utf-8")

# prints the contents of the file
print(f.read())

# closes the file
f.close()