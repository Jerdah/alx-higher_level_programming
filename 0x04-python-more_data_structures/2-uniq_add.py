#!/usr/bin/python3

def uniq_add(my_list=[]):
    """Function adds all uniques integers in a list"""
    result = 0
    unique_numbers = set()
    for num in my_list:
        if num not in unique_numbers:
            unique_numbers.add(num)
            result += num
    return result
