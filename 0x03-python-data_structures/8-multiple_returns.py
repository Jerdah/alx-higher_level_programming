#!/usr/bin/python3

def multiple_returns(sentence):
    """Function returns a tuple with the length of a string and its first character"""
    if sentence is not None:
        if sentence:
            return len(sentence), sentence[0]
        return 0, None
    return None, None
