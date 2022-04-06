from cs50 import get_string
from sys import argv

# Alerts the user of proper usage
if len(argv) != 2:
    print(f"Usage: python {argv[0]} dictionary")
    exit(1)


def main():
    # Creates an empty set to store the list of banned words
    words = set()

    # Calls the open function that returns a file object, f
    with open(argv[1], "r") as f:
        # Iterates through words in the dictionary and
        # adds them to the created list, stripping of
        # any trailing newline characters using the rstrip method
        for line in f:
            words.add(line.rstrip("\n"))

        # Prompts the user to enter a string of text,
        # separates each word in the text and stores
        # them in a list
        to_check = prompt()

        # Iterates through the user's text, replacing
        # every letter of any banned word found,
        # with an asterisk
        for word in to_check:
            if word.lower() in words:
                for i in word:
                    print("*", end="")
                print(" ", end="")
            else:
                print(word, end=" ")
        print()


def prompt():
    text = input("What message would you like to censor?\n")
    return text.split()


if __name__ == "__main__":
    main()
