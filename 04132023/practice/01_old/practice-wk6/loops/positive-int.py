# gets a positive integer from a user
from cs50 import get_int

def main():
    x = get_positive_int("Enter a positive int: ")
    print("You typed", x)

def get_positive_int(i):
    while True:
        n = get_int(i)
        if n > 0:
            break
    return n

if __name__ == "__main__":
    main()