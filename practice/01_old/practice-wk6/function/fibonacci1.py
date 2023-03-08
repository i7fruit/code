# fibonacci1.py
# Fri, 02.15.19 13:56hrs

# This program uses recursion to print
# the fibonacci series, but it is slow.
while True:
    limit = int(input("limit: "))
    if limit > -1 and limit < 36:
        break

def fib(n):
    # uses recursion to print the series
    if n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)

for i in range(limit):
    print(f"{fib(i):7}")

# NOTE:
# {z:3} means print z to three significant places
# {z:.2} means print z to two decimal places