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
linie4 = input().split()
d1 = int(linie4[0])
d2 = int(linie4[1])


det = -calc_det(b1, b2, b1 * b1 + b2 * b2, c1, c2, c1 *
                c1 + c2 * c2, d1, d2, d1 * d1 + d2 * d2)
det += calc_det(a1, a2, a1 * a1 + a2 * a2, c1, c2, c1 *
                c1 + c2 * c2, d1, d2, d1 * d1 + d2 * d2)
det -= calc_det(a1, a2, a1 * a1 + a2 * a2, b1, b2, b1 *
                b1 + b2 * b2,  d1, d2, d1 * d1 + d2 * d2)
det += calc_det(a1, a2, a1 * a1 + a2 * a2, b1, b2, b1 *
                b1 + b2 * b2,  c1, c2, c1 * c1 + c2 * c2)
if det > 0:
    print('AC: ILLEGAL')
else:
    print('AC: LEGAL')

det = -calc_det(c1, c2, c1 * c1 + c2 * c2, d1, d2, d1 *
                d1 + d2 * d2, a1, a2, a1 * a1 + a2 * a2,)
det += calc_det(b1, b2, b1 * b1 + b2 * b2, c1, c2, c1 *
                c1 + c2 * c2, d1, d2, d1 * d1 + d2 * d2)
det += calc_det(b1, b2, b1 * b1 + b2 * b2,  d1, d2, d1 *
                d1 + d2 * d2, a1, a2, a1 * a1 + a2 * a2)
det -= calc_det(b1, b2, b1 * b1 + b2 * b2,  c1, c2, c1 *
                c1 + c2 * c2, a1, a2, a1 * a1 + a2 * a2)
if det > 0:
    print('BD: ILLEGAL')
else:
    print('BD: LEGAL')
