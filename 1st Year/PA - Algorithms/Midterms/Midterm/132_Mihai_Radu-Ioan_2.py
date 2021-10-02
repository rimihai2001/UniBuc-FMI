#Mihai Radu-Ioan
#Grupa 132
#SUBIECTUL 2
#a) """[1p] Scrieți o funcție inlocuieste_cuv cu 3 parametri șiruri de caractere: prop, x, y (în această
#ordine), unde prop este o propoziție în care cuvintele sunt separate prin câte un spațiu,
#iar x și y sunt două șiruri diferite de caractere formate doar din litere, având aceeași lungime.
#Funcția returnează două valori:
#- propoziția obținută modificând propoziția prop astfel: fiecare cuvânt care are lungimea divizibilă cu
#cea a cuvântului x este înlocuit cu atâtea apariții concatenate ale lui y astfel încât să se păstreze
#lungimea cuvântului înlocuit.
#- numărul de cuvinte care au fost modificate dacă s-a modificat cel puțin un cuvânt în propoziție și -1
#altfel.
#b) [1p] Scrieți o funcție poz_negativ cu un parametru, care primește ca parametru o listă de
#numere întregi și returnează pozițiile (numerotate de la 1) în care apare în listă numărul
#-1. Dacă nu există o astfel de valoare funcția va returna None.
#c) [1p] Se dă fișierul text "propozitii.in" cu următoarea structură:
#- pe linia k a fișierului se află o propoziție cu cuvintele separate prin câte un spațiu
#Se citesc de la tastatură două cuvinte diferite a și b (formate doar din litere; cele două cuvinte se
#dau pe o linie, separate prin spațiu). Folosind apeluri utile ale funcțiilor de la a) și b) să se rezolve
#următoarele cerințe:
#- să se creeze un nou fișier text "propozitii_noi.out" cu propozițiile din fișierul "propozitii.in"
#modificate astfel: fiecare cuvânt care are lungimea divizibilă cu cea a cuvântului a este înlocuit cu
#atâtea apariții concatenate ale lui b astfel încât să se păstreze lungimea cuvântului înlocuit. Se vor
#afișa în fișier doar propozițiile în care s-au modificat maxim 2 cuvinte.
#- să se afișeze numărul propozițiilor din fișier în care nu s-a modificat niciun cuvânt, dacă există
#astfel de propoziții; altfel se va afișa numărul 0."""


#a)

def inlocuieste_cuv(prop,x,y):
    sirfinal=""
    contor=0
    propozitie2=prop[:-1]
    print(propozitie2)
    for cuvant in propozitie2.split():
        if len(cuvant)%len(x)==0:
            de_cate_ori=len(cuvant)//len(y)
            sirfinal += " "
            sirfinal+= y*de_cate_ori
            contor+=1
        else:
            sirfinal += " "
            sirfinal+=cuvant
    if contor==0:
        contor=-1
    sirfinal += "."
    return sirfinal,contor


#b)

def poz_negativ(lst):
    lista_negative=[]
    for i in range(len(lst)):
        if(lst[i]==-1):
            lista_negative.append(i+1)
    if(len(lista_negative)==0):
        return None
    return lista_negative


#c)

def inlocuieste_cuv(prop,x,y):
    sirfinal=""
    contor=0
    propozitie2=prop[:-1]
    print(propozitie2)
    for cuvant in propozitie2.split():
        if len(cuvant)%len(x)==0:
            de_cate_ori=len(cuvant)//len(y)
            sirfinal += " "
            sirfinal+= y*de_cate_ori
            contor+=1
        else:
            sirfinal += " "
            sirfinal+=cuvant
    if contor==0:
        contor=-1
    sirfinal += "."
    return sirfinal,contor

def poz_negativ(lst):
    lista_negative=[]
    for i in range(len(lst)):
        if(lst[i]==-1):
            lista_negative.append(i+1)
    if(len(lista_negative)==0):
        return None
    return lista_negative

f=open("propozitii.in", 'r')
prop=[line.rstrip() for line in f]
print(prop)
a=input("a=")
b=input("b=")
lista_cuv_mod=[]
with open('propozitii_noi.out', 'w') as g:
    for i in prop:
        prop_out,cont=inlocuieste_cuv(i,a,b)
        if(cont<=2):
            print(prop_out,file=g)
        lista_cuv_mod.append(cont)
lista_poz_neg=poz_negativ(lista_cuv_mod)
print(len(lista_poz_neg))