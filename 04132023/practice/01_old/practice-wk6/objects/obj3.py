# obj3.py
# Sat, 02.16.19 14:31hrs

# Defines a class, User, that does nothing
class User:
    pass

# Creates an instance/object of the class User
p = User()

# To attach data, type the name of the object,
# ...a dot, the name of the variable, and then
# ... attach the value.

# first_name, age, and height are the fields of the object
p.first_name = input("First Name: ")
p.age = int(input("Age: "))
p.height = float(input("Height: "))

# Creates a new instance of the User class
q = User()
q.first_name = input("First Name: ")
q.age = int(input("Age: "))
q.weight = float(input("Weight: "))

# Prints contents of the p object
print(p.first_name, p.age, p.height)

# Prints contents of the q object
print(q.first_name, q.age, q.weight)