#!/usr/bin/env python3
# obj2.py
# Wed, 02.06.19 15:26hrs

# All classes have an __init__()
# which is called when the class
# is being initiated

# The __init__() function is used
# to assign values to object properties
from cs50 import get_string
from cs50 import get_int

class Person():
    def __init__(self, name, age):
        self.name = name
        self.age = age

# creates an object called student
student = Person(get_string("name: "), get_int("age: "))

print(student.name, "is", student.age, "years old.")