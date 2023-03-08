# dic0.py
# Tue, 02.05.19 1948hrs
#
# dictionaries are collections that are
# unordered, but are changeable and indexed.
# They have keys and values

pizzas = {
    "cheeze": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}

# changes value of one of the keys
pizzas["cheeze"] = 18

# adds a new key
pizzas["bacon"] = 4

# prints out the keys in the dictionary
for i in pizzas:
    print(i, end=" ")
print("\n")

# also prints out the keys using the keys() method
for key in pizzas.keys():
    print(key)
print()

# prints the values
for i, j in pizzas.items():
    print(j, end=" ")
print("\n")

# prints the dictionary
for i, j in pizzas.items():
    print("A whole {} pizza costs ${} dollars".format(i, j))