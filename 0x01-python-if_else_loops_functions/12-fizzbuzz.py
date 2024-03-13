#!/usr/bin/python3

def fizzbuzz():
    """
    Print the numbers from 1 to 100, with the following:
    - For multiples of 3, print 'Fizz' instead of the number
    - For multiples of 5, print 'Buzz' instead of the number
    - For multiples of both 3 and 5, print 'FizzBuzz' instead of the number
    
    Each element is followed by a space, and the function does not import any modules.
    """
    for i in range(1, 101):
        if i % 3 == 0 and i % 5 == 0:
            print("FizzBuzz", end=" ")
        elif i % 3 == 0:
            print("Fizz", end=" ")
        elif i % 5 == 0:
            print("Buzz", end=" ")
        else:
            print(i, end=" ")
