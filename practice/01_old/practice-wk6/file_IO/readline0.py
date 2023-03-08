# readline0.py
# Mon, 02.11.19 22:51hrs

# The readline() method reads data from
# a file one line at a time
f = open("text.txt", encoding="utf-8")

# prints the first line
print(f.readline(), end="")

# prints the second line
print(f.readline(), end="")

f.close()