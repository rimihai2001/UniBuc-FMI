from cmath import inf
import math
import os
from argparse import ArgumentParser
import copy
import stopit
import sys
import time


'''
Sfere cazatoare - MIHAI Radu-Ioan, Grupa 232
link drive documentatie plus fisiere input:
https://drive.google.com/drive/folders/1Lc2iXT4xnidmNp_AjBdSBv5G9T5goSD5?usp=sharing
'''


sfere = []
sfere_temp = []
iesiri = []
poz_iesiri = []
poz_sfere = []
matrice = []
vizualizare = []
mat_adiacenta = []
mat_ponderi = []
cost = 0
step = 1
fout = ""
de_scos = []
dir_input = ""
dir_output = ""
nsol = 1
timeout = 1
k = 0
dist_max = 0


class Node:
    def __init__(self, matrice, configuratie, sfere, iesiri, distanta, predecesor=None):
        '''
        :param matrice: matricea turnurilor
        :param configuratie: matricea de sfere
        :param sfere: vector cu pozitia sferelor
        :param iesiri: vector cu pozitia iesirilor
        :param distanta: distanta fata de prima configuratie
        :param predecesor: ultima configuratie inainte de cea actuala
        '''
        self.matrice = matrice
        self.configuratie = configuratie
        self.sfere = sfere
        self.iesiri = iesiri
        self.distanta = distanta
        self.val_h = calculeaza_h(configuratie)
        self.value = self.distanta + self.val_h
        self.predecesor = predecesor

    def __repr__(self):
        '''
        :return: afisarea matricei de sfere
        '''
        return "\n".join("".join(row) for row in self.configuratie)

    def __lt__(self, other):
        '''

        :param other: alta clasa de tip Node
        :return: clasa mai mica dupa sortarea value
        '''
        return self.value < other.value

    def generare_suc(self, matrice=matrice, sfere=sfere):
        '''
        Verificam unde ar merge fiecare sfera dupa regula din enunt pentru a genera succesorii
        :param matrice: matricea turnurilor
        :param sfere: vector cu pozitia sferelor
        :return: vectorul de succesori posibili ai configuratiei actuale
        '''

        global sfere_temp
        succesori = []
        directii = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        for sfr in sfere:
            cost_mutare = inf
            sfera_finala = -1
            contor_directie = 0
            for directie in directii:
                contor_directie += 1
                if (
                    0 <= sfr[0] + directie[0] < len(matrice)
                    and 0 <= sfr[1] + directie[1] < len(matrice)
                    and cost_mutare
                    > (
                        matrice[sfr[0]][sfr[1]]
                        - matrice[sfr[0] + directie[0]][sfr[1] + directie[1]]
                    )
                    * (
                        matrice[sfr[0]][sfr[1]]
                        - matrice[sfr[0] + directie[0]][sfr[1] + directie[1]]
                    )
                    and (
                        matrice[sfr[0]][sfr[1]]
                        - matrice[sfr[0] + directie[0]][sfr[1] + directie[1]]
                    )
                    > 0
                ):
                    cost_mutare = (
                        matrice[sfr[0]][sfr[1]]
                        - matrice[sfr[0] + directie[0]][sfr[1] + directie[1]]
                    ) * (
                        matrice[sfr[0]][sfr[1]]
                        - matrice[sfr[0] + directie[0]][sfr[1] + directie[1]]
                    )
                    sfera_finala = contor_directie
            sfere_temp.append(sfera_finala)
        for sfera_in in sfere:
            self.configuratie[sfera_in[0]][sfera_in[1]] = "."
        for sfera_noua in sfere_temp:
            self.configuratie[sfera_noua[0]][sfera_noua[1]] = "@"
        succesori.append(self.configuratie)
        return succesori


def calculeaza_h(nod_actual, tip="banala"):
    '''
    Functie de calcularea euristicii (mai multe detalii despre fiecare in cadrul documentatiei)
    :param nod_actual: nodul actual
    :param tip: tipul euristicii
    :return: valoarea euristicii
    '''
    if verif_stare_finala() == True:
        return 0
    elif tip == "banala":
        return 1
    elif tip == "ad_1":
        dist_min=inf
        for sf in nod_actual.sfere:
            for ies in nod_actual.iesiri:
                dist_min=min(dist_min,(abs(sf[0]-ies[0])+abs(sf[1]-ies[1])))
        return dist_min
    elif tip == "ad_2":
        return len(nod_actual.sfere)
    elif tip == "neadmisibila":
        dist_max = -inf
        for sf in nod_actual.sfere:
            for ies in nod_actual.iesiri:
                dist_max = max(dist_max, (abs(sf[0] - ies[0]) + abs(sf[1] - ies[1])))
        return dist_max


