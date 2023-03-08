# for-loop1.py
# Mon, 02.04.19 14:41hrs
# iterates through a set of
# numbers printing out the even numbers

# starting from 0, iterate in twos,
# up to but not including 100
for i in range(0, 100, 2):
    print(i, end=" ")
    if not i == 0 and i % 10 == 0:
        print()

print()