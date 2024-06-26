#!/usr/bin/python3
def safe_print_list(my_list=[], x=0):
    """Function prints x elements of a list
    """
    try:
        for index in range(x):
            print(my_list[index], end="")
        return x
    except IndexError:
        return index
    finally:
        print()
