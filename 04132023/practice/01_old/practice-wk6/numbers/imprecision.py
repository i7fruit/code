# Because computers only have a finite amount
# of memory, python still doesn't solve the
# problem of floating point imprecision

from cs50 import get_float

x = get_float("x: ")
y = get_float("y: ")

print(f"x / y = {(x / y):.60}")