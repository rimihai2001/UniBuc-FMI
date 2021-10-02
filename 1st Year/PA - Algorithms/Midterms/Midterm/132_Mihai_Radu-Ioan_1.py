"""
Mihai Radu-Ioan
Grupa 132

Subiectul 1
a) [0,5p] Scrieți o funcție citire_lista_vec cu un parametru reprezentând numele unui fișier text care
conține elementele unei liste de vectori de numere naturale cu următoarea structură: pe linia i a
fișierului sunt elementele vectorului i din listă, separate printr-un spațiu (vezi exemplul de fișier de
intrare la punctul c)). Funcția citește elementele listei de vectori din fișierul cu numele dat ca parametru
și returnează lista de vectori cu aceste elemente. Dacă în fișierul de intrare nu se află o listă în care
lungimile vectorilor să alterneze, având când mai multe când mai puține elemente față de vectorul
anterior (adică orice vector de pe poziția k în listă, cu excepția primei și ultimei poziții, trebuie să fie
încadrat de doi vectori care au fie ambii mai puține, fie ambii mai multe elemente față de vectorul k),
atunci funcția va returna None.
b) [1,25p] Scrieți o funcție multimi care primește ca parametri (în această ordine): o listă de vectori
și un număr variabil de numere naturale reprezentând indici ai vectorilor din listă (indicele primului
vector din listă este 0; indicii dați sunt mai mici decât numărul de vectori din listă). Asociem fiecărui
vector din listă două mulțimi: mulțimea elementelor care au cifra zecilor 0 (inclusiv elementele <10) și
mulțimea elementelor care au suma cifrelor pară.
Funcția returnează următoarele două informații:
- intersecția mulțimilor elementelor care au cifra zecilor 0 asociate vectorilor corespunzători indicilor
dați (elementele din intersecție sunt distincte două câte două).
- o listă cu elementele care au suma cifrelor pară și care apar în oricare dintre vectorii corespunzători
indicilor dați (lista poate conține elemente duplicate dacă acestea apar în vectori diferiți)
Se acordă jumătate din punctaj dacă în loc de o funcție cu număr variabil de parametri se va scrie o
funcție multimi care primește 2 parametri (în această ordine): o listă de vectori și o listă de numere
naturale reprezentând indici ai vectorilor din listă și returnează informațiile cerute la punctul b).
c) [1,25p] Se dă fișierul text "lista_vec.in" cu structura descrisă la punctul a). Folosind apeluri utile
ale funcțiilor de la a) și b) să se citească lista de vectori din fișierul “lista_vec.in” și să se afișeze pe
ecran numerele având suma cifrelor pară care se află în fișier pe (oricare dintre) primele două și ultima
linie (se vor afișa pe aceeași linie, separate prin spațiu, ordonate crescător), precum și numărul de
elemente având cifra zecilor 0 care se află pe toate cele 3 linii menționate (primele două și ultima)."""

#a)

def citire_lista_vec(file_name):
    file = open(file_name, "r")
    vec = [[int(x) for x in line.split()] for line in file]
    for i in range(1, len(vec)-1):
        if i%2==1:
            if len(vec[i]) > len(vec[i-1]) or len(vec[i]) > len(vec[i+1]):
                return None
        else:
            if len(vec[i]) < len(vec[i-1]) or len(vec[i]) < len(vec[i+1]):
                return None
    return vec

#b)

def sum_cif(nr):
    s=0
    nr=int(nr)
    while nr>0:
        s+=nr%10
        nr//=10
    return s


def check_nul(nr):
    if (nr//10)%10==0:
        return True
    else:
        return False


def multimi(vec, *index):
    nule = []
    pare = []

    for elem in vec[index[0]]:
        if check_nul(elem):
            nule.append(elem)

    for i in index:
        local_nule = []

        for elem in vec[index[i]]:
            if check_nul(elem):
                local_nule.append(elem)
            if sum_cif(elem)%2==0:
                pare.append(elem)

        nule=set(nule)&set(local_nule)

    return nule, pare

#c)

def citire_lista_vec(file_name):
    file = open(file_name, "r")
    vec = [[int(x) for x in line.split()] for line in file]
    for i in range(1, len(vec)-1):
        if i%2==1:
            if len(vec[i]) > len(vec[i-1]) or len(vec[i]) > len(vec[i+1]):
                return None
        else:
            if len(vec[i]) < len(vec[i-1]) or len(vec[i]) < len(vec[i+1]):
                return None
    return vec


def sum_cif(nr):
    s=0
    nr=int(nr)
    while nr>0:
        s+=nr%10
        nr//=10
    return s


def check_nul(nr):
    if (nr//10)%10==0:
        return True
    else:
        return False


def multimi(vec, *index):
    nule = []
    pare = []

    for elem in vec[index[0]]:
        if check_nul(elem):
            nule.append(elem)

    for i in index:
        local_nule = []

        for elem in vec[index[i]]:
            if check_nul(elem):
                local_nule.append(elem)
            if sum_cif(elem)%2==0:
                pare.append(elem)

        nule=set(nule)&set(local_nule)

    return nule, pare

vec = citire_lista_vec("lista_vec.in")
nule, pare = multimi(vec, 0, 1, -1)
pare.sort()
for elem in pare:
    print(elem, end=" ")
print()
print(len(nule))