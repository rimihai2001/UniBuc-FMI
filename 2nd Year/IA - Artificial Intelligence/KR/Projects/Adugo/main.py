import time
import copy
import pygame
import sys


ADANCIME = 0
ESTIMARE = 0
NUMAR_MUTARI = 0
NUMAR_CAINI = 14


class Joc:
    '''
    Clasa pentru a genera matricea jocului
    '''

    LIBER = "."
    INVALID = " "
    PIESA_JAGUAR = "j"
    PIESA_CAINE = "c"
    maxim_caini = 14
    drumuri = {}
    poz_valide = []

    def __init__(self, matrice_tabla=None):
        '''
        :param matrice_tabla: daca avem deja o matrice salvata, o putem initializa cu aceea
        '''
        global NUMAR_MUTARI

        self.ultima_mutare = None

        if matrice_tabla:

            self.matrice_tabla = matrice_tabla
            NUMAR_MUTARI += 1
        else:

            self.matrice_tabla = [
                [Joc.PIESA_CAINE for i in range(5)] for i in range(3)]
            self.matrice_tabla[2][2] = Joc.PIESA_JAGUAR

            lista_libere = [[Joc.LIBER for i in range(5)] for i in range(4)]
            self.matrice_tabla.extend(lista_libere)

            self.matrice_tabla[5][0] = Joc.INVALID
            self.matrice_tabla[5][4] = Joc.INVALID
            self.matrice_tabla[6][1] = Joc.INVALID
            self.matrice_tabla[6][3] = Joc.INVALID

            Joc.construire_drumuri()

    @classmethod
    def construire_drumuri(cls):
        '''
        Se construiesc drumurile intre pozitiile din matrice
        '''
        cls.poz_valide = [
            (i, j) for i in [0, 1, 2, 3, 4] for j in [0, 1, 2, 3, 4]
        ]

        directii1 = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        directii2 = [
            (0, -1),
            (0, 1),
            (-1, 0),
            (1, 0),
            (-1, -1),
            (1, 1),
            (-1, 1),
            (1, -1),
        ]

        for i in range(5):
            for j in range(5):
                drumuri_crt = []

                if i % 2 == j % 2:
                    for directie in directii2:
                        x = i + directie[0]
                        y = j + directie[1]

                        if (x, y) in cls.poz_valide:
                            drumuri_crt.append((x, y))
                else:
                    for directie in directii1:
                        x = i + directie[0]
                        y = j + directie[1]

                        if (x, y) in cls.poz_valide:
                            drumuri_crt.append((x, y))

                cls.drumuri[(i, j)] = drumuri_crt

        cls.poz_valide.extend([(5, 1), (5, 2), (5, 3), (6, 0), (6, 2), (6, 4)])

        cls.drumuri[(4, 2)].extend([(5, 1), (5, 2), (5, 3)])
        cls.drumuri[(5, 1)] = [(4, 2), (5, 2), (6, 0)]
        cls.drumuri[(5, 2)] = [(4, 2), (5, 1), (5, 3), (6, 2)]
        cls.drumuri[(5, 3)] = [(4, 2), (5, 2), (6, 4)]
        cls.drumuri[(6, 0)] = [(5, 1), (6, 2)]
        cls.drumuri[(6, 2)] = [(6, 0), (6, 4), (5, 2)]
        cls.drumuri[(6, 4)] = [(5, 3), (6, 2)]

    def pozitii_caini_tabla(self):
        '''

        :return: Pozitiile cainilor din matricea grafica
        '''
        lista_caini = []
        for i, j in Joc.poz_valide:
            if self.matrice_tabla[i][j] == Joc.PIESA_CAINE:
                lista_caini.append(
                    [
                        j * 110 + 30,
                        i * 110 + 30,
                    ]
                )
        return lista_caini

    def poz_jag(self):
        '''
        :return: pozitia jaguarului din matricea grafica
        '''
        lista_coord_jaguar = []
        for i, j in Joc.poz_valide:
            if self.matrice_tabla[i][j] == Joc.PIESA_JAGUAR:
                lista_coord_jaguar.append(
                    [
                        j * 110 + 30,
                        i * 110 + 30,
                    ]
                )
                break
        return lista_coord_jaguar

    def adauga_in_display_ecran_joc(self):
        '''
        adaugarea elementelor in pygame
        '''

        lista_pozitii_piese_caine = self.pozitii_caini_tabla()
        pozitie_tabla_jaguar = self.poz_jag()

        ecran.fill(bgColour)
        for nod in coordonateNoduri:
            pygame.draw.circle(
                surface=ecran,
                color=elemColour,
                center=nod,
                radius=10,
                width=0,
            )

        for muchie in Graph.muchii:
            p0 = coordonateNoduri[muchie[0]]
            p1 = coordonateNoduri[muchie[1]]
            pygame.draw.line(
                surface=ecran, color=elemColour, start_pos=p0, end_pos=p1, width=5
            )
        for nod in lista_pozitii_piese_caine:
            ecran.blit(
                piesa_caine, (nod[0] - 20, nod[1] - 20)
            )
        for nod in pozitie_tabla_jaguar:
            ecran.blit(
                piesa_jaguar, (nod[0] - 20, nod[1] - 20)
            )

        my_font = pygame.font.SysFont("arial", 20)
        text_surface = my_font.render(
            "Scor:" + str(NUMAR_MUTARI), False, (0, 0, 0))
        ecran.blit(text_surface, (225, 710))

        my_font = pygame.font.SysFont("arial", 20)

        if NUMAR_MUTARI % 2 == 1:
            text_surface = my_font.render("Urmeaza: Caine", False, (0, 0, 0))
        else:
            text_surface = my_font.render("Urmeaza: Jaguar", False, (0, 0, 0))

        ecran.blit(text_surface, (200, 750))

        pygame.display.update()

    def pozitie_jaguar_matrice(self):
        '''
        :return: coordonatele jaguarului in matrice
        '''
        for i in range(len(self.matrice_tabla)):
            for j in range(len(self.matrice_tabla[i])):
                if (i, j) in Joc.poz_valide:
                    if self.matrice_tabla[i][j] == Joc.PIESA_JAGUAR:
                        return i, j

    def stare_finala(self):
        '''
        verificam daca starea este finala
        :return: Castigator daca este finala, False daca nu
        '''
        if self.ultima_mutare == None:
            return False

        if NUMAR_CAINI <= 9:
            return "j"

        x_jag, y_jag = self.pozitie_jaguar_matrice()
        last_check = [
            (0, 1),
            (0, 2),
            (0, -1),
            (0, -2),
            (1, 0),
            (2, 0),
            (-2, 0),
            (1, 0),
            (-1, -1),
            (-2, -2),
            (1, 1),
            (2, 2),
            (1, -2),
            (2, -2),
            (-1, 1),
            (-2, 2),
        ]

        poz_posibile = 0
        poz_ocupate = 0

        for dir in last_check:
            if x_jag + dir[0] < len(self.matrice_tabla) and y_jag + dir[1] < len(
                self.matrice_tabla[x_jag]
            ):
                poz_posibile += 1
                if self.matrice_tabla[x_jag][y_jag] == "c":
                    poz_ocupate += 1

        if poz_posibile == poz_ocupate:
            return "c"

        return False

    def estimeaza_scor_1(self):
        '''

        :return: Scorul este dat de numarul de mutari facute de un jucator
        '''
        return round(int(NUMAR_MUTARI / 2))

    def estimeaza_scor_2(self):
        '''

        :return: Scorul este dat de nr total de mutari * nr de caini ramasi pe tabla in starea finala
        '''
        return round(int(NUMAR_MUTARI * NUMAR_CAINI))

    def __str__(self):
        '''

        :return: afisare frumoasa in consola
        '''
        sir = ""
        for i in self.matrice_tabla:
            sir += " ".join(i)
            sir += "\n"
        return sir


def afisare_finala(stare_curenta):
    '''

    :param stare_curenta: tabla in care se afla jocul
    :return: True daca e stare finala (caz in care se afiseaza castigatorul), False daca nu
    '''
    stare_finala = stare_curenta.tabla_joc.stare_finala()
    if stare_finala == True:
        print("A castigat " + stare_finala)
        return True
    else:
        return False


class Buton:
    '''
    Clasa pentru a face butoanele din meniu
    '''

    def __init__(
        self,
        display=None,
        left=0,
        top=0,
        w=0,
        h=0,
        button_color_bg=(0, 0, 100),
        button_color_bg_selected=(0, 100, 0),
        text="",
        font="arial",
        font_size=16,
        font_color=(255, 255, 255),
        button_value="",
    ):
        self.display = display
        self.button_color_bg = button_color_bg
        self.button_color_bgSel = button_color_bg_selected
        self.text = text
        self.font = font
        self.w = w
        self.h = h
        self.selectat = False
        self.font_size = font_size
        self.font_color = font_color
        fontObj = pygame.font.SysFont(self.font, self.font_size)
        self.textRandat = fontObj.render(self.text, True, self.font_color)
        self.dreptunghi = pygame.Rect(left, top, w, h)
        self.dreptunghiText = self.textRandat.get_rect(
            center=self.dreptunghi.center)
        self.button_value = button_value

    def selecteaza(self, sel):
        '''

        :param sel: selectat pentru a afisa ca butonul este selectat vizual
        '''
        self.selectat = sel
        self.adauga_in_display()

    def select_button(self, coord):
        if self.dreptunghi.collidepoint(coord):
            self.selecteaza(True)
            return True
        return False

    def construire_grid(self):
        '''
        construim un dreptunghi pentru grid
        '''
        self.dreptunghi.left = self.left
        self.dreptunghi.top = self.top
        self.dreptunghiText = self.textRandat.get_rect(
            center=self.dreptunghi.center)

    def adauga_in_display(self):
        '''
        adaug elementele vizuale
        '''
        if self.selectat:
            culoareF = self.button_color_bgSel
        else:
            culoareF = self.button_color_bg
        pygame.draw.rect(self.display, culoareF, self.dreptunghi)
        self.display.blit(self.textRandat, self.dreptunghiText)


