# list0.py
# Mon, 02.04.19 14:54hrs
#
# Lists are collection data types that are
# ordered, changeable, and allows duplicate members
#
# illustrates how to declare lists
numbers = [] # an empty list

floats = [2.3, 4.45, 0.9] # an initialized list

# a list comprehenstion
# the for loop in the brackets
# is used to generate numbers
# for the numbs list

# The range is x starting from 0
# ...up to but not including 20, but
# in multiples of 3
numbs = [x for x in range(0, 20, 3)]

# prints the lists
print("numbers list is", numbers)
print("floats list is", floats)
print("numbs list is", numbs)