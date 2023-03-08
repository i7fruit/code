# func1.py

# However, it's more conventional to have the
# definition of the function come after the
# function has been called.

# Because this will cause an error, it can be
# fixed by defining another function, we can
# call it Main for no particular reason, and call
# the function from there

def main():
    for i in range(5):
        sneeze()

def sneeze():
    print("Achoo!")

# Whereas in C, main is called by default,
# but the programmer has to call main by himself
# in python
if __name__ == "__main__":
    main()