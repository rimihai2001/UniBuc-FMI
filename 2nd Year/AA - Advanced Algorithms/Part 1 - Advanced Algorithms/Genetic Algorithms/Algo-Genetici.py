import random, math, copy
from matplotlib import pyplot as plt


# generare cromozom
def generate_chromosome(length):
    return [random.randint(0, 1) for ll in range(length)]


# generare populatie
def generate_population():
    first_pop = [generate_chromosome(size_crom) for cromz in range(pop_size)]
    return first_pop


# functia de fitness
def func(x):
    return coef_func[0] * x * x + coef_func[1] * x + coef_func[2]


# valoare codificata
def val_coded(cromozom):

    cromozom = "".join(map(str, cromozom))
    cromozom = int(cromozom, 2)

    rez_formula = (interval[1] - interval[0]) / (
        pow(2, size_crom) - 1
    ) * cromozom + interval[0]

    return rez_formula


# returneaza lista cu toate valorile cromozomilor, trecute prin functia de fitness
def get_all_values(populatie):
    return [func(val_coded(ch)) for ch in populatie]


# print cromozom (baza 2)
def pr_crom(lst):
    return "".join(map(str, lst))


# afiseaza populatia
def print_population(populatie):
    if contor_it == 1:
        for i in range(0, len(populatie)):
            x = val_coded(populatie[i])
            fout.write(
                str(i + 1)
                + ": "
                + pr_crom(populatie[i])
                + ", x ="
                + str(x)
                + ", f(x) = "
                + str(func(x))
                + "\n"
            )

        fout.write("\n\n")
    return


# returneaza array cu prob de selectie
def get_prob_selectie(populatie):

    valori_cromozomi = get_all_values(populatie)
    coef_F = sum(valori_cromozomi)
    list_temp = []
    for f_x in valori_cromozomi:
        list_temp.append(f_x / coef_F)

    if contor_it == 1:
        fout.write("Probabilitati selectie:\n")
        for i in range(1, pop_size + 1):
            fout.write(
                "Cromozom "
                + str(i)
                + " -> probabilitate: "
                + str(list_temp[i - 1])
                + "\n"
            )
        fout.write("\n\n")
    return list_temp


# selectie_proportionala
def selection_f(prob_selectie):
    list_temp = []
    s = 0
    for p in prob_selectie:
        list_temp.append(s)
        s += p
    list_temp.append(1.0)

    if contor_it == 1:
        fout.write("Intervale probabilitati selectie:\n")
        for t in list_temp:
            fout.write(str(t) + "\n")
        fout.write("\n\n")
    return list_temp


def metoda_selectie():
    pop = []
    for i in range(0, pop_size):
        cz_ind_rand = random.randint(0, pop_size - 1)
        pop.append(copy.deepcopy(populatie[cz_ind_rand]))
        if contor_it == 1:
            fout.write(" selectam cromozomul " + str(cz_ind_rand) + "\n")

    return pop


# functie alegere crossover
def get_crossover_candidati_cz(populatie, p_recombinare):
    list_temp = []
    for i in range(1, pop_size + 1):
        u = random.random()
        msg = str(i) + ": " + pr_crom(populatie[i - 1]) + ", u=" + str(u)
        if u < p_recombinare:
            list_temp.append(i - 1)
            msg += " < " + str(p_recombinare) + " participa"
        if contor_it == 1:
            fout.write(msg + "\n")
    return list_temp


# functie crossover
def crossover(candidati_cz):
    fout.write("\n")
    rezultat_1 = []
    rezultat_2 = []
    while len(candidati_cz) >= 2:
        # alegere 2 cromozomi
        sample = random.sample(candidati_cz, 2)
        candidati_cz.remove(sample[0])
        candidati_cz.remove(sample[1])

        # alegere punct rupere
        pct_rupere = random.randrange(0, size_crom)
        if contor_it == 1:
            fout.write(
                "Recombinare dintre cromozomul "
                + str(sample[0] + 1)
                + " cu cromozomul "
                + str(sample[1] + 1)
                + ":\n"
            )
            fout.write(
                str(pr_crom(populatie_noua[sample[0]]))
                + "\n"
                + str(pr_crom(populatie_noua[sample[1]]))
                + "\ncu punct rupere= "
                + str(pct_rupere)
                + "\n"
            )

        # combinare dupa rupere
        rezultat_1 = (
            populatie_noua[sample[0]][:pct_rupere]
            + populatie_noua[sample[1]][pct_rupere:]
        )
        rezultat_2 = (
            populatie_noua[sample[1]][:pct_rupere]
            + populatie_noua[sample[0]][pct_rupere:]
        )

        if contor_it == 1:
            fout.write(
                "Rezultat:\n"
                + str(pr_crom(rezultat_1))
                + "\n"
                + str(pr_crom(rezultat_2))
                + "\n\n"
            )
        populatie_noua[sample[0]] = rezultat_1
        populatie_noua[sample[1]] = rezultat_2
    return


