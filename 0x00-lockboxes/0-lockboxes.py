#!/usr/bin/python3
"""module"""


def canUnlockAll(boxes):
    """boxes is a list of lists"""
    for key in range(1, len(boxes) - 1):
        ctr = False
        for idx in range(len(boxes)):
            ctr = (key in boxes[idx] and key != idx)
            if ctr:
                break
        if ctr is False:
            return ctr
    return True
