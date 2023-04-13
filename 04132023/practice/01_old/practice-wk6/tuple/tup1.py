#!/usr/bin/env python3
# tup1.py
# Fri, 02.08.19 23:46hrs

# declares a tuple
cars = ("toyota", "volkswagen", "ford")
print(cars)

# a tuple can also be declared using the tuple() constructor
airlines = tuple(("emirates", "delta", "qatar airways")) # use double round brackets for multiple members
print(airlines)

# members of a tuple can't be changed or removed
airlines.remove("delta")
print(airlines)