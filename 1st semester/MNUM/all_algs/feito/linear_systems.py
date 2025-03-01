def print_sol(x):
    for i, c in enumerate(x):
        print("x%d: %.05f" % (i, c))


def gauss_jacobi(A, b, x=None, iterations=10):
    if x is None:
        x = [0 for i in range(len(A))]

    print("Iteration 0")
    print_sol(x)
    print()

    for i in range(1,iterations+1):
        aux = []
        for j in range(len(A[0])):
            x1 = (b[j] - (A[j][0] * x[0] + A[j][1] * x[1] + A[j][2] * x[2])) / A[j][j]
            aux.append(x1)
        x = [x[i] + aux[i] for i in range(len(x))]

        print("Iteration", i)
        print_sol(x)
        print()

    return x


def gauss_seidel(A, b, x=None, iterations=10):
    if x is None:
        x = [0 for i in A[0]]

    print("Iteration 0")
    print_sol(x)
    print()

    for i in range(1,iterations+1):
        for j in range(len(A[0])):
            x1 = (b[j] - (A[j][0] * x[0] + A[j][1] * x[1] + A[j][2] * x[2])) / A[j][j]
            x[j] += x1

        print("Iteration", i)
        print_sol(x)
        print()

    return x


def residue(sol, originalA, originalb):
    res = [0 for i in sol]
    for i in range(len(originalA)):
        for j in range(len(originalA)):
            res[i] += originalA[i][j] * sol[j]

    return [abs(res[i] - originalb[i]) for i in range(len(sol))]

A=[[10,6,1],[1,11,3],[2,7,13]]
b=[2,0,-8]

print(gauss_seidel(A,b))