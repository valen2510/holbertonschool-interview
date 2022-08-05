#!/usr/bin/python3
'''
Function that returns a list of lists of integers representing
the Pascal’s triangle of n.
'''


def pascal_triangle(n):
    '''
    - Returns:
        empty list if n <= 0
    - You can assume n will be always an integer.
    '''
    pascal_list = []
    if n <= 0:
        return pascal_list
    for i in range(n):
        row = [1]
        if pascal_list:
            last_row = pascal_list[-1]
            row.extend([sum(pair) for pair in zip(last_row, last_row[1:])])
            row.append(1)
        pascal_list.append(row)
    return (pascal_list)
