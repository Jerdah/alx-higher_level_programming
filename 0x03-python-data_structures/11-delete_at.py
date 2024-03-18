#!/usr/bin/python3

def delete_at(my_list=[], idx=0):
    """Function deletes the item at a specific position in a list"""
    if my_list is not None and -1 < idx < len(my_list):
        del my_list[idx]
    return my_list
