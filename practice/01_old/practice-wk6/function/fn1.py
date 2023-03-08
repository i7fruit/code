#!/usr/bin/env python3
# Functions can be stored in data structures
def hello(text):
    """This function takes a value and
    prints it to the screen"""
    print("Hello, {}".format(text))

# A list populated with functions
list0 = [hello, str.upper, str.capitalize]

# Prints the content of the list
for i in list0:
    print(i)