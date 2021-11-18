#!/usr/bin/python3
"""Rotate a 2D matrix"""


def rotate_2d_matrix(matrix):
    """Given an n x n 2D matrix,
    rotate it 90 degrees clockwise.
    Args:
        matrix ([arr]): 2 dimensions matrix
    """
    ms = len(matrix)
    for x in range(0, int(ms / 2)):
        for y in range(x, ms-x-1):
            temp = matrix[x][y]
            matrix[x][y] = matrix[ms - 1 - y][x]
            matrix[ms - 1 - y][x] = matrix[ms - 1 - x][ms - 1 - y]
            matrix[ms - 1 - x][ms - 1 - y] = matrix[y][ms - 1 - x]
            matrix[y][ms - 1 - x] = temp
