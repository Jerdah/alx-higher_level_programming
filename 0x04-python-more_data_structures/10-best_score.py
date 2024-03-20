#!/usr/bin/python3

def best_score(a_dictionary):
    """
    Function returns a key with the biggest integer value."""
    if not a_dictionary:
        return None

    best_key = None
    best_value = float('-inf')  # Negative infinity

    for key, value in a_dictionary.items():
        if value > best_value:
            best_value = value
            best_key = key

    return best_key
