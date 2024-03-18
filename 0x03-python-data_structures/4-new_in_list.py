#!/usr/bin/python3

def new_in_list(my_list, idx, element):
    """Function replaces an element in a list at a  specific position without modifying the original"""
    if my_list is not None:
        if -1 < idx < len(my_list):
            return my_list[:idx] + [element] + my_list[idx+1:]
        return my_list[:]
    return None