class Lista_Butoane:
    '''
    clasa pentru a face grid de butoane
    '''

    def __init__(
        self, listaButoane=[], indiceSelectat=0, spatiuButoane=10, left=0, top=0
    ):
        self.listaButoane = listaButoane
        self.indiceSelectat = indiceSelectat
        self.listaButoane[self.indiceSelectat].selectat = True
        self.top = top
        self.left = left
        leftCurent = self.left
        for b in self.listaButoane:
            b.top = self.top
            b.left = leftCurent
            b.construire_grid()
            leftCurent += spatiuButoane + b.w

    def select_button(self, coord):
        '''

        '''
        for index_but, b in enumerate(self.listaButoane):
            if b.select_button(coord):
                self.listaButoane[self.indiceSelectat].selecteaza(False)
                self.indiceSelectat = index_but
                return True
        return False

    def adauga_in_display(self):
        '''
        adaugare in display a grid-ului de butoane
        '''
        for b in self.listaButoane:
            b.adauga_in_display()

    def getbutton_value(self):
        '''
        getter de valoare pentru un buton
        '''
        return self.listaButoane[self.indiceSelectat].button_value


def adauga_in_display_alegeri(display, tabla_curenta):
    '''

    :param display: variabila pentru a afisa butonul
    :param tabla_curenta: matricea actuala a starii
    '''
    buton_selectare_algo = Lista_Butoane(
        top=30,
        left=30,
        listaButoane=[
            Buton(display=display, w=80, h=30,
                  text="Minimax", button_value="minimax"),
            Buton(display=display, w=80, h=30,
                  text="Alpha-Beta", button_value="alpha-beta"),
        ],
        indiceSelectat=0,
    )
    buton_selectare_piesa_player1 = Lista_Butoane(
        top=180,
        left=30,
        listaButoane=[
            Buton(display=display, w=80, h=30,
                  text="Jaguar", button_value="j"),
            Buton(display=display, w=80, h=30, text="Caini", button_value="c"),
        ],
        indiceSelectat=0,
    )
    buton_selectare_dificultate = Lista_Butoane(
        top=330,
        left=30,
        listaButoane=[
            Buton(display=display, w=80, h=30,
                  text="Usor", button_value="usor"),
            Buton(display=display, w=80, h=30,
                  text="Mediu", button_value="mediu"),
            Buton(display=display, w=80, h=30,
                  text="Greu", button_value="greu"),
        ],
        indiceSelectat=0,
    )
    buton_estimare_scor = Lista_Butoane(
        top=480,
        left=30,
        listaButoane=[
            Buton(display=display, w=120, h=30,
                  text="Estimare Scor 1", button_value="1"),
            Buton(display=display, w=120, h=30,
                  text="Estimare Scor 2", button_value="2"),
        ],
        indiceSelectat=0,
    )
    buton_tip_joc = Lista_Butoane(
        top=610,
        left=30,
        listaButoane=[
            Buton(display=display, w=120, h=30,
                  text="Jucator vs Jucator", button_value="2"),
            Buton(display=display, w=120, h=30,
                  text="PC vs Jucator", button_value="1"),
            Buton(display=display, w=120, h=30,
                  text="PC vs PC", button_value="3"),
        ],
        indiceSelectat=1,
    )

    play = Buton(
        display=display,
        top=700,
        left=30,
        w=40,
        h=30,
        text="PLAY",
        button_color_bg=(155, 0, 55),
    )

    buton_selectare_algo.adauga_in_display()
    buton_selectare_piesa_player1.adauga_in_display()
    buton_selectare_dificultate.adauga_in_display()
    buton_estimare_scor.adauga_in_display()
    buton_tip_joc.adauga_in_display()
    play.adauga_in_display()

    while True:
        for ev in pygame.event.get():
            if ev.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif ev.type == pygame.MOUSEBUTTONDOWN:
                pos = pygame.mouse.get_pos()
                if not buton_selectare_algo.select_button(pos):
                    if not buton_selectare_piesa_player1.select_button(pos):
                        if not buton_selectare_dificultate.select_button(pos):
                            if not buton_estimare_scor.select_button(pos):
                                if not buton_tip_joc.select_button(pos):
                                    if play.select_button(pos):
                                        tabla_curenta.adauga_in_display_ecran_joc()
                                        return (
                                            buton_selectare_piesa_player1.getbutton_value(),
                                            buton_selectare_algo.getbutton_value(),
                                            buton_selectare_dificultate.getbutton_value(),
                                            buton_estimare_scor.getbutton_value(),
                                            buton_tip_joc.getbutton_value(),
                                        )
        pygame.display.update()


