import cmath

# link formula: https://www.linkedin.com/pulse/short-formula-check-given-point-lies-inside-outside-polygon-ziemecki/


def PonEdge(P, P0, P1):
    p0 = P0[0] - P[0], P0[1] - P[1]
    p1 = P1[0] - P[0], P1[1] - P[1]

    det = (p0[0] * p1[1] - p1[0] * p0[1])
    prod = (p0[0] * p1[0] + p0[1] * p1[1])

    return (det == 0 and prod < 0) or (p0[0] == 0 and p0[1] == 0) or (p1[0] == 0 and p1[1] == 0)


def isInPoligon(P, Muchii):
    sum = complex(0, 0)
    for i in range(1, len(Muchii) + 1):
        v0, v1 = Muchii[i - 1], Muchii[i % len(Muchii)]
        if PonEdge(P, v0, v1):
            return -1
        sum += cmath.log((complex(*v1) - complex(*P)) /
                          (complex(*v0) - complex(*P)))
    return abs(sum) > 1



poligon_pct = []
puncte_de_verificat = []


n = int(input())
for i in range(n):
    linie = input().split()
    punct = [float(linie[0]), float(linie[1])]
    poligon_pct.append(punct)

m = int(input())
puncte_de_verificat = []
for i in range(m):
    linie = input().split()
    punct = [float(linie[0]), float(linie[1])]
    puncte_de_verificat.append(punct)

for punct in puncte_de_verificat:
    if isInPoligon(punct, poligon_pct):
        if isInPoligon(punct, poligon_pct) == -1:
            print('BOUNDARY')
        else:
            print('INSIDE')
    else:
        print('OUTSIDE')
