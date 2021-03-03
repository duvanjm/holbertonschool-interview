#!/usr/bin/python3
"""module"""


def validUTF8(data):
    """ 0. UTF-8 Validation"""
    try:
        isvalid = True
        for i in data:
            i = i & 0xff
            if i >= 192 and i < 224:
                isvalid = False
            if i >= 224 and i < 240:
                isvalid = False
            if i >= 240 and i < 248:
                isvalid = False
            if i >= 128 and i < 192:
                isvalid = False
            if i > 255:
                isvalid = False
        return(isvalid)
    except Exception as e:
        return(False)
