# Code is taken from YouTube channel Socratica
#
# momoization1.py
#
# Fri, 02.15.19 23:40hrs

# LRU_CACHE provides a way to add memoization to a function
from functools import lru_cache

# Add @lru_cache just above the function definition
@lru_cache(maxsize = 1000) # default maxsize is 128 if no argument is included
def fibonacci(n):
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1
    elif n > 2:
        return fibonacci(n - 1) + fibonacci(n - 2)

# Prompts the user to enter number of digits to display
r = int(input("Enter range: "))

print("Key  Value")
for i in range(r):
    print(f"{i:2}" f"{fibonacci(i):6}")