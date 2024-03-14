#!/usr/bin/python3.8

import hidden_4

def print_names():
    names = ["my_secret_santa", "print_hidden", "print_school"]
    for name in names:
        print(name)

if __name__ == "__main__":
<<<<<<< HEAD
    print_names()
=======

    for name in dir(hidden_4):
        if not name.startswith('__'):
            print(name)
>>>>>>> refs/remotes/origin/main
