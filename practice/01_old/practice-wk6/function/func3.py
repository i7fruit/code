# func3.py
# Tue 02.05.19 20:06hrs
#
# defines a function
from cs50 import get_float

def add_two_floats():
    x = get_float("float x: ")
    y = get_float("float y: ")
    print(x + y)

add_two_floats()