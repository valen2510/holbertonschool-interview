#!/usr/bin/python3
"""Log parsing"""
import signal
import sys


if __name__ == '__main__':
    sum_size = 0
    status_code = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
    }

    try:
        i = 0
        for line in sys.stdin:
            args = line.split()
            if len(args) > 6:
                status = args[-2]
                file_size = args[-1]
                sum_size += int(file_size)
                if status in status_code:
                    i += 1
                    status_code[status] += 1
                    if i % 10 == 0:
                        print('File size: {}'.format(sum_size))
                        for key, value in sorted(status_code.items()):
                            if value != 0:
                                print('{}: {}'.format(key, value))

    except KeyboardInterrupt:
        print('File size: {}'.format(sum_size))
