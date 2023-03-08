# Python handles integer overflow
# a lot better than C
from time import sleep

x = 2

while True:
    print(x)
    x = x ** 2
    sleep(1)