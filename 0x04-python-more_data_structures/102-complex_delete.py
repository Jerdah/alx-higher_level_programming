#!/usr/bin/python3
def complex_delete(a_dictionary, value):
    new_dict = dict(a_dictionary)
    keys_to_delete = [key for key, val in new_dict.items() if val == value]
    for key in keys_to_delete:
        del new_dict[key]
        return new_dict
