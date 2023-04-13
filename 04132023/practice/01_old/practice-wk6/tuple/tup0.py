# tup0.py
#
# a tuple is a collection data type that is
# ordered, unchanegable (immutable),
# and allows duplicate members
#
# below is a list of three tuples
presidents = [
    ("Barack Obama", 2008),
    ("Thomas Jefferson", 1797),
    ("James Madison", 1809)
]

# iterates over the list of tuples
for i, j in presidents:
    print("{0} took office in {1}.".format(i, j))
    # Can also be as below:
    #print(f"{i} took office in {j}")
    #print(i, "took office in", j)