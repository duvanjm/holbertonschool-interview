#!/usr/bin/python3
"""module"""


def validUTF8(data):
    """ 0. UTF-8 Validation"""
    for n in data:
        if count == 0:
            if (n >> 3) == 0b11110:
                count = 3
            elif (n >> 4) == 0b1110:
                count = 2
            elif (n >> 5) == 0b110:
                count = 1
            elif (n >> 7):
                return False
        else:
            if (n >> 6) != 0b10:
                return False
            count -= 1
    return count == 0
