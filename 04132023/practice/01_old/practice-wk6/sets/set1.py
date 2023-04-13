# set1.py
# Wed, 02.13.19 21:24hrs

# illustrates unions and intersections in sets
a = set([1, 2, "may", 3])
b = {"april", "may", "june", 2}

# displays values that intersect with both sets
c = a.intersection(b)
print(c)

# combines both sets in a union
d = a.union(b)
print(d)

# unlike the remove() method,
# the discard() method will not
# throw and error if the object
# does not exist in the set
e = a.discard("mayan")
print(e)
print(a)