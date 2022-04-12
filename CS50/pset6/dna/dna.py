# Pset 6 dna.py
import sys
import csv


def main():
    # Checks for proper usage
    if len(sys.argv) != 3:
        print("Usage: Python dna.py data.csv sequence.txt")
        return

    # Memory location to read csv file into
    ls_database = []

    # Opens file for reading
    read_csv_file(ls_database)

    # Opens the txt file for reading
    text = read_txt_file()

    # List to store STRs
    if sys.argv[1] == "databases/large.csv":
        str_dict = {"name": "", "AGATC": 0, "TTTTTTCT": 0, "AATG": 0, "TCTAG": 0, "GATA": 0, "TATC": 0, "GAAA": 0, "TCTG": 0}
    elif sys.argv[1] == "databases/small.csv":
        str_dict = {"name": "", "AGATC": 0, "AATG": 0, "TATC": 0}

    # Checks STRs
    for dict_row in ls_database:
        for ky in dict_row:
            if ky != "name":
                str_dict[ky] = STR_check(text[0], ky)

    # Compares dictionaries
    match = False
    for dict_row in ls_database:
        if dict_cmp(dict_row, str_dict):
            match = True
            print(dict_row["name"])
            exit(1)

    if not match:
        print("No match")


def read_csv_file(array):
    """Opens a csv file for reading and appends
    its contents to a list"""
    csv_file = sys.argv[1]
    with open(csv_file, encoding="utf-8") as file:
        # Wraps file object with csv functionality
        reader = csv.DictReader(file)
        # Iterates over rows of data
        if sys.argv[1] == "databases/large.csv":
            for line in reader:
                line["AGATC"] = int(line["AGATC"])
                line["TTTTTTCT"] = int(line["TTTTTTCT"])
                line["AATG"] = int(line["AATG"])
                line["TCTAG"] = int(line["TCTAG"])
                line["GATA"] = int(line["GATA"])
                line["TATC"] = int(line["TATC"])
                line["GAAA"] = int(line["GAAA"])
                line["TCTG"] = int(line["TCTG"])
                array.append(line)

        elif sys.argv[1] == "databases/small.csv":
            for line in reader:
                line["AGATC"] = int(line["AGATC"])
                line["AATG"] = int(line["AATG"])
                line["TATC"] = int(line["TATC"])
                array.append(line)


def read_txt_file():
    """Reads a text file"""
    txt_file = sys.argv[2]
    with open(txt_file, encoding="utf-8") as filetx:
        sequence = filetx.read().splitlines()

    return sequence


def STR_check(string, s_t_r):
    # Length of string
    n = len(string)
    # Length of s_t_r
    str_len = len(s_t_r)

    maxi, count = 0, 0
    j = 0
    k = 0
    full = []
    name = ""

    while j < n:
        k = j + str_len
        if string[j:k] == s_t_r:
            count += 1
            j += str_len
            k += str_len

        else:
            full.append(count)
            count = 0
            j += 1

    maxi = max(full)

    return maxi


def dict_cmp(dict1, dict2):
    """Compares two dictionaries for equality"""
    check = True

    for ky in dict1:
        if ky != "name":
            if dict1[ky] != dict2[ky]:
                check = False

    return check


if __name__ == "__main__":
    main()