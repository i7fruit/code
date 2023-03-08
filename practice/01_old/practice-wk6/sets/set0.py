# set0.py
# Fri, 02.09.19 00:06hrs

# sets are collection data sets in python
# that are unordered and unindexed. They
# also do not allow for duplicate members

# sets are created using curly braces
food = {"rice", "beans", "plantains"}
food.add("potatoes")
print(food)

# removes an object from the set
food.remove("rice") # throws an error if the object doesn't exist in the set
print(food)