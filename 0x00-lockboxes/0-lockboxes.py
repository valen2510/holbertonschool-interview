#!/usr/bin/python3
"""Method that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """ unlock boxes function"""

    if len(boxes) == 0:
        return False

    unlock_boxes = [0]
    for key in unlock_boxes:
        for element in boxes[key]:
            if element not in unlock_boxes and element < len(boxes):
                unlock_boxes.append(element)

    if len(unlock_boxes) == len(boxes):
        return True
    return False
