# int1.py
# Wed, 02.13.19 18:31hrs

import sys

# ( sys.maxsize ) gives max value of an int
a = sys.maxsize
print("Maximum value of \'int\':", a)

# ( -sys.maxsize - 1 ) gives the min value of an int
b = -sys.maxsize - 1
print("Minimum value of \'int\'", b)

# ( j ) is used to display complex numbers
n = 3 + 5.2j
print(n)

# displayes real property of n
print(n.real)

# prints imaginary property of n
print(n.imag)

# displays the data type of n: complex
print(type(n))