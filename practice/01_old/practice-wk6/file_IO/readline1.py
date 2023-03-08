# readline1.py
# Mon, 02.11.19 23:12hrs

# uses a for loop to print the
# contents of a text file line by line
f = open("text.txt", "r", encoding="utf-8")

words = [] # an empty list

for line in f:
    # saves each line to the list
    words.append(line)

# prints the list
print(words)

f.close()