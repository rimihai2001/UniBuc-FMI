ore_activitati = 0


class Elev:
    id = 1

    def __init__(self, nume=None, sanatate=90, inteligenta=20, oboseala=0, buna_dispozitie=100):
        global id
        if nume == None:
            self.nume = "Necunoscut_"+str(self.__class__.id)
        else:
            self.nume = nume
        self.sanatate = int(sanatate)
        self.inteligenta = int(inteligenta)
        self.oboseala = int(oboseala)
        self.buna_dispozitie = int(buna_dispozitie)
        self.__class__.id = int(self.__class__.id+1)

    def desfasoara_activitate(self, activitate):
        timp_executat_activ = 0
        timp_executat_activ += lista_activ[activitate][5]
        self.sanatate += lista_activ[activitate][1]
        self.inteligenta += lista_activ[activitate][2]
        self.oboseala += lista_activ[activitate][3]
        self.buna_dispozitie += lista_activ[activitate][4]

    def trece_ora(self, ora, activitate):
        if (ora >= 22 or ora < 6) and lista_activ[activitate][0] != "dormit":
            self.sanatate -= 1
        self.sanatate += lista_activ[activitate][1] / \
            lista_activ[activitate][5]
        self.inteligenta += lista_activ[activitate][2] / \
            lista_activ[activitate][5]
        self.oboseala += lista_activ[activitate][3] / \
            lista_activ[activitate][5]
        self.buna_dispozitie += lista_activ[activitate][4] / \
            lista_activ[activitate][5]

    def testeaza_final(self):
        if self.inteligenta == 100:
            print('Elevul '+self.nume+' a absolvit. Felicitari!')
            return True
        if self.sanatate == 0 or self.buna_dispozitie == 0:
            print('Elevul '+self.nume+' este bolnav si a fost dus la spital.')
            return True
        if self.oboseala == 100:
            self.inteligenta = self.inteligenta // 2
            self.buna_dispozitie = self.buna_dispozitie // 2
            self.sanatate = self.sanatate // 2
            return False
        return False

    def verificare(self):
        if self.oboseala > 100:
            self.oboseala = 100
        if self.inteligenta > 100:
            self.inteligenta = 100
        if self.sanatate > 100:
            self.sanatate = 100
        if self.buna_dispozitie > 100:
            self.buna_dispozitie = 100
        if self.oboseala < 0:
            self.oboseala = 0
        if self.inteligenta < 0:
            self.inteligenta = 0
        if self.sanatate < 0:
            self.sanatate = 0
        if self.buna_dispozitie < 0:
            self.buna_dispozitie = 0

    def afiseaza_raport(cls):
        print("Activitati realizate: ", end="")

        for aaa in dict_elev:
            print(str(aaa)+"("+str(dict_elev[aaa])+" ore),", end=" ")
        print()

    def __repr__(self):
        finalstr = str(self.nume)+' ' + '(snt: '+str(self.sanatate)+', intel: '+str(self.inteligenta) + \
            ', obos: '+str(self.oboseala)+', dispoz: ' + \
            str(self.buna_dispozitie) + ')'
        return finalstr


class Activitate:
    def __init__(self, nume, factor_sanatate, factor_inteligenta, factor_oboseala, factor_dispozitie, durata):
        self.nume = nume
        self.factor_sanatate = int(factor_sanatate)
        self.factor_inteligenta = int(factor_inteligenta)
        self.factor_oboseala = int(factor_oboseala)
        self.factor_dispozitie = int(factor_dispozitie)
        self.durata = int(durata)


def porneste_simulare():
    comanda = input("Comanda= ")
    if comanda == 'gata':
        global merge
        merge = False
        return False
    elif comanda == 'continua':
        return True
    elif isinstance(int(comanda), int) == True:
        global ore_activitati
        ore_activitati = int(comanda)
        return True
    return True


if __name__ == "__main__":
    ora_curenta = 9
    merge = True
    lista_activ = []
    lista_elevi = []
    while merge == True:
        porneste_simulare()
        if merge == False:
            break

        n = int(input("Numar elevi="))
        for nrelev in range(0, n):
            ora_cur = ora_curenta
            elev_nume = input("Nume elev: ")
            elev_sanatate = int(input("Sanatate elev: "))
            elev_inteligenta = int(input("Inteligenta elev: "))
            elev_oboseala = int(input("Oboseala elev: "))
            elev_bd = int(input("Buna dipozitie elev: "))

            if elev_nume == "":
                elev_nume = None

            elv = Elev(elev_nume, elev_sanatate,
                       elev_inteligenta, elev_oboseala, elev_bd)
            fin = open("file.txt", "r+")
            linie = fin.readlines()

            for l in linie:
                lin = l.split()
                ac = Activitate(lin[0], int(lin[1]), int(lin[2]), int(
                    lin[3]), int(lin[4]), int(lin[5]))
                lista_activ.append([lin[0], int(lin[1]), int(lin[2]), int(
                    lin[3]), int(lin[4]), int(lin[5])])
            timp = int(ore_activitati)
            elv.verificare()
            print("Ora "+str((int(ora_curenta)+int(ore_activitati)) % 24)+":00")
            afis_act = ""
            afis_comp = ""
            nract = 0
            while timp > 0 and elv.testeaza_final() == False:

                dict_elev = {}
                elv.verificare()
                if lista_activ[0][5] <= timp:
                    elv.desfasoara_activitate(0)
                    timp -= lista_activ[0][5]
                    ora_cur += lista_activ[0][5]
                    ora_cur %= 24
                    afis_act = lista_activ[0][0]
                    afis_comp = str(lista_activ[0][5]) + \
                        '/'+str(lista_activ[0][5])
                    nract += 1
                else:
                    nract += 1
                    afis_act = lista_activ[0][0]
                    afis_comp = str(timp)+'/'+str(lista_activ[0][5])
                    for i in range(0, timp):
                        elv.trece_ora(ora_cur, 0)
                        ora_cur += 1
                        ora_cur %= 24
                        timp -= 1
                if lista_activ[0][0] in dict_elev:
                    dict_elev[lista_activ[0][0]] += lista_activ[0][5]
                else:
                    dict_elev[lista_activ[0][0]] = lista_activ[0][5]
                lista_activ.pop(0)
                elv.verificare()
            if elv.testeaza_final() == False:
                print(repr(elv)+' '+afis_act+' '+afis_comp)
                if nract > 0:
                    elv.afiseaza_raport()
