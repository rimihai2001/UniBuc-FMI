def calc_det(p1, p2, q1, q2, r1, r2):
    return q1*r2+p1*q2+p2*r1-q1*p2-r1*q2-r2*p1


vir_stanga = 0
vir_dreapta = 0
fara_vir = 0

nr_puncte = int(input())
puncte = []

for i in range(nr_puncte):
    inp = input().split()
    puncte.append((int(inp[0]), int(inp[1])))

puncte.append(puncte[0])

for i in range(nr_puncte+1-2):
    p1, p2 = puncte[i]
    q1, q2 = puncte[i+1]
    r1, r2 = puncte[i+2]

    determinant = calc_det(p1, p2, q1, q2, r1, r2)

    if determinant > 0:
        vir_stanga += 1
    elif determinant < 0:
        vir_dreapta += 1
    else:
        fara_vir += 1

print(vir_stanga, vir_dreapta, fara_vir)
