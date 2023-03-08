# read0.py
# Mon, 02.11.19 22:02hrs
# This program prints the contents of a file
# a few bytes at a time
f = open("text.txt", encoding="utf-8")

p = f.read(5)
while p:
    print(p, end="")
    p = f.read(5)
f.close()