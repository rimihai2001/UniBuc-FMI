def calc_det(p1, p2, q1, q2, r1, r2):
    return q1*r2+p1*q2+p2*r1-q1*p2-r1*q2-r2*p1


nr_puncte = int(input())
puncte = []
puncte_de_verificat = []

for i in range(nr_puncte):
    inp = input().split()
    puncte.append((int(inp[0]), int(inp[1])))

puncte.append(puncte[0])

nr_pct_de_verificat = int(input())

for i in range(nr_pct_de_verificat):
    inp = input().split()
    puncte_de_verificat.append((int(inp[0]), int(inp[1])))


for i in range(len(puncte_de_verificat)):
    ins = 0
    out = 0
    for j in range(nr_puncte):
        det = calc_det(puncte[j][0], puncte[j][1], puncte[j+1][0], puncte[j+1]
                       [1], puncte_de_verificat[i][0], puncte_de_verificat[i][1])
        if det > 0:
            ins += 1
        elif det < 0:
            out += 1
    if ins == nr_puncte:
        print("INSIDE")
    elif ins+out != nr_puncte:
        print("BOUNDARY")
    else:
        print("OUTSIDE")
