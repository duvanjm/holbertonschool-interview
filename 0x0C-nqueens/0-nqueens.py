#!/usr/bin/python3
"""module"""

import sys


def solve(board, column, n):
    """solve the n queens problem"""
    if column == n:
        printboard(board)
        return True


def printboard(board):
    """print board"""
    solution = []
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 1:
                solution.append([i, j])
    print(solution)


def main():
    """main function"""
    n = int(sys.argv[1])
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    if type(n) is not int:
        print('N must be a number')
        exit(1)
    if n < 4:
        print('N must be at least 4')
        exit(1)
    board = [[0 for i in range(n)] for j in range(n)]
    solve(board, 0, n)


if __name__ == '__main__':
    main()
