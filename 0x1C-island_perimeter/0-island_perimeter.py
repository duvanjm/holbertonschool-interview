#!/usr/bin/python3
"""calculate perimeter"""


def island_perimeter(grid):
    """calculate perimeter
    """
    peri, count = 0, 0
    len_grid = len(grid)
    for i in range(len_grid):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                count += 1
                if j != len(grid[i]) - 1 and grid[i][j + 1] == 1:
                    peri += 1
                if i != len(grid) - 1 and grid[i + 1][j] == 1:
                    peri += 1
    return count * 4 - 2 * peri
