#!/usr/bin/python3

def print_reversed_list_integer(my_list=[]):
    """Functionprints all integers of a list, in reverse order"""
    if my_list:
        print('\n'.join(['{:d}'.format(n) for n in my_list[::-1]]))
