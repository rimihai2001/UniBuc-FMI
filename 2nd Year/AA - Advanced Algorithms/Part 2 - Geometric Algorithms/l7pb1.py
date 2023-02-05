import math


INF = math.inf

xmax = -INF
xmin = INF
ymax = INF
ymin = -INF


def isVertical(P):
    if(P[1] == 0):
        return True
    return False


n = int(input())

lista_planuri = []

for i in range(n):
    plan = input()
    plan = plan.split()
    elem_plan = [int(plan[0]), int(plan[1]), int(plan[2])]
    lista_planuri.append(elem_plan)

for plan in lista_planuri:
    if isVertical(plan):
        d = -plan[2]/plan[0]
        if plan[0] > 0:
            xmin = min(xmin, d)
        else:
            xmax = max(xmax, d)
    else:
        d = -plan[2]/plan[1]
        if plan[1] > 0:
            ymax = min(ymax, d)
        else:
            ymin = max(ymin, d)

if (xmax > xmin or ymax < ymin):
    print("VOID")
else:
    if (xmax != -INF and xmin != INF and ymin != -INF and ymax != INF):
        print("BOUNDED")
    else:
        print("UNBOUNDED")
