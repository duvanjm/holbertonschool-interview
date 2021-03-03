#!/usr/bin/python3
"""module"""


def validUTF8(data):
    """ 0. UTF-8 Validation"""
    n_bytes = 0

    for i in data:
        byte = format(i, '#010b')[-8:]

        if n_bytes == 0:
            if byte[0] == '1':
                n_bytes = len(byte.split('0')[0])

            if n_bytes > 4 or n_bytes == 1:
                return False
            elif n_bytes == 0:
                continue
        else:
            if not (byte[0] == '1' and byte[1] == '0'):
                return False

        n_bytes = n_bytes - 1

    if n_bytes != 0:
        return False
    return True
