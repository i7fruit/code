# dict4.py
# CODE FROM CS50
#
# Tue, 02.20.19 16:36hrs

class Dictionary:
    def __init__(self):
        self.words = set()

    def check(self, word):
        return word.lower() in self.words

    def load(self, dictionary):
        with open(dictionary, "r") as f:
            for line in f:
                self.words.add(line.rstrip("\n"))
        return True

    def size(self):
        return len(self.words)

    def unload(self):
        return True