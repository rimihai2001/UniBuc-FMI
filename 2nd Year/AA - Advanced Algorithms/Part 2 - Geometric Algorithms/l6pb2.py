import math

INF = math.inf

xmin = ymin = INF
xmax = ymax = -INF

left_pct = None
right_pct = None
top_pct = None
bottom_pct = None

n = int(input())
poligon_pct = []

for i in range(n):
    linie = input().split()
    punct = [int(linie[0]), int(linie[1])]
    poligon_pct.append(punct)

    if punct[0] > xmax:
        right_pct = i
        xmax = punct[0]

    if punct[0] < xmin:
        left_pct = i
        xmin = punct[0]

    if punct[1] < ymin:
        ymin = punct[1]
        bottom_pct = i

    if punct[1] > ymax:
        ymax = punct[1]
        top_pct = i


ok = True
a = left_pct
while a != right_pct and ok == True:
    if poligon_pct[a][0] >= poligon_pct[(a+1) % n][0]:
        ok = False
        break
    a += 1
    a %= n

while a != left_pct and ok:
    if poligon_pct[a][0] <= poligon_pct[(a+1) % n][0]:
        ok = False
        break
    a += 1
    a %= n

if ok == True:
    print("YES")
else:
    print("NO")


ok = True
a = bottom_pct
while a != top_pct and ok:
    if poligon_pct[a][1] >= poligon_pct[(a+1) % n][1]:
        ok = False
        break
    a += 1
    a %= n


while a != bottom_pct and ok:
    if poligon_pct[a][1] <= poligon_pct[(a+1) % n][1]:
        ok = False
        break
    a += 1
    a %= n

if ok == True:
    print("YES")
else:
    print("NO")
