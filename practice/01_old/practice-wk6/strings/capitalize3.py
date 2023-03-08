# capitalizes the first character of a name
from cs50 import get_string

s = get_string("s:")

# string length
n = len(s)

i = 0

# ignores characters before first alphabet
while not(s[i].isalpha()):
    i += 1

# flag indicates searching for letters
flag = True

# flag indicates searching for spaces
spa = False

# iterates over the string
for j in range(n - i):
    # if searching for letters and find one,
    # capitalize it, turn flag off to indicate
    # not searching, then turn spa on to search
    # for spaces
    if s[j + i].isalpha() and flag:
        print(s[j + i].upper(), end="")
        flag = False
        spa = True

    # if another letter found, but flag is off
    # just print
    elif s[j + i].isalpha() and not(flag):
        print(s[j + i], end="")

    # if character is not a letter...
    elif not(s[j + i].isalpha()):
        # ...and char is a space, and you're looking, print
        # the space and turn spa off to show no longer searching.
        # But turn flag on to search for new letters
        if s[j + i] == " " and spa:
            print(s[j + i], end="")
            spa = False
            flag = True

        # if char is not a space, just print and turn on
        # flag to search for next letter
        elif not(s[j + i] == " "):
            print(s[j + i], end="")
            flag = True

print()