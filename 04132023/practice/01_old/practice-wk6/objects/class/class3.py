# class2.py
# Sat, 02.16.19 22:17hrs
# Code from Socratica on YouTube: Python Classes and Objects
import datetime
class User:
    """This is information concerning a hypothetical
    student. The class contains information about their
    full name and date of birth"""
    def __init__(self, full_name, birthday):
        self.name = full_name
        self.birthday = birthday # yyyymmdd

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

    def age(self):
        """Returns the age of the user in years"""
        today = datetime.date(2019, 2, 17)
        yyyy = int(self.birthday[0:4])
        mm = int(self.birthday[4:6])
        dd = int(self.birthday[6:8])
        dob = datetime.date(yyyy, mm, dd) # Date of birth
        age_in_days = (today - dob).days
        age_in_years = age_in_days / 365
        return int(age_in_years)

# Creates and object and prints its values
student = User(input("Name (f m l): "), input("Date of birth (yyyymmdd): "))
print(student.first_name, student.middle_name, student.last_name)
print(student.age())