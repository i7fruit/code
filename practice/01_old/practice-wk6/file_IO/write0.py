#!/usr/bin/env python3
# write0.py
# Mon, 02.18.19 23:28hrs
#
# This program writes the contents of a list
# to a file using the write() function

# A list containing items to write to a file
countries = ["United States", "Angola", "Ghana", "Brazil"]

with open("world.txt", "w", encoding="utf-8") as c:
    for i in countries:
        c.write(i)
        c.write("\n")
        # The two lines in the for loop can also
        # be substituted for the line
        # print(i, file = c)