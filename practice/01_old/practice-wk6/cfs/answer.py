from cs50 import get_string

s = get_string("Are you a man? (y/n): ")

if s == "Y" or s == "y":
    print("Yes")
elif s == "N" or s == "n":
    print("No")