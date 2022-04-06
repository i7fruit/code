#!/usr/bin/env python
# Pset 6 mario.py (more comfortable)

from cs50 import get_int

# Prompts the user for the height of the pyramid
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# Computes the width
width = (height * 2) + 2

# Draws both pyramids
hash_ctr, space_ctr = 1, height - 1

for row in range(height):
    # Builds left half
    i, j = 0, 0
    while i < space_ctr:
        print(" ", end="")
        i += 1

    while j < hash_ctr:
        print("#", end="")
        j += 1

    # Prints gap
    print("  ", end="")

    # Builds right half
    j = 0
    while j < hash_ctr:
        print("#", end="")
        j += 1

    # Updates space_ctr and hash_ctr
    hash_ctr += 1
    space_ctr -= 1
    print()