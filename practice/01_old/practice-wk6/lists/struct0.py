# list1.py
# Sat, 02.02.19 16:38hrs
# Hash Table

from cs50 import get_string

# creates and empty list
students = []

# retrieves student's name and dorm
for i in range(3):
    name = get_string("name: ")
    dorm = get_string("dorm: ")

    # creates hash table of key:value pairs to store the info
    j = {"name": name, "dorm": dorm}

    # appends the info from the hash table to the list
    students.append(j)

# prints the list
for j in students:
    print(f"{j['name']} lives in {j['dorm']} house")