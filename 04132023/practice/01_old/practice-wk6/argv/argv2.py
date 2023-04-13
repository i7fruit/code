# argv2.py
# Sat, 02.02.19 12:49hrs

# iterates over each character
# in the command line arguments
from sys import argv

# for every word in the list
for s in argv:
    # for every character in each word in the list
    for c in s:
        print(c, end=" ")
    print()