def citire():
    """
    Contine parsarea fisierului, parcurgerea fisierului din folderul dat, citirea datelor din fisier si contruirea matricelor cerute in enunt
    """
    global sfere, matrice, iesiri, vizualizare, fout, de_scos, cost, mat_ponderi, mat_adiacenta, poz_iesiri, poz_sfere, dir_input, dir_output, nsol, timeout
    parser = ArgumentParser()
    parser.add_argument(
        "-dir_in", dest="dir_input", default="input", help="input folder"
    )
    parser.add_argument(
        "-dir_out",
        dest="dir_output",
        default="output",
        help="output folder",
    )
    parser.add_argument("-nsol", dest="nsol", default="1", help="numar solutii")
    parser.add_argument("-to", dest="timeout", default="5", help="Timeout")

    args = vars(parser.parse_args())
    dir_input, dir_output, nsol, timeout = (
        args["dir_input"],
        args["dir_output"],
        int(args["nsol"]),
        int(args["timeout"]),
    )
    listaFisiereinput = os.listdir("input")
    if not os.path.isdir(dir_output):
        os.mkdir(dir_output)
    else:
        for file in os.listdir(dir_output):
            os.remove(dir_output + "/" + file)
    for fs in listaFisiereinput:
        for i in range(1, 7):
            nume_file_out = dir_output + "/output_" + fs + "__algo__"
            if i == 1:
                fout = open(nume_file_out + "DF", "w")
            elif i == 2:
                fout = open(nume_file_out + "BF", "w")
            elif i == 3:
                fout = open(nume_file_out + "DFI", "w")
            elif i == 4:
                fout = open(nume_file_out + "Astar", "w")
            elif i == 5:
                fout = open(nume_file_out + "Astar_opt", "w")
            else:
                fout = open(nume_file_out + "IDAstar", "w")
            fin = open(dir_input + "/" + fs, "r+")
            linie = fin.readlines()
            sfere = []
            iesiri = []
            matrice = []
            vizualizare = []
            mat_adiacenta = []
            mat_ponderi = []
            de_scos = []
            cost = 0
            input_type = 0
            for l in linie:
                lin = l.split()
                if lin == ["sfere"]:
                    input_type = 1
                    continue
                if lin == ["iesiri"]:
                    input_type = 2
                    continue
                if input_type == 0:
                    matrice.append(list(map(int, lin)))
                elif input_type == 1:
                    sfere.append(list(map(int, lin)))
                else:
                    iesiri.append(list(map(int, lin)))
            k = int(matrice[0][0])
            dist_max = int(matrice[0][1])
            matrice = matrice[1:]
            vizualizare = [
                ["." for i in range(len(matrice[0]))] for j in range(len(matrice))
            ]
            for ies in iesiri:
                vizualizare[ies[0]][ies[1]] = "#"
            for sf in sfere:
                if vizualizare[sf[0]][sf[1]] == "#":
                    vizualizare[sf[0]][sf[1]] = "%"
                    de_scos.append(sf)
                else:
                    vizualizare[sf[0]][sf[1]] = "@"
            if verif_input_valid() == False:
                fout.write("Date de input invalide!")
            else:
                afisare(fout)
                if verif_stare_finala_alternativa() == True:
                    afisare(fout, 1)
                # actualizare_cost_stare()


def afisare(nume_fisier=fout, final=0):
    '''
    Functie de afisare a output-ului in fisier
    :param nume_fisier: numele fisierului de iesire
    :param final: parametru care arata daca programul este la final si trebuie afisat costul final

    '''
    if final == 0:
        nume_fisier.write(str(step) + ")\n")
        nume_fisier.write("cost:" + str(cost) + "\n")
        nume_fisier.write("Matrice turnuri:\n")
        for line in matrice:
            nume_fisier.write("  ".join(map(str, line)) + "\n")

        nume_fisier.write("Matrice sfere:\n")
        for line in vizualizare:
            nume_fisier.write("  ".join(map(str, line)) + "\n")
        nume_fisier.write("\n")
    if final == 1:
        nume_fisier.write("cost final:" + str(cost) + "\n")


def numar_update_stare():
    """
    :return: NT = numar turnuri ce pot fi scazute in inaltime
    """
    return math.ceil(2 / 3 * len(sfere))


def eliminare_sfere_final(sfere_de_eliminat=de_scos):
    """
    Daca o sfera este pe o iesire, atunci eliminam sfera si iesirea din liste
    :param sfere_de_eliminat: pozitie ce se regaseste si sfera si iesirea
    """
    for afara in sfere_de_eliminat:
        iesiri.remove(afara)
        sfere.remove(afara)


def verif_stare_finala():
    """
    :return: avand in considerare ca elimin sferele din vectorul de sfere cand ajung la iesire, atunci starea finala se indeplineste cand toate sferele au ajuns la iesire, deci vectorul de sfere este gol
    """
    eliminare_sfere_final()
    return len(sfere) == 0


def verif_stare_finala_alternativa():
    """
    :return: daca toate sferele se afla pe iesiri
    """
    return all(item in iesiri for item in sfere)


def actualizare_cost_stare():
    """
    In sfere_temp avem pozitia actuala a sferelor si in sfere ultima pozitie, adaugam la cost costul dintre mutarile consecutive si actualizam vectorul sfere
    :return:
    """
    global cost, sfere, sfere_temp
    for i in range(len(sfere)):
        cost += (
            matrice[sfere[i][0]][sfere[i][1]]
            - matrice[sfere_temp[i][0]][sfere_temp[i][1]]
        ) * (
            matrice[sfere[i][0]][sfere[i][1]]
            - matrice[sfere_temp[i][0]][sfere_temp[i][1]]
        )
    sfere = copy.deepcopy(sfere_temp)
    sfere_temp.clear()


def verif_input_valid():
    """
    Cazuri de input invalid:
    - daca sunt mai multe sfere decat iesiri
    - mai multe sfere in acelasi loc
    - mai multe iesiri in acelasi loc
    - daca o iesire nu este pe marginea grid-ului
    :return: True daca este valid si False daca nu este valid
    """
    if len(sfere) > len(iesiri):
        return False
    for sf in sfere:
        if sfere.count(sf) > 1:
            return False
    for ies in iesiri:
        if iesiri.count(ies) > 1:
            return False
        if (
            (ies[0] == 0 or ies[0] == len(matrice) - 1)
            or (ies[1] == 0 or ies[1] == len(matrice[0]) - 1)
        ) == False:
            return False
    return True


citire()
