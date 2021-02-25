#FUNÇOES REAIS
import cmath
def bissection(a, b, f, iterations=10):
    print("Iteration 0")
    print("a: %.03f" % a)
    print("b: %.03f" % b)

    for i in range(1, iterations + 1):
        m = (b + a) / 2.0
        if f(a) * f(m) <= 0.0:
            b = m
        else:
            a = m

        print("Iteration", i)
        print("a: %.03f" % a)
        print("b: %.03f" % b)

    return a, b


def false_position(a, b, f, iterations=10):
    print("Iteration 0")
    print("a: %.05f" % a)
    print("b: %.05f" % b)

    for i in range(1, iterations + 1):
        rr = (a * f(b) - b * f(a)) / (f(b) - f(a))
        if f(a) * f(rr) <= 0.0:
            b = rr
        else:
            a = rr

        print("Iteration", i)
        print("a: %.05f" % a)
        print("b: %.05f" % b)

    return a, b


def newton(guess, f, df, iterations=10):
    print("Iteration %d: %.05f" % (0, guess))
    print("f(guess): ", f(guess))
    for i in range(1, iterations + 1):
        guess -= f(guess) / df(guess)
        print("Iteration %d: %.05f" % (i, guess))
        print("f(guess): ", f(guess))

    return guess


def picard_peano(guess,rec,iterations=10):
    print("Iteration %d: %.05f" % (0, guess))

    for i in range(1, iterations + 1):
        guess = rec(guess)
        print("Iteration %d: %.05f" % (i, guess))

    return guess

import math

def f(x):
    return cmath.sin(x)+x**5-0.2*x+1

def df(x):
    return cmath.cos(x)+5*x**4-0.2
def rec1(x):
    return 1/2*cmath.sqrt(cmath.exp(x))

def rec2(x):
    return -1/2*cmath.sqrt(cmath.exp(x))

def rec3(x):
    return cmath.exp(x)/(4*x)

def rec4(x):
    return 2*cmath.log(2*x)

print("x1:\n", picard_peano(-0.5,rec1))
print("x2:\n", picard_peano(0.5,rec2))
print("x3:\n", picard_peano(4.5,rec3))
#x = picard_peano(0.9, rec4,1)
#print("x: %.05f" % x)
#print("Residue: %.05f" % (f(x)))

#print(bissection(-1,0,f,6))

#print(newton(3.8,f,df,2))