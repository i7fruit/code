# dict1.py
# Fri, 02.09.19

shapes = {
    "triangle": "blue",
    "pentagon": "brown",
    "square": "green"
}

# prints the dictionary
print(shapes)

# prints the keys
for i in shapes:
    print(f"{i}")

print()

# adds an item to the dictionary
shapes["octagon"] = "red"

# removes an item from the dictionary
del(shapes["pentagon"])

# prints the values
for i, j in shapes.items():
    print(f"{j}")

# using the dict() constructor
# a new dictionary can be created using the dict() constructor
# but keys are not written as strings
students = dict(foo = "gold", mark = 2, water = 2.3)
print()
# prints the dictionary
for i, j in students.items():
    print("{}: {}".format(i, j))