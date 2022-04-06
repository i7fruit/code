#!/usr/bin/env python
# Pset 6 readability.py
from cs50 import get_string


def main():
    # Prompts the user for some text
    text = input("Text: ")

    # Computes number of letters
    letters = letter_ctr(text)

    # Computes number of words
    words = word_ctr(text)

    # Computes number of sentences
    sentences = sentence_ctr(text)

    # Computes coleman-liau index
    grade_level = coleman_liau_index(letters, words, sentences)

    if grade_level < 1:
        print("Before Grade 1")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print("Grade " + str(grade_level))


# letter_ctr()
def letter_ctr(txt):
    """Computes the number of letters in the text"""
    ctr = 0

    for i in txt:
        if i.isalpha():
            ctr += 1

    return ctr


# word_ctr()
def word_ctr(txt):
    """Extracts words from a string of text using
    the split() function"""
    words = txt.split()

    return len(words)


# sentence_ctr()
def sentence_ctr(txt):
    """Extracts the number of sentences in a
    string of text"""
    ctr = 0

    for word in txt:
        if "." in word or "!" in word or "?" in word:
            ctr += 1

    return ctr


# Computes Coleman-Liau index
def coleman_liau_index(ltrs, wrds, sen):
    """Computes the grade reading level"""
    L = (ltrs / wrds) * 100
    S = (sen / wrds) * 100

    index = .0588 * L - .296 * S - 15.8

    return int(round(index))


if __name__ == "__main__":
    main()