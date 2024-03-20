#!/usr/bin/python3

def multiply_by_2(a_dictionary):
    """Function returns a new dict with all values x2"""
    new_dict = {}
    for key, value in a_dictionary.items():
        new_dict[key] = value * 2
    return new_dict
