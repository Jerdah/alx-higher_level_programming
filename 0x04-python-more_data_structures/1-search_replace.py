#!/usr/bin/python3

def search_replace(my_list, search, replace):
    """Function replaces all occurences of an element by another in new list"""
    new_list = []
    for elem in my_list:
        if elem == search:
            new_list.append(replace)
        else:
            new_list.append(elem)
    return new_list
