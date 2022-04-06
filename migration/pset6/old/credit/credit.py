# credit.py
# This program checks if a credit
# card number entered by a user is
# a valid credit card number by
# using Luhn's Algorithm to verify
# the checksum, and it identifies if
# it's an American Express, Mastercard,
# Visa credit card, or if the card is
# invalid.
from cs50 import get_int

# prompts the user for a card number
cc_num = get_int("Card Number: ")

# checks if the card number is valid or not
cc_cpy = cc_num
i = 0
AmX = False
Vis = False
Mas = False

# calculates number of digits entered
while cc_cpy:
    cc_cpy //= 10
    i += 1

if i == 14 or (i < 13 or i > 16):
    print("INVALID")

elif i == 13:
    p = i - 1
    if cc_num // 10**p != 4:
        print("INVALID")
    elif cc_num // 10**p == 4:
        Vis = True

elif i == 16:
    p = i - 1
    q = i - 2
    if (cc_num // 10**p != 4) and cc_num // 10**p != 5:
        print("INVALID")
    elif (cc_num // 10**p == 4):
        Vis = True
    elif cc_num // 10**p == 5:
        if (cc_num // 10**q < 51) or (cc_num // 10**q > 55):
            print("INVALID")
        else:
            Mas = True

elif i == 15:
    p = i - 2
    if (cc_num // 10**p != 34) and (cc_num // 10**p != 37):
        print("INVALID")
    else:
        AmX = True

# checks validity using Luhn's Algorithm
i, odd, even = 0, 0, 0
two, ten, nine = 2, 10, 9
cc_cpy = cc_num
while cc_cpy:
    if i % two == 0:
        odd += cc_cpy % ten
    elif i % two != 0:
        x = (cc_cpy % ten) * two
        if x > nine:
            even += (x // ten) + (x % ten)
        else:
            even += x
    # updates number
    cc_cpy //= ten
    # increments
    i += 1

total = odd + even

if total % ten == 0:
    if AmX:
        print("AMEX")
    elif Mas:
        print("MASTERCARD")
    elif Vis:
        print("VISA")
else:
    print("INVALID")