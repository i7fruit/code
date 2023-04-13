#!/usr/bin/env python3
# fn4-map.py
# Python's built-in map() function takes a function
# and an iterable, and calls the function on each element
# in the iterable, yielding the results as it goes along

# Prints out text in uppercase characters
def caps(text):
    """Prints out character string arguments
    in uppercase characters"""
    print(text.upper())

# Multiplies an integer by 2
def doubles(x):
    """Multiplies a given argument by 2"""
    print(x * 2)

# Creates a list of text
words = list(map(caps, ["one", "two", "three"]))

for word in words:
    print(word)

ints = list(map(doubles, [29, 8, 32, 5]))

for i in ints:
    print(i)