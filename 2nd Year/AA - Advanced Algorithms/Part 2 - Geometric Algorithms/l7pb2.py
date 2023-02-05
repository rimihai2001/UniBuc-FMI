import math

INF = math.inf

def intersectie_planuri(P, Q):
    xmax = -INF
    xmin = INF
    ymin = INF
    ymax = -INF
    for plan in P:

        if plan[1] == 0:
            if plan[0]*Q[0]+ plan[2]>=0:
                continue
            d = -plan[2] / plan[0]
            if d > Q[0]:
                xmin = min(xmin, d)

            else:
                xmax = max(xmax, d)
        else:
            if plan[1]*Q[1]+ plan[2]>=0:
                continue
            d = -plan[2] / plan[1]
            if d > Q[1]:
                ymin = min(ymin, d)

            else:
                ymax = max(ymax, d)

    if max(xmin, ymin) == INF or min(xmax, ymax) == -INF:
        return 0
    return (xmax-xmin)*(ymax-ymin)


n = int(input())

lista_planuri = []

for i in range(n):
    plan = input()
    plan = plan.split()
    elem_plan = [int(plan[0]), int(plan[1]), int(plan[2])]
    lista_planuri.append(elem_plan)

n2 = int(input())

for i in range(n2):
    punct_input = input()
    punct_input = punct_input.split()
    punct = [float(punct_input[0]), float(punct_input[1])]
    valid = intersectie_planuri(lista_planuri, punct)
    if valid == 0:
        print("NO")
    else:
        print("YES")
        print("{:.6f}".format(valid))
