# crack.py
# This program takes a user's hashed password,
# decrypts it, and prints the actual password
# in plaintext to the screen
from sys import argv
from sys import exit
import crypt
from time import sleep

if len(argv) != 2:
    print("Usage: python crack.py hash")
    exit(1)

# the hash key
hash_key = argv[1]

# extracts the salt from the hash
salt = argv[1][0:2]

# creats an empty list to store the key
key = []

A = 65
a = 97
size = 52

# checks the hash against one-word keys
x = A
for i in range(size):
    key = chr(x)
    p = crypt.crypt(key, salt)
    if hash_key == p:
        print(key)
        exit(0)
    x += 1
    if x == 91:
        x = a
    if x == 123:
        break

# two-word keys
x, y = A, A
for i in range(size):
    one = chr(x)

    for j in range(size):
        key = one + chr(y)
        p = crypt.crypt(key, salt)
        if hash_key == p:
            print(key)
            exit(0)
        y += 1
        if y == 91:
            y = a
        if y == 123:
            break

    x += 1
    y = A
    if x == 91:
        x = a
    if x == 123:
        break

# three-word keywords
x, y, z = A, A, A
# iterates over element 0
for i in range(size):
    one = chr(x)

    # iterates over element 1
    for j in range(size):
        two = one + chr(y)

        # iterates over element 2
        for k in range(size):
            key = two + chr(z)
            p = crypt.crypt(key, salt)
            if hash_key == p:
                print(key)
                exit(0)

            z += 1
            if z == 91:
                z = a
            if z == 123:
                break
        y += 1
        z = A
        if y == 91:
            y = a
        if y == 123:
            break

    x += 1
    y = A
    z = A
    if x == 91:
        x = a
    if x == 123:
        break

# four-word keywords
x, y, z, w = A, A, A, A
# iterates over element 0
for i in range(size):
    one = chr(x)

    # iterates over element 1
    for j in range(size):
        two = one + chr(y)

        # iterates over element 2
        for k in range(size):
            three = two + chr(z)

            # iterates over element 3
            for l in range(size):
                key = three + chr(w)

                p = crypt.crypt(key, salt)
                if hash_key == p:
                    print(key)
                    exit(0)
                w += 1
                if w == 91:
                    w = a
                if w == 123:
                    break

            z += 1
            w = A
            if z == 91:
                z = a
            if z == 123:
                break
        y += 1
        z = A
        w = A
        if y == 91:
            y = a
        if y == 123:
            break

    x += 1
    y = A
    z = A
    w = A
    if x == 91:
        x = a
    if x == 123:
        break

# # five-word keywords
# x, y, z, w, v = A, A, A, A, A
# # iterates over element 0
# for i in range(size):
#     one = chr(x)

#     # iterates over element 1
#     for j in range(size):
#         two = one + chr(y)

#         # iterates over element 2
#         for k in range(size):
#             three = two + chr(z)

#             # iterates over element 3
#             for l in range(size):
#                 four = three + chr(w)

#                 # iterates over element 4
#                 for m in range(size):
#                     key = four + chr(v)

#                     p = crypt.crypt(key, salt)
#                     print(key)
#                     if hash_key == p:
#                         print(key)
#                         exit(0)
#                     v += 1
#                     if v == 91:
#                         v = a
#                     if v == 123:
#                         break

#                 w += 1
#                 v = A
#                 if w == 91:
#                     w = a
#                 if w == 123:
#                     break

#             z += 1
#             w = A
#             v = A
#             if z == 91:
#                 z = a
#             if z == 123:
#                 break
#         y += 1
#         z = A
#         w = A
#         v = A
#         if y == 91:
#             y = a
#         if y == 123:
#             break

#     x += 1
#     y = A
#     z = A
#     w = A
#     v = A
#     if x == 91:
#         x = a
#     if x == 123:
#         break