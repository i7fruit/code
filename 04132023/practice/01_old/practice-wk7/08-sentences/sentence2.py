#!/usr/bin/env python3
# sentence2.py
# Sun, March 31 2019 12:10hrs
# This program compares the sentences
# in two files and returns a list of
# sentences that both files have in common,
# without repetitions
from nltk.tokenize import sent_tokenize

# Gets file names from the user
file_1, file_2 = input("File Name 1: "), input("File Name 2: ")

# Empty lists to store text read from files
list_1 = []
list_2 = []
list_3 = []

try:
    with open(file_1, "r") as f:
        sent_a = f.read()
except FileNotFoundError:
    print(f"{file_1} not found")

try:
    with open(file_2, "r") as f:
        sent_b = f.read()
except FileNotFoundError:
    print(f"{file_2} not found")

# Stores a list of sentences in both files
list_1 = sent_tokenize(sent_a)
list_2 = sent_tokenize(sent_b)

# Compares both lists and extracts sentences common to both lists
for line in list_1:
    if line in list_2 and line not in list_3:
        list_3.append(line)

# Prints sentences in common
for line in list_3:
    print(line)