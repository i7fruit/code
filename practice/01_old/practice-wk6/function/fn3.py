#!/usr/bin/env python3
# fn3.py
# Sun, March 24 16:23hrs
#
# Functions can be passed as arguments to other functions
def cap(text):
    """Takes text input and prints
    it out in uppercase letters"""
    print(text.upper())

def low(text):
    """Takes text input and prints it
    out in lowercase letters"""
    print(text.lower())

cap("hello!")

def hi(fn):
    """Takes a function argument, and prints its
    output to the screen"""
    hello = fn(input("Enter text: "))
    print(hello)

# Passed the cap() function as an argument
# to the hi() function
hi(cap)

hi(low)