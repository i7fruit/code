#!/usr/bin/env python3
# sentence1.py
# Sat, March 30 2019 23:14hrs
# This program takes a string of
# text and prints out the sentences
# that make up that string of text
from nltk.tokenize import sent_tokenize, word_tokenize

text_a = []

file = "file0.txt"

with open(file, "r") as f:
    text_a = sent_tokenize(f.read())

print(text_a)