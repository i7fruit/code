# class0.py
# Sat, 02.16.19 14:57hrs
# Code from Socratica on YouTube: Python Classes and Objects
class User:
    def __init__(self, full_name, birthday):
        self.name = full_name
        self.birthday = birthday #mmddyyyy

student = User(input("Name: "), input("Date of birth: "))
print(student.name, student.birthday)