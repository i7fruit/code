# mario.py

from cs50 import get_int
from cs50 import get_string

# prompts the user for the pyramid height
while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

# Calculates initial amounts for space and pound characters
space = height - 1
pound = height - space

# draws the pyramid
for i in range(height):
    j = space
    k = pound

    # draws left half of pyramid
    while j > 0:
        print(" ", end="")
        j -= 1
    while k > 0:
        print("#", end="")
        k -= 1

    # draws the middle space
    print("  ", end="")

    # resets k to draw right half of pyramid
    k = pound
    while k > 0:
        print("#", end="")
        k -= 1
    print()

    # updates amounts of spaces and # chars to be drawn
    space -= 1
    pound += 1