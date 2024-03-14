#!/usr/bin/python3
import sys
from sys import argv

if __name__ == "__main__":
    """Program prints the result of the addition of all arguments"""

print(sum(map(int, argv[1:])))
