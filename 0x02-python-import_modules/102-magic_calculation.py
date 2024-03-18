#!/usr/bin/python3
from magic_calculation_102 import add, sub

def magic_calculation(a, b):
    """Function does exactly what Python bytecode does"""
    result = 0
    if a < b:
        c = add(a, b)
        for i in range(4, 6):
            c = add(c, i)
        return c
    else:
        return sub(a, b)

    print(magic_calculation(1, 3))  # Output: 8 (1 + 3 + 4 + 5)
    print(magic_calculation(6, 3))  # Output: 3 (6 - 3)
