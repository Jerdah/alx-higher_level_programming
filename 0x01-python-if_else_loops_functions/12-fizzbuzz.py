def fizzbuzz():
    """
    Print the numbers from 1 to 100, with the following:
    - For multiples of 3, print 'Fizz' instead of the number
    - For multiples of 5, print 'Buzz' instead of the number
    - For multiples of both 3 and 5, print 'FizzBuzz' instead of the number
    
    Each element is followed by a space, and the function does not import any modules.
    """
        print(' '.join([
        (i % 3 is 0) * 'Fizz' +
        (i % 5 is 0) * 'Buzz' +
        (str(i) if i % 3 and i % 5 else "")
        for i in range(1, 101)
    ]), end=" ")
