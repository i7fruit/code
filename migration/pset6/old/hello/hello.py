#!/usr/bin/env python3
# hello.py
# This program prompts the user
# for a name, and displays the
# result to the screen using the
# print function
from cs50 import get_string

name = get_string("What is your name?\n")
print("hello,", name)