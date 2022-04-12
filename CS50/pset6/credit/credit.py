c#!/usr/bin/env python
# Pset 6 credit.py (more comfortable)

# This program checks if a credit
# card number entered by a user is
# a valid credit card number by
# using Luhn's Algorithm to verify
# the checksum, and it identifies if
# it's an American Express, Mastercard,
# Visa credit card, or if the card is
# invalid.
from cs50 import get_string


def main():
    # Prompts user for card number
    cc_number = get_string("Number: ")
    checksum(cc_number)


def checksum(num):
    # Checks if number has right number of digits
    mult_by_2, rest_of_digits = 0, 0

    if not num.isdigit():
        print("INVALID..")
        return False

    else:
        length = len(num)

        if length == 13 or length == 15 or length == 16:
            # Multiplies every other number by 2
            for digit in range(-2, (-length - 1), -2):
                x = int(num[digit]) * 2

                # Adds both digits of two-digit numbers to the total
                if x > 9:
                    mult_by_2 += x // 10
                    mult_by_2 += x % 10

                else:
                    mult_by_2 += x

            # Adds digits that were not multiplied by two
            for digit in range(-1, (-length - 1), -2):
                rest_of_digits += int(num[digit])

            # Computes total and modulo divides by ten
            total = mult_by_2 + rest_of_digits

            if total % 10 == 0:
                # Checks if Visacard
                if length == 13 or length == 16:
                    if num[0] == "4":
                        print("VISA")
                        return True

                # Checks if American Express
                if length == 15:
                    if num[0] == "3" and (num[1] == "4" or num[1] == "7"):
                        print("AMEX")
                        return True

                # Checks if Mastercard
                if length == 16:
                    if num[0] == "5" and (num[1] == "1" or num[1] == "2" or num[1] == "3" or
                                          num[1] == "4" or num[1] == "5"):
                        print("MASTERCARD")
                        return True

    print("INVALID")
    return False


if __name__ == "__main__":
    main()