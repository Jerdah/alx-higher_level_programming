#!/usr/bin/python3

def weight_average(my_list=[]):
    """Function returns the weighted average of all integers tuple"""
    if not my_list:
        return 0

    numerator = 0
    denominator = 0

    for score, weight in my_list:
        numerator += score * weight
        denominator += weight

    if denominator == 0:
        return 0
    else:
        return numerator / denominator
