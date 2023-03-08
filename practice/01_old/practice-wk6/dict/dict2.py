# dict2.py
# Thur, 02.14.19 12:50hrs
from cs50 import get_string
from cs50 import get_int
from cs50 import get_float
from time import sleep

student = dict(name = get_string("name: "), age = get_int("age: "), height = get_float("height: "))

# meaningless code, just added for the look
print("Please wait", end="")
for i in range(3):
    for j in range(6):
        sleep(1)
        print(".", end="")
    for k in range(6):
        print("\b", end="")
    for l in range(6):
        print(" ", end="")
    for m in range(6):
        print("\b", end="")
print()

# tries to retrieve a value not included in the list
try:
    p = student["weight"]
    print(p)
except KeyError:
    print("No value weight")

# NOTE:
# if only p = student["weight"] had been used
# the interpreter would have thrown a Key Error