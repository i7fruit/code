def lines(a, b):
    """Return lines in both a and b"""

    # Lists to store data
    list_a, list_b, list_c = [], [], []

    # Splits the strings into lines
    list_a = a.splitlines()
    list_b = b.splitlines()

    # Iterates over the lists
    for line in list_a:
        if line in list_b and line not in list_c:
            list_c.append(line)

    return list_c


def sentences(a, b):
    """Return sentences in both a and b"""

    from nltk.tokenize import sent_tokenize

    # Lists to store data read from files
    list_a, list_b, list_c = [], [], []

    list_a = sent_tokenize(a)
    list_b = sent_tokenize(b)

    for sentence in list_a:
        if sentence in list_b and sentence not in list_c:
            list_c.append(sentence)

    return list_c


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # Lists to store data
    subs0, subs1, subs2 = [], [], []

    # Computes the length of both strings
    length_a, length_b = len(a), len(b)

    # Iterates over string a
    for i in range(length_a):
        s = a[i:int(i + n)]
        subs0.append(s)
        t = len(s)
        if t < n:
            subs0.pop()

    # Iterates over b
    for i in range(length_b):
        s = b[i:int(i + n)]
        subs1.append(s)
        t = len(s)
        if t < n:
            subs1.pop()

    # Creates a list of similar substrings
    for i in subs0:
        if i in subs1 and i not in subs2:
            subs2.append(i)

    return subs2
