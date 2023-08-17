import math
def score(x, y):
    position = math.sqrt((x**2 + y**2))
    if position > 10: 
        return 0
    if 5 < position <= 10:
        return 1
    if 1 < position <= 5:
        return 5
    return 10