def lista_muchii(noduri):
    '''
    :param noduri: lista de noduri ale grafului
    :return: lista de muchii a grafului
    '''
    muchii = []
    for pz in Joc.poz_valide:
        for item in Joc.drumuri[pz]:
            muchii.append(
                (noduri.index((pz[1], pz[0])), noduri.index((item[1], item[0]))))
    return muchii


class Graph:
    '''
    clasa pentru initializarea unui graf pentru a afisa in pygame
    '''

    noduri = []
    muchii = []

    @classmethod
    def init_graf(self):
        self.noduri = [(j, i) for i, j in Joc.poz_valide]
        self.muchii = lista_muchii(self.noduri)


def main():
    '''
    Functia de main care initializeaza evenimentele si construieste tabla
    '''
    global ecran, bgColour, elemColour, piesa_caine, piesa_jaguar, coordonateNoduri, ESTIMARE, NUMAR_MUTARI

    tabla_curenta = Joc()
    Graph.init_graf()

    pygame.init()
    pygame.display.set_caption("Adugo (cainii si jaguarul) - Mihai Radu-Ioan")

    bgColour = (255, 255, 255)
    elemColour = (0, 0, 100)
    ecran = pygame.display.set_mode(size=(550, 800))

    piesa_caine = pygame.image.load("piesa-caine.png")
    piesa_jaguar = pygame.image.load("piesa-jaguar.png")

    piesa_caine = pygame.transform.scale(piesa_caine, (40, 40))
    piesa_jaguar = pygame.transform.scale(piesa_jaguar, (40, 40))

    coordonateNoduri = [[30 + 110 * x for x in nod] for nod in Graph.noduri]

    val, tip_algoritm, dificultate, estimare, tip_joc = adauga_in_display_alegeri(
        ecran, tabla_curenta
    )

    if dificultate == "usor":
        ADANCIME = 1
    elif dificultate == "mediu":
        ADANCIME = 2
    elif dificultate == "greu":
        ADANCIME = 3

    if estimare == "1":
        ESTIMARE = 1
    elif estimare == "2":
        ESTIMARE = 2

    print("Tabla:")
    print(str(tabla_curenta))

    tabla_curenta.adauga_in_display_ecran_joc()

    if tip_joc == "1":
        print("TIP JOC:", 1)
    elif tip_joc == "2":
        print("TIP JOC:", 2)
    else:
        print("TIP JOC:", 3)


if __name__ == "__main__":
    timp_start = time.time()
    main()
    pygame.font.init()
    while True:
        for event in pygame.event.get():
            timp_pas = time.time()
            print("Timp mutare: ", round((time.time() - timp_pas)), " secunde")
            if ESTIMARE == 1:
                print("Scor actual: ", Joc.estimeaza_scor_1(Joc))
            elif ESTIMARE == 2:
                print("Scor actual: ", Joc.estimeaza_scor_2(Joc))
            if event.type == pygame.QUIT:
                print("Timp total joc: ", round(
                    (time.time() - timp_start)), " secunde")
                print("Mutari jucator 1: ", round(NUMAR_MUTARI / 2))
                print("Mutari jucator 2: ", round(NUMAR_MUTARI / 2))
                pygame.quit()
                sys.exit()
