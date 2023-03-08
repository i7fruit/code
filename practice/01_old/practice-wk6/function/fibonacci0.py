# fibonacci.py
# Thur, 02.14.19 20:11
# prints out the fibonacci series

from cs50 import get_int
#from time import sleep

# prompts the user for a number
while True:
    n = get_int("n: ")
    if n > 0:
        break

def main():
    fibonacci(n)

def fibonacci(x):
    print(0)
    print(1)
    a, b, c, i = 0, 1, 0, 0
    while i < n:
        c = a + b
        print(" ", c)
#        sleep(1)
        a = b
        b = c
        i += 1

if __name__ == "__main__":
    main()