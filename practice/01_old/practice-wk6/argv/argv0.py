# argv0.py

# Tues, Jan 29 2019 20:06hrs
from sys import argv

if len(argv) == 2:
    print("Hello,", argv[1])
else:
    print("Hello, world")