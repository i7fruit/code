# func2.py
# Jan 27 2019 23:45hrs
# Illustrates a function that takes a parameter
from cs50 import get_int

x = get_int("x: ")

def main():
    cough(x)

def cough(n):
    for i in range(n):
        print("Kuff kuff")

if __name__ == "__main__":
    main()