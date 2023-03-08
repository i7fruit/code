from cs50 import get_float

x = get_float("x: ")
y = get_float("y: ")

print("x + y = ", x + y)
print("x - y = ", x - y)
print("x mod y = ", x % y)
print("x ** y = ", x ** y)
print("x / y = ", x / y)

# Prints a float to specific decimal places
print(f"x / y = {(x/y):.3f} to 3 decimal places")

# {z:2f} means,
# print the value to the left
# of the colon, to 2dp