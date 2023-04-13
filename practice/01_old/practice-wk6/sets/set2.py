# set2.py
# Wed, 02.20.19 23:10hrs

# This program prompts the user for text input,
# then searches through a set of banned words
# to see if there are any matches with what the
# user has typed in, replacing any banned words
# found in the user's input with an asterisk for
# every letter in the word.

banned = {"foo", "bar", "baz", "shoot", "heck"}

x = input("Enter text: ")

check = x.split()
read = []

for i in check:
    if i.lower() in banned:
        for c in range(len(i)):
            print("*", end="")
    else:
        print(i, end="")

    print(" ", end="")
print()