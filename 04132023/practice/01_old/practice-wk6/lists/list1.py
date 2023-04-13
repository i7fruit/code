# list1.py
# Mon, 02.04.19
# a list can also be created using
# the list() function

names = list(("one", "two", "eight")) # note the double brackets
# NOTE: The list() object method takes at most 1 argemuent,
# so the items in the inner brackets are listed as one argument
print(names)

# add new items with the append() object method
names.append("twenty")
print(names)

# delete items from the list using the remove() object
names.remove("two")
print(names)

names.remove(names[0])
print(names)

# you can also append with the insert() object method
# inserts "nine" in element 1
names.insert(1, "nine")
print(names)