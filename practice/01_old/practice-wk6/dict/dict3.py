# dict3.py
# Thur, 02.14.19 15:15hrs
from cs50 import get_string
from cs50 import get_int

resident = {"name": "Okolori Afor", "address": "1234 Sesame Street", "state": "MD", "zip": 20112}

# tries to retrieve an object not in the dictionary
# using the get() method
p = resident.get("county") # This will not throw a key error if the key does not exist

print("There is", p)