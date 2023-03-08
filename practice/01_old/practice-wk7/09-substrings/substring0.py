#!/usr/bin/env python3
# substring0.py
# Sun, March 31 2019 12:08hrs
# This program prints substrings of
# sentences to the screen depending on
# the number of characters the user has
# specified the substrings to comprise of
from nltk.tokenize import sent_tokenize

# Prompts the user for input and stores the input
# in a list
list0 = sent_tokenize(input("Enter text here: "))

# Prompts the user for substrings' length
n = int(input("Enter substrings' length: "))

# Iterates over sentences in the list
for sentence in list0:
    l = len(sentence)
    # Iterates over the characters that make up
    # each sentence
    for i in range(l):
        print(sentence[i:int(i+n)])
    print("\n")