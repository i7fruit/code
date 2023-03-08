# capitalize4.py
# Fri, 02.01.19 15:16hrs
# Prints out the initials of a name
from cs50 import get_string

s = get_string("Enter name: ")
n = len(s)
i = 0
while not(s[i].isalpha()):
    i += 1

flag = True
spa = False

for j in range(n - i):
    if s[i + j].isalpha() and flag:
        print(s[i + j].upper(), end="")
        flag = False
        spa = True

    elif not(s[i + j].isalpha()):
        flag = True
        spa = False

print()