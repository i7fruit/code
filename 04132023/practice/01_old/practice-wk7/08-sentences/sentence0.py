#!/usr/bin/env python3
# sentence0.py
# Sat, March 30 2019 23:05hrs
# This program takes a string of
# text and prints out the sentences
# that make up that string of text
from nltk.tokenize import sent_tokenize

text = list()
text.append(sent_tokenize("What's happening here? Do you know him?"))

for line in text:
    print(line)