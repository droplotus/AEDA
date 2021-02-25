def sequentialSearch(x0, func, h=1):
    a = x0
    b = a + h
    while func(a) > func(b):
        a += h
        b += h
    return [a, b]


def tercos(interval, f, prec=0.0001):
    a = interval[0]
    b = interval[1]
    while abs(b - a) > prec:
        c = a + (b - a) / 3.0
        d = b - (b - a) / 3.0
        if f(c) < f(d):
            b = d
        else:
            a = c
    return [a, b]


from math import sqrt


def aureaSec(rangeVal, f, prec=0.1):
    # B = proporção
    B = (math.sqrt(5) - 1) / 2
    A = B**2

    x1 = rangeVal[0]
    x2 = rangeVal[1]
    x3 = A * (x2 - x1) + x1
    x4 = B * (x2 - x1) + x1

    print("x1: %0.5f : f(x1): %0.5f" % (x1, f(x1)))
    print("x2: %0.5f : f(x2): %0.5f" % (x2, f(x2)))
    print("x3: %0.5f : f(x3): %0.5f" % (x3, f(x3)))
    print("x4: %0.5f : f(x4): %0.5f" % (x4, f(x4)))

    for i in range(2):
        if f(x3) < f(x4):
            x2 = x4
            x4 = x3
            x3 = B * (x4 - x1) + x1
        else:
            x1 = x3
            x3 = x4
            x4 = B * (x2 - x3) + x3

        print("\nx1: %0.5f : f(x1): %0.5f" % (x1, f(x1)))
        print("x2: %0.5f : f(x2): %0.5f" % (x2, f(x2)))
        print("x3: %0.5f : f(x3): %0.5f" % (x3, f(x3)))
        print("x4: %0.5f : f(x4): %0.5f" % (x4, f(x4)))


def quadAdjust(points, f):
    x1 = points[0]
    x3 = points[1]
    x2 = (x1 + x3) / 2.0

    h = x2 - x1

    return x2 - (h * (f(x1) - f(x3))) / (2 * (f(x1) - 2 * f(x2) + f(x3)))

import math
def f(x):
    return -5*math.cos(x)+math.sin(x)+10

#print(sequentialSearch(-5,f,1))
#print(tercos([1,2],f))
aureaSec([2,4],f,0.0001)
#print(quadAdjust([2.894368,2.8944498],f))
#print(quadAdjust([1.723559,1.723625],f))
