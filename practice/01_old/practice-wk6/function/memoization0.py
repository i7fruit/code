# Code is taken from YouTube channel Socratica
#
# momoization0.py
#
# Fri, 02.15.19 18:13hrs
#
# This program prints the
# Fibonacci series using Memoization
# it is more efficient, and faster than
# just using the recursive method in
# the fibonacci1.py file

print("How many numbers would you like to print?", end="")
limit = int(input("\nlimit: "))

# First create an empty dictionary to store recent function calls
fibonacci = {}

def fib(n): # NOTE: n is the key in the dictionary ie n: value
    # Returns the value if it exists in the dictionary
    if n in fibonacci:
        return fibonacci[n]

    # Otherwise, compute the value, store it in
    # the dictionary, then return it

    # Computes the value
    if n == 0:
        value = 0
    if n == 1 or n == 2:
        value = 1
    elif n >= 3:
        value = fib(n - 1) + fib(n - 2)

    # Stores the value
    fibonacci[n] = value

    # Returns it
    return value

for i in range(limit):
    print(f"{i:3}", f"{fib(i):6}")