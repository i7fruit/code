#!/usr/bin/env python3
# fn2.py
# Sat, March 23 2019 09:57hrs
#
# This program accesses function objects stored
# inside a list
def hello(text):
    """This function takes a value and
    prints it to the screen"""
    print("Hello, {}".format(text))

# A list populated with functions
list0 = [hello, str.upper, str.capitalize]

# A function object stored in the list can be called
# without being first assigened to a variable
print(list0[1]("cats suck"))

# Prints the content of the list
for i in list0:
    print(i, i("what's happening?"), sep="\n", end="\n\n")