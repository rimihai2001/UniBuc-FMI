def calc_det(p1, p2, q1, q2, r1, r2):
    return q1*r2+p1*q2+p2*r1-q1*p2-r1*q2-r2*p1


def elim_dup(lst):
    return [t for t in (set(tuple(i) for i in lst))]    


def graham_scan_i(pct):
    pct.sort(key=lambda punct: punct[0])
    inf = [pct[0], pct[1]]
    for i in range(2, len(pct)):
        inf.append(pct[i])
        while len(inf) > 2 and calc_det(inf[-3][0], inf[-3][1], inf[-2][0], inf[-2][1], inf[-1][0], inf[-1][1]) <= 0:
            inf.pop(-2)
    return inf


def graham_scan_s(pct):
    pct.sort(key=lambda punct: punct[0])
    sup = [pct[0], pct[1]]
    for i in range(2, len(pct)):
        sup.append(pct[i])
        while len(sup) > 2 and calc_det(sup[-3][0], sup[-3][1], sup[-2][0], sup[-2][1], sup[-1][0], sup[-1][1]) >= 0:
            sup.pop(-2)
    return sup


def graham_scan(pct):
    
    ls = graham_scan_s(pct)
    li = graham_scan_i(pct)

    return elim_dup(li+ls)


nr_puncte = int(input())
puncte = []

for i in range(nr_puncte):
    inp = input().split()
    puncte.append((int(inp[0]), int(inp[1]), i))

puncte_finale = graham_scan(puncte)

puncte_finale.sort(key=lambda punct: (punct[2]))

print(len(puncte_finale))
for p_fin in puncte_finale:
    print(p_fin[0], p_fin[1])
