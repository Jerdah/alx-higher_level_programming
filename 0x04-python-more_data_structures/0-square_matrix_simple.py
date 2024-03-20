#!/usr/bin/python3

def square_matrix_simple(matrix=[]):
    """Function computes square valure of all integers of a matrix"""
    if not matrix:
        return []

    new_matrix = []
    for row in matrix:
        new_row = []
        for elem in row:
            new_row.append(elem ** 2)
        new_matrix.append(new_row)

        return new_matrix
