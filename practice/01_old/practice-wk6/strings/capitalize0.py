# capitalizes a string
from cs50 import get_string

s = get_string("Enter text: ")

# prints a space after each character
for c in s:
    print(c, end=" ")

# prints a newline
print()

# prints each character as uppercase
for c in s:
    print(c.upper(), end="")

# prints a newline
print()