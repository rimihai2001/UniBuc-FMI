"""
Mihai Radu-Ioan
Grupa 132

Subiectul 3
Se dă fișierul text alimente.in cu următoarea structură:
a. pe prima linie apare numărul n reprezentând tipurile de alimente găsite la un magazin
b. pe următoarele n linii avem produse care au următoarea structură: <șir de caractere>,<int>,<șir
de caractere>, unde:
• primul șir de caractere este numele alimentului;
• numărul reprezintă codul firmei care îl distribuie;
• cel de-al doilea șir de caractere conține informații despre produs.
c. un număr m reprezentând numărul de produsele din magazin (stocul)
d. pe următoarele m linii sunt distribuitorii fiecărui produs aflat în stoc în magazin; fiecare dintre
aceste linii are structura <șir de caractere>,<int> unde:
• șirul de caractere este numele alimentului (unul dintre cele n tipuri date anterior);
• numărul reprezintă codul firmei care îl distribuie;
Șirurile de caractere nu conțin caracterul ‘,’ (virgula).
Exemplu de fișier de intrare:
4
Apa minerala,5,Izvorul Rece 2l
Apa minerala,7,Bicaz 1.5l
Lapte,5,1l
Ulei,5,1l
6
Lapte,5
Apa minerala,5
Apa minerala,7
Apa minerala,5
Ulei,5
Apa minerala,5
(explicații: sunt 3 sticle de Apa minerala de la distribuitorul 5 în stoc, de aceea informația Apa minerala,5
apare de 3 ori)
Cerințe:
a) [1,25p] Scrieți o funcție care primește ca parametru numele fișierului și memorează într-o
structură de date informațiile din fișier. Folosiți o structură convenabilă (eficientă) pentru a
răspunde cât mai eficient la cerințele de la subpunctele următoare. Se garantează ca un
distribuitor nu va vinde același tip de produs (nu vom avea “Apa minerala,5,Izvorul Rece 2l” și
“Apa minerala,5,Bicaz 1.5l”).
b) [0.75p] Scrieți o funcție detalii_produs care primește 2 parametri: structura în care s-au
memorat datele la cerința a) și un șir de caractere s, și returnează lista de alimente care au
numele s, fiecare aliment avand 3 componente: distribuitorul, cantitatea și informațiile despre
produs.
Să se apeleze funcția pentru un produs citit de la tastatură și să se afișeze pe ecran rezultatul
returnat ca în exemplul de mai jos ( se vor afișa toți distribuitorii care vând acel produs, cantitatea
de pe stoc și detaliile produsului, separate prin spatiu.
Exemplu:
Intrare tastatura: Iesire pe ecran:
Apa minerala 5 3 Izvorul Rece 2l
7 1 Bicaz 1.5l
c) [0,5p] Scrieți o funcție elimina_produse care primește ca parametri structura în care s-au
memorat datele la cerința a), un nume de produs, un distribuitor și o cantitate c și elimina din
structura c bucăți de produs de la acest distribuitor. Dacă c este mai mare decât numărul total
de produse din acel tip, se va întoarce None. Să se citească de la tastatură un nume de produs,
un distribuitor și o cantitate (de pe acelasi rând, separat prin ‘,’) și să se apeleze funcția
definită pe structura de la subpunctul a). Să se afișeze pe ecran cantitatea de produs de acest
tip rămasă în stoc.
Exemplu:
Intrare tastatura: Ieșire pe ecran:
Apa minerala,5,2 1
d) [0,5p] Scrieți o funcție comasare_produse care primește structura și comasează (grupează)
toate produsele cu același nume și returnează o listă care conține perechi de tipul
(nume_aliment, cantitate). Funcția va sorta elementele înainte de a le returna în funcție de
nume. Să se afișeze pe ecran elementele comasate (separate prin ‘ - ’ ).
Exemplu: (pentru intrarea de la punctul a)):
Apa minerala - 4
Lapte - 1
Ulei - 1"""

#a)

def citire_fis(file):
    f = open(file, 'r')
    mat = [line.split(',') for line in f]
    for s in range(len(mat)):
        for t in range(len(mat[s])):
            mat[s][t]=mat[s][t].replace('\n','')
    return mat

#b)

def detalii_produs(mat,s):
    tipuri=[]
    stoc=[]
    zona1=int(mat[0][0])
    zona2=int(mat[zona1+1][0])
    for i in range(1,zona1+1):
        if(mat[i][0]==s):
            tipuri.append(mat[i])
    for i in range(zona2,len(mat)):
        if(mat[i][0]==s):
            stoc.append(mat[i])
    for i in range(len(tipuri)):
        contor=0
        for j in range(len(stoc)):
            if stoc[j][0]==s and stoc[j][1]==tipuri[i][1]:
                contor+=1
        print(tipuri[i][1],contor,tipuri[i][2])

produs=input("Produs: ")
detalii_produs(mat,produs)

#c)

def stergere_produs(mat,nume,dis,c):
    contor=0
    zona1 = int(mat[0][0])
    zona2 = int(mat[zona1 + 1][0])
    for i in range(zona2,len(mat)):
        if mat[i][0]==nume:
            if mat[i][1]==dis:
                contor+=1
    if contor<int(c):
        return None
    return contor-int(c)


intrare=input("Date intrare:")
intrare=intrare.split(',')
print(stergere_produs(mat,intrare[0],intrare[1],intrare[2]))

#d)

def comasare_produse(mat):
    dict={}
    vector=[]
    zona1 = int(mat[0][0])
    zona2 = int(mat[zona1 + 1][0])
    for i in range(zona2, len(mat)):
        dict[mat[i][0]]+=mat[i][1]
    for i,j in dict.items():
        vector.append((i,j))
    vector.sort(key=sortare)
    for i in vector:
        print(i[0],"-",i[1])



