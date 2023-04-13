# list3.py
# Tue, 02.05.19 14:19hrs

colors = list()

colors.append("blue")
print(colors)

# adds red at the 0th element
colors.insert(0, "red")
print(colors)

# adds a character to the second element
colors[1] = "blue" + "s"

print(colors)

# another list can be added as well
shapes = ["circle", "square", "octagon"]

# appends the shapes list to the colors list
colors.append(shapes)

# prints the shapes list within the colors list
print(colors)

colors.remove(shapes)

# concatinates both lists
print(colors + shapes)

# tacks one list to another to form one full list
colors[len(colors):] = shapes
print(colors)