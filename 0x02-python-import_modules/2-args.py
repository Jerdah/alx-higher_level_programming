#!/usr/bin/python3
import sys
from sys import argv

if __name__ == "__main__":
    """Program prints the number of and the list of its arguments"""

num = len(sys.argv) - 1
if num == 0:
    print("0 arguments.")
elif num == 1:
    print("1 argument:")
else:
    print("{}arguments:".format(num))
for i in range(num):
    print("{}{}".format(i+1, sys.argv[i + 1]))
