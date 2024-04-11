#!/usr/bin/python3

def add_integer(a, b=98):
    """
    Add two integers together.
    
    Args:
        a (int or float): The first integer to add.
        b (int or float, optional): The second integer to add. Defaults to 98.
    
    Raises:
        TypeError: If a or b is not an integer or float.
    
    Returns:
        int: The sum of a and b.
    """
    if not isinstance(a, (int, float)):
        raise TypeError("a must be an integer")
    if not isinstance(b, (int, float)):
        raise TypeError("b must be an integer")
    return (int(a) + int(b))
