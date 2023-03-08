# class2.py
# Sat, 02.16.19 22:17hrs
# Code from Socratica on YouTube: Python Classes and Objects
class User:
    """This is information concerning a hypothetical
    student. The class contains information about their
    full name and date of birth"""
    def __init__(self, full_name, birthday):
        self.name = full_name
        self.birthday = birthday #mmddyyyy

        # Extract first and last names
        # Splits the name by cutting whenever it
        # encounters a space (" ")
        # The pieces will be stored in an array
        name_pieces = full_name.split(" ")

        # Stores the first string in the array in self.first_name
        self.first_name = name_pieces[0]

        self.middle_name = name_pieces[1]

        # Stores the last string in the array
        self.last_name = name_pieces[-1]

# Creates and object and prints its values
student = User(input("Name: "), input("Date of birth: "))
print(student.first_name, student.middle_name,
    student.last_name, student.birthday, sep="\n")

# NOTE: Type help( <class_name> ) in the terminal to view
# the help text which gives a useful overview of the class