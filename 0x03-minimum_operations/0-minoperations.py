#!/usr/bin/python3
"""Minimum Operations """


def minOperations(n):
    """Given a number n, write a
    method that calculates the fewest
    number of operations needed to result in
    exactly n H characters in the file.
    """

    num = 0
    slt = 2

    if n < 1:
        return 0

    while n > 1:
        while n % slt == 0:
            num += slt
            n = n/slt
        slt += 1

    return num
