def calc_det(p1, p2, q1, q2, r1, r2):
    return q1*r2+p1*q2+p2*r1-q1*p2-r1*q2-r2*p1


nr_teste = int(input())

for i in range(nr_teste):
    inp = input().split()
    p1 = int(inp[0])
    p2 = int(inp[1])
    q1 = int(inp[2])
    q2 = int(inp[3])
    r1 = int(inp[4])
    r2 = int(inp[5])

    determinant = calc_det(p1, p2, q1, q2, r1, r2)

    if determinant > 0:
        print("LEFT")
    elif determinant < 0:
        print("RIGHT")
    else:
        print("TOUCH")

