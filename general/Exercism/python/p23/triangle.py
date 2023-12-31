def equilateral(sides):
    if isTriangle(sides):
        a, b, c = sides
        return (a == b) and (a == c)
    return False

def isosceles(sides):
    if isTriangle(sides):
        a, b, c = sides
        return (a == b) or (b == c) or (a == c)
    return False

def scalene(sides):
    if isTriangle(sides):
        a, b, c = sides
        return (a != b) and (b != c) and (c != a)
    return False

def isTriangle(sides):
    a, b, c = sides
    sidesLength = a > 0 and b > 0 and c > 0
    twoSides = (a + b >= c) and (a + c >= b) and (b + c >= a)
    return sidesLength and twoSides