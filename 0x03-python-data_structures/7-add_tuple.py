#!/usr/bin/python3

def add_tuple(tuple_a=(), tuple_b=()):
     """Function adds 2 tuples"""
     return tuple(sum(t) for t in zip(
        (tuple_a + (0,) * ((not tuple_a) + 1))[:2],
        (tuple_b + (0,) * ((not tuple_b) + 1))[:2],
    ))
