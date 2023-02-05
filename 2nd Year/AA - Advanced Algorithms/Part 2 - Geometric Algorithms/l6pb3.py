def calc_det(a, b, c, d, e, f, g, h, i):
    return (a * e * i - a * h * f
            - d * b * i + d * h * c
            + g * b * f - g * e * c)


linie1 = input().split()
a1 = int(linie1[0])
a2 = int(linie1[1])
linie2 = input().split()
b1 = int(linie2[0])
b2 = int(linie2[1])
linie3 = input().split()
c1 = int(linie3[0])
c2 = int(linie3[1])

n = int(input())
puncte_test = []

for i in range(n):
    linie = input().split()
    punct = (int(linie[0]), int(linie[1]))
    puncte_test.append(punct)

for punct in puncte_test:
    d1, d2 = int(punct[0]), int(punct[1])
    det = -calc_det(b1, b2, b1 * b1 + b2 * b2, c1, c2,
                    c1 * c1 + c2 * c2, d1, d2, d1 * d1 + d2 * d2)
    det += calc_det(a1, a2, a1 * a1 + a2 * a2, c1, c2,
                    c1 * c1 + c2 * c2, d1, d2, d1 * d1 + d2 * d2)
    det -= calc_det(a1, a2, a1 * a1 + a2 * a2, b1, b2,
                    b1 * b1 + b2 * b2,  d1, d2, d1 * d1 + d2 * d2)
    det += calc_det(a1, a2, a1 * a1 + a2 * a2, b1, b2,
                    b1 * b1 + b2 * b2,  c1, c2, c1 * c1 + c2 * c2)
    if det > 0:
        print('INSIDE')
    elif det < 0:
        print('OUTSIDE')
    else:
        print('BOUNDARY')