def mutatie_tip_1():
    if contor_it == 1:
        fout.write(
            "\nProbabilitatea de mutatie "
            + str(p_mutatie)
            + " :\nAu fost modificati cromozomii:\n"
        )
    for i in range(pop_size - 1):

        for j in range(len(populatie_noua[i])):
            u = random.random()
            if u < p_mutatie:
                if contor_it == 1:
                    fout.write(str(i + 1) + " ")
                populatie_noua[i][j] = abs(populatie_noua[i][j] - 1)

    if contor_it == 1:
        fout.write("\n")
    return


def mutatie_tip_2():
    if contor_it == 1:
        fout.write(
            "\nProbabilitatea de mutatie"
            + str(p_mutatie)
            + ":\nAu fost modificati cromozomii:\n"
        )
    for i in range(pop_size - 1):
        u = random.random()

        if u < p_mutatie:
            if contor_it == 1:
                fout.write(str(i + 1) + " ")

            poz = random.randrange(0, size_crom - 1)
            populatie_noua[i][poz] = abs(populatie_noua[i][poz] - 1)


# index pentru fitness minim si maxim
def get__min_max_fit(populatie):
    ind_max = 0
    ind_min = 0
    maxx = func(val_coded(populatie[0]))
    minn = func(val_coded(populatie[0]))
    for i in range(len(populatie)):
        f_x = func(val_coded(populatie[i]))
        if f_x > maxx:
            ind_max = i
            maxx = f_x
        if minn > f_x:
            ind_min = i
            minn = f_x
    return (ind_min, ind_max)


# cel mai bun cz se pastreaza
def criteriu_elitist():
    ind_fittest_old_pop = get__min_max_fit(populatie)[1]
    ind_least_fit_populatie_noua = get__min_max_fit(populatie_noua)[0]

    populatie_noua[ind_least_fit_populatie_noua] = copy.deepcopy(
        populatie[ind_fittest_old_pop]
    )


# calculare maxim functie
def calc_max():
    mxm = val_coded(populatie_noua[get__min_max_fit(populatie_noua)[1]])
    fout.write("x= " + str(mxm) + ", f(x)= " + str(func(mxm)))
    x_plot.append(mxm)
    y_plot.append(func(mxm))


def grafic_maxim():
    # Grafic maxim
    plt.rcParams["figure.figsize"] = [7, 7]
    plt.rcParams["figure.autolayout"] = True
    plt.xlim(interval[0] - 1, interval[1] + 1)
    plt.ylim(min(y_plot) - 1, max(y_plot) + 1)
    plt.grid()
    plt.scatter(x_plot, y_plot)
    plt.show()


# MAIN

fout = open("Evolutie.txt", "w")
with open("input.txt") as f:
    lines = f.read().splitlines()

pop_size = int(lines[0])
interval = [int(x) for x in lines[1].split()]
coef_func = [int(x) for x in lines[2].split()]
precizie = int(lines[3])
p_recombinare = float(lines[4])
p_mutatie = float(lines[5])
nr_etape = int(lines[6])
contor_it = 1

x_plot = []
y_plot = []

size_crom = math.floor(
    math.log((interval[1] - interval[0]) * (math.pow(10, precizie)), 2)
)

print("Waiting for the new population...")

populatie = generate_population()
fout.write("Populatia initiala:\n")
print_population(populatie)


for contor_it in range(1, nr_etape + 1):
    print("Step " + str(contor_it) + " status - STARTED!")

    prob_selectie = get_prob_selectie(populatie)

    intervale_selectie = selection_f(prob_selectie)

    populatie_noua = metoda_selectie()

    if contor_it == 1:
        fout.write("\nDupa selectie:\n")
        print_population(populatie_noua)

    index_cr_incrucisare = get_crossover_candidati_cz(populatie_noua, p_recombinare)

    crossover(index_cr_incrucisare)

    if contor_it == 1:
        fout.write("\nDupa recombinare:\n")
        print_population(populatie_noua)

    rand_mutatie = random.randint(0, 1)
    if rand_mutatie == 1:
        mutatie_tip_2()
    else:
        mutatie_tip_1()
    if contor_it == 1:
        fout.write("Dupa mutatie: \n")
        print_population(populatie_noua)

    criteriu_elitist()

    if contor_it == 1:
        fout.write("Dupa criteriul elitist: \n")
        print_population(populatie_noua)

    if contor_it == 1:
        fout.write("Evolutia maximului: \n")
    calc_max()

    populatie = copy.deepcopy(populatie_noua)

    print("Step " + str(contor_it) + " status - DONE!")

grafic_maxim()
print("Finished!")
