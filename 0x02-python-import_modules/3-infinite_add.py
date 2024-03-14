#!/usr/bin/python3
import sys

if __name__ == "__main__":
    """Program prints the result of the addition of all arguments"""

    sum = 0

    for arg in sys.argv[1:]:
        sum += int(arg)

        print(sum)

