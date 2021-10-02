#include <bits/stdc++.h>
using namespace std;

class Automobil
{
protected:
    static int nrtotaut;
    string zona;
    string dimensiune;
    int nr_usi_auto;
    int nr_max_pers_auto;
    float pret;
public:
    Automobil(string zona = "", string dimensiune = "", float nr_usi_auto = 0, int nr_max_pers_auto = 0, float pret = 0);
    friend bool operator<(const Automobil& a1, const Automobil& a2)
    {
        return(a1.getter_pret_auto() < a2.getter_pret_auto());
    };
    virtual void citire(istream& in)
    {
        cout << "Zona deplasare (oras, drum_lung): ";
        in >> zona;
        cout << "Lungimea masinii: ";
        in >> dimensiune;
        cout << "Numar usi: ";
        in >> nr_usi_auto;
        cout << "Numar maxim persoane: ";
        in >> nr_max_pers_auto;
        cout << "Pret: ";
        in >> pret;
    };
    virtual void afisare(ostream& out) const
    {
        {
            out << "Zona deplasare(oras, drum_lung): " << zona << endl;
            out << "Lungimea masinii: " << dimensiune << endl;
            out << "Numar usi: " << nr_usi_auto << endl;
            out << "Numar maxim persoane: " << nr_max_pers_auto << endl;
            out << "Pret: " << pret << endl;
        }
    };
    static int getter_nr_total_auto()
    {
        return nrtotaut;
    }
    friend istream& operator>>(istream& in, Automobil& a)
    {
        a.citire(in);
        return in;
    };
    friend ostream& operator<<(ostream& out, const Automobil& a)
    {
        a.afisare(out);
        return out;
    };
    virtual float getter_pret_auto() const
    {
        return pret;
    }
    virtual bool get_tip_auto()const
    {
        return 1;
    };
    ~Automobil()
    {
        nrtotaut--;
    }
};

class Mini : public Automobil
{
    bool sh = true;
public:
    Mini(string zona = "", string dimensiune = "", float nr_usi_auto = 0, int nr_max_pers_auto = 0, float pret = 0);
    friend bool operator ==(Mini& m1, Mini& m2)
    {
        if (m1.zona == m2.zona and m1.dimensiune == m2.dimensiune and m1.nr_usi_auto == m2.nr_usi_auto and m1.nr_max_pers_auto == m2.nr_max_pers_auto and m1.pret == m2.pret)
            return true;
        else
            return false;
    }
    Mini& operator=(Mini& m)
    {
        zona = m.zona;
        dimensiune = m.dimensiune;
        nr_usi_auto = m.nr_usi_auto;
        nr_max_pers_auto = m.nr_max_pers_auto;
        pret = m.pret;
        return *this;
    }
    void citire(istream& in)
    {
        Automobil::citire(in);
    };
    void afisare(ostream& out) const
    {
        Automobil::afisare(out);
    };
    bool get_tip_auto()
    {
        return sh;
    }

    ~Mini() {}
};

class Mica : public Automobil
{
    const bool sh = 0;
public:
    Mica(string zona = "", string dimensiune = "", float nr_usi_auto = 0, int nr_max_pers_auto = 0, float pret = 0);
    friend bool operator ==(Mica& m1, Mica& m2)
    {
        if (m1.zona == m2.zona and m1.dimensiune == m2.dimensiune and m1.nr_usi_auto == m2.nr_usi_auto and m1.nr_max_pers_auto == m2.nr_max_pers_auto and m1.pret == m2.pret)
            return true;
        else
            return false;
    };
    Mica& operator=(Mica& m)
    {
        zona = m.zona;
        dimensiune = m.dimensiune;
        nr_usi_auto = m.nr_usi_auto;
        nr_max_pers_auto = m.nr_max_pers_auto;
        pret = m.pret;
        return *this;
    };
    void citire(istream& in)
    {
        Automobil::citire(in);
    };
    void afisare(ostream& out) const
    {
        Automobil::afisare(out);
    };
    bool get_tip_auto()
    {
        return sh;
    }
    ~Mica() {}
};

template <class T>
class Vanzare
{
    T* stoc_masini;
    T* vandute;
    int nrstoc_masini;
    int nr_auto_vandute;
public:
    Vanzare();
    void addmasina(T& c)
    {
        stoc_masini[nrstoc_masini] = c;
        nrstoc_masini++;
    };
    int get_nr_auto_stoc()
    {
        return nrstoc_masini;
    }
    int getter_nr_auto_vandute()
    {
        return nr_auto_vandute;
    }
    T& operator -=(T& c)
    {
        if (nrstoc_masini == 0)
        {
            cout << "Nu exista masini in stoc! Reporniti programul pentru actualizare!"<<endl;
            exit(EXIT_FAILURE);
        }
        bool ok = false;
        int poz;
        for (int i = 0; i < nrstoc_masini; i++)
            if (stoc_masini[i] == c)
            {
                ok = true;
                poz = i;
            }
        if (ok == false)
        {
            cout << "Nu exista aceasta masina!"<<endl;
        }
        vandute[nr_auto_vandute] = stoc_masini[poz];
        nr_auto_vandute++;
        if(ok)
        {
            for (int i = poz; i < nrstoc_masini; i++)
                stoc_masini[i] = stoc_masini[i + 1];
            nrstoc_masini--;
        }
    };
    void afisare_automobile()
    {
        if (nrstoc_masini == 0)
        {
            cout << "Nu exista masini in stoc! Reporniti programul pentru actualizare!"<<endl<<endl;
            exit(EXIT_FAILURE);

        }
        for (int i = 0; i < nrstoc_masini; i++)
            cout << stoc_masini[i] << endl;
    };
    void afisare_nr_auto_vandute()
    {
        if (nr_auto_vandute == 0)
        {
            cout << "Nu s-au vandut masini!"<<endl<<endl;
            return;
        }
        for (int i = 0; i < nr_auto_vandute; i++)
            cout << vandute[i] << endl;
    };
    ~Vanzare()
    {
        delete[] stoc_masini;
        delete[] vandute;
    };
};

class Compacta : public Automobil
{
    const bool sh = 0;
    string model;
public:
    Compacta(string model = "", string zona = "", string dimensiune = "", float nr_usi_auto = 0, int nr_max_pers_auto = 0, float pret = 0);
    friend bool operator ==(Compacta& m1, Compacta& m2)
    {
        if (m1.model == m2.model and m1.zona == m2.zona and m1.dimensiune == m2.dimensiune and m1.nr_usi_auto == m2.nr_usi_auto and m1.nr_max_pers_auto == m2.nr_max_pers_auto and m1.pret == m2.pret)
            return true;
        else
            return false;
    };
    Compacta& operator=(Compacta& c)
    {

        zona = c.zona;
        dimensiune = c.dimensiune;
        nr_usi_auto = c.nr_usi_auto;
        nr_max_pers_auto = c.nr_max_pers_auto;
        pret = c.pret;
        model = c.model;
        return *this;

    };
    void citire(istream& in)
    {
        Automobil::citire(in);
        cout << "Model: ";
        in >> model;
    };
    bool get_tip_auto()
    {
        return sh;
    }
    string getmodel()
    {
        return model;
    }
    void afisare(ostream& out) const
    {
        Automobil::afisare(out);
        cout << "Model: ";
        out << model << endl;
    };
    ~Compacta() {}
};

class Monovolum : public Automobil
{
    vector <pair<int, int> > ziluna;
    int nrziluna;
    int anfabricat;
    int anachizitie;
    int ziactuala;
    int lunaactuala;
    bool sh;
public:
    Monovolum(int anfabricat = 0, int anachizitie = 0, int ziactuala = 0, int lunaactuala = 0, bool sh = true, string zona = "", string dimensiune = "", float nr_usi_auto = 0, int nr_max_pers_auto = 0, float pret = 0);
    friend bool operator ==(Monovolum& m1, Monovolum& m2)
    {

        if (m1.anfabricat == m2.anfabricat and m1.zona == m2.zona and m1.dimensiune == m2.dimensiune and m1.nr_usi_auto == m2.nr_usi_auto and m1.nr_max_pers_auto == m2.nr_max_pers_auto and m1.pret == m2.pret)
            return true;
        return false;

    };
    Monovolum& operator=(Monovolum& m)
    {

        zona = m.zona;
        dimensiune = m.dimensiune;
        nr_usi_auto = m.nr_usi_auto;
        nr_max_pers_auto = m.nr_max_pers_auto;
        pret = m.pret;
        nrziluna = m.nrziluna;
        anfabricat = m.anfabricat;
        anachizitie = m.anachizitie;
        ziactuala = m.ziactuala;
        lunaactuala = m.lunaactuala;
        sh = m.sh;
        for (int i = 0; i < ziluna.size(); i++)
            ziluna[i] = m.ziluna[i];
        return *this;

    };
    void citire(istream& in)
    {
        Automobil::citire(in);
        cout << "Reducerea(Nr. zile, Nr. Luni, Zilele, Lunile): ";
        in >> nrziluna;
        int zi, luna;
        for (int i = 0; i < nrziluna; i++)
        {

            in >> zi >> luna;
            if (luna<6 or luna>8)
            {
                cout << "Data nu a fost corect introdusa";
                exit(EXIT_FAILURE);
            }
            else if (zi>31 or zi<1)
            {
                cout << "Data nu a fost corect introdusa";
                exit(EXIT_FAILURE);
            }
            else if(luna==6 and zi>30)
            {
                cout << "Data nu a fost corect introdusa";
                exit(EXIT_FAILURE);
            }
            ziluna.push_back({zi, luna});
        }
        cout << "Anul fabricatiei: ";
        in >> anfabricat;
        cout << "Anul achizitionarii: ";
        in >> anachizitie;
        cout << "Ziua achizitionarii: ";
        in >> ziactuala;
        cout << "Luna achizitionarii: ";
        in >> lunaactuala;
        cout << "Second hand? (1 - DA / 0 - NU): ";
        int aux;
        in >> aux;
        if (aux == 1)
            sh = true;
        if (aux == 0)
            sh = false;
        if (sh == true)
        {
            int reducerezilevara = 0;
            for (int i = 0; i < ziluna.size(); i++)
            {
                if (ziluna[i].first == ziactuala and ziluna[i].second == lunaactuala)
                    reducerezilevara = 10/100*pret;
            }
            pret = pret - reducerezilevara;
        }
    };
    void afisare(ostream& out) const
    {
        {
            out << "Zona recomandata pentru deplasare: " << zona << '\n';
            out << "Lungimea masinii: " << dimensiune << '\n';
            out << "Numar usi: " << nr_usi_auto << '\n';
            out << "Numar maxim persoane: " << nr_max_pers_auto << '\n';
            out << "Pretul: " << pret << '\n';
            out << "Anul fabricarii: " << anfabricat << '\n';
        }
    };
    bool get_tip_auto()
    {
        return sh;
    }
    ~Monovolum() {}
};

template<>
class Vanzare<Monovolum>
{
    Monovolum* stoc_masini;
    Monovolum* vandute;
    int nrstoc_masini;
    int nr_auto_vandute;
    int numar_masini_monovolum_sh;
public:
    Vanzare()
    {
        nrstoc_masini = 0;
        nr_auto_vandute = 0;
        numar_masini_monovolum_sh = 0;
        stoc_masini = new Monovolum[101];
        vandute = new Monovolum[101];
    };
    void addmasina(Monovolum& c)
    {
        stoc_masini[nrstoc_masini] = c;
        nrstoc_masini=nrstoc_masini+1;
        if (c.get_tip_auto() == true)
            numar_masini_monovolum_sh++;
    };
    int get_nr_auto_stoc()
    {
        return nrstoc_masini;
    }
    int getter_nr_auto_vandute()
    {
        return nr_auto_vandute;
    }
    int get_numar_auto_monovolum_sh()
    {
        return numar_masini_monovolum_sh;
    }
    Monovolum& operator -=(Monovolum& c)
    {
        if (nrstoc_masini == 0)
        {
            cout << "Nu exista o masina de acest tip cu caracteristicile introduse"<<endl;
        }
        bool ok = false;
        int poz;
        for (int i = 0; i < nrstoc_masini; i++)
            if (stoc_masini[i] == c)
            {
                ok = true;
                poz = i;
            }
        if (ok == false)
        {
            cout << "Nu exista o masina de acest tip cu caracteristicile introduse"<<endl;
        }
        if (stoc_masini[poz].get_tip_auto() == true)
            numar_masini_monovolum_sh--;
        vandute[nr_auto_vandute] = stoc_masini[poz];
        nr_auto_vandute=nr_auto_vandute+1;
        if (ok == true)
        {
            for (int i = poz; i < nrstoc_masini; i++)
                stoc_masini[i] = stoc_masini[i + 1];
            nrstoc_masini=nrstoc_masini-1;
        }
        else
        {
            cout << "Nu exista o masina de acest tip cu caracteristicile introduse"<<endl;
        }
    };
    void afisare_automobile()
    {
        if (nrstoc_masini == 0)
        {
            cout << "Nu exista masini in stoc!"<<endl;
            return;
        }
        for (int i = 0; i < nrstoc_masini; i++)
            cout << stoc_masini[i] << endl;
    };
    void afisare_nr_auto_vandute()
    {
        if (nr_auto_vandute == 0)
        {
            cout << "Nu exista masini vandute!"<<endl;
            return;
        }
        for (int i = 0; i < nr_auto_vandute; i++)
            cout << vandute[i] << endl;
    };
    ~Vanzare()
    {
        delete[] stoc_masini;
        delete[] vandute;
    };

};

int Automobil::nrtotaut = 0;
Automobil::Automobil(string zona, string dimensiune, float nr_usi_auto, int nr_max_pers_auto, float pret) :zona(zona), dimensiune(dimensiune), nr_usi_auto(nr_usi_auto), nr_max_pers_auto(nr_max_pers_auto), pret(pret)
{
    nrtotaut++;
}

Mini::Mini(string zona, string dimensiune, float nr_usi_auto, int nr_max_pers_auto, float pret) :Automobil(zona, dimensiune, nr_usi_auto, nr_max_pers_auto, pret)
{
}

Mica::Mica(string zona, string dimensiune, float nr_usi_auto, int nr_max_pers_auto, float pret) :Automobil(zona, dimensiune, nr_usi_auto, nr_max_pers_auto, pret)
{
}

Compacta::Compacta(string model, string zona, string dimensiune, float nr_usi_auto, int nr_max_pers_auto, float pret) :Automobil(zona, dimensiune, nr_usi_auto, nr_max_pers_auto, pret), model(model)
{
}

Monovolum::Monovolum(int anfabricat, int anachizitie, int ziactuala, int lunaactuala, bool sh, string zona, string dimensiune, float nr_usi_auto, int nr_max_pers_auto, float pret) :Automobil(zona, dimensiune, nr_usi_auto, nr_max_pers_auto, pret), anfabricat(anfabricat), anachizitie(anachizitie), lunaactuala(lunaactuala), ziactuala(ziactuala), sh(sh)
{
}

template<class T>
Vanzare<T>::Vanzare()
{
    nrstoc_masini = 0;
    nr_auto_vandute = 0;
    stoc_masini = new T[101];
    vandute = new T[101];
}


int main()
{
    int n,ok=1,meniu_optiune;

    set<pair<Automobil*, bool>> stoc_masini;
    set<pair<Automobil*, bool>>::iterator it;

    Automobil** v;
    Vanzare<Mini> stoc_masiniMini;
    Vanzare<Mica> stoc_masiniMica;
    Vanzare<Compacta> stoc_masiniCompacta;
    Vanzare<Monovolum> stoc_masiniMonovolum;

    while (ok==1)
    {
        cout << "MENIU"<<endl<<endl;
        cout << "1: Adauga masina Mini"<<endl;
        cout << "2: Adauga masina Mica"<<endl;
        cout << "3: Adauga masina Compacta"<<endl;
        cout << "4: Adauga masina Monovolum"<<endl;
        cout << "5: Vinde masina Mini"<<endl;
        cout << "6: Vinde masina Mica"<<endl;
        cout << "7: Vinde masina Compacta"<<endl;
        cout << "8: Vinde masina Monovolum"<<endl;
        cout << "9: Numar masini in stoc (pe tipuri de masina)"<<endl;
        cout << "10: Vezi masini in stoc (pe tipuri de masina)"<<endl;
        cout << "11: Numar masini vandute (pe tipuri de masina)"<<endl;
        cout << "12: Vezi masinile vandute (pe tipuri de masina)"<<endl;
        cout << "13: Numar de masini de tip Monovolum (noi si second-hand)"<<endl;
        cout << "14: Citire, stocare locala si afisare a n masini"<<endl;
        cout << "0: OPRIRE APLICATIE"<<endl<<endl;
        cout << endl<<"Operatiunea: ";
        cin >> meniu_optiune;
        switch(meniu_optiune)
        {
        case 0:
        {
            ok=0;
            cout<<"Programul se va inchide! O zi buna!"<<endl;
        }
        break;
        case 1:
        {
            Mini newMini;
            cin >> newMini;
            stoc_masiniMini.addmasina(newMini);
        }
        break;
        case 2:
        {
            Mica newMica;
            cin >> newMica;
            stoc_masiniMica.addmasina(newMica);
        }
        break;
        case 3:
        {
            Compacta newCompacta;
            cin >> newCompacta;
            stoc_masiniCompacta.addmasina(newCompacta);
        }
        break;
        case 4:
        {
            Monovolum newMonovolum;
            cin >> newMonovolum;
            stoc_masiniMonovolum.addmasina(newMonovolum);
        }
        break;
        case 5:
        {
            cout << "Caracteristicile masinii Mini cautate:"<<endl;
            Mini cumpMini;
            cin >> cumpMini;
            stoc_masiniMini -= cumpMini;
        }
        break;
        case 6:
        {
            cout << "Caracteristicile masinii Mici cautate:"<<endl;
            Mica cumpMica;
            cin >> cumpMica;
            stoc_masiniMica -= cumpMica;
        }
        break;
        case 7:
        {
            cout << "Caracteristicile masinii Compacte cautate:"<<endl;
            Compacta cumpCompacta;
            cin >> cumpCompacta;
            stoc_masiniCompacta -= cumpCompacta;
        }
        break;
        case 8:
        {
            cout << "Caracteristicile masinii Monovolum cautate:"<<endl;
            Monovolum cumpMonovolum;
            cin >> cumpMonovolum;
            stoc_masiniMonovolum -= cumpMonovolum;
        }
        break;
        case 9:
        {
            cout << "In stoc sunt " << stoc_masiniMini.get_nr_auto_stoc() << " masini Mini"<<endl;
            cout << "In stoc sunt " << stoc_masiniMica.get_nr_auto_stoc() << " masini Mici"<<endl;
            cout << "In stoc sunt " << stoc_masiniCompacta.get_nr_auto_stoc() << " masini Compacte"<<endl;
            cout << "In stoc sunt " << stoc_masiniMonovolum.get_nr_auto_stoc() << " masini Monovolume"<<endl;
            cout << "In total sunt in stoc " << stoc_masiniMini.get_nr_auto_stoc() + stoc_masiniMica.get_nr_auto_stoc() + stoc_masiniCompacta.get_nr_auto_stoc() + stoc_masiniMonovolum.get_nr_auto_stoc() << " autoturisme"<<endl;
        }
        break;
        case 10:
        {
            cout << "Masiniile Mini din stoc:"<<endl;
            stoc_masiniMini.afisare_automobile();
            cout << "Masiniile Mici din stoc:"<<endl;
            stoc_masiniMica.afisare_automobile();
            cout << "Masiniile Compacte din stoc:"<<endl;
            stoc_masiniCompacta.afisare_automobile();
            cout << "Masiniile Monovolum din stoc:"<<endl;
            stoc_masiniMonovolum.afisare_automobile();
        }
        break;
        case 11:
        {
            cout << "S-au vandut " << stoc_masiniMini.getter_nr_auto_vandute() << " masini Mini"<<endl;
            cout << "S-au vandut " << stoc_masiniMica.getter_nr_auto_vandute() << " masini Mici"<<endl;
            cout << "S-au vandut " << stoc_masiniCompacta.getter_nr_auto_vandute() << " masini Compacte"<<endl;
            cout << "S-au vandut " << stoc_masiniMonovolum.getter_nr_auto_vandute() << " masini Monovolum"<<endl;
            cout << "In total s-au vandut " << stoc_masiniMini.getter_nr_auto_vandute() + stoc_masiniMica.getter_nr_auto_vandute() + stoc_masiniCompacta.getter_nr_auto_vandute() + stoc_masiniMonovolum.getter_nr_auto_vandute() << " masini"<<endl;
        }
        break;
        case 12:
        {
            cout << "Masiniile mini vandute:"<<endl;
            stoc_masiniMini.afisare_nr_auto_vandute();
            cout << "Masiniile mici vandute:"<<endl;
            stoc_masiniMica.afisare_nr_auto_vandute();
            cout << "Masiniile compacte vandute:"<<endl;
            stoc_masiniCompacta.afisare_nr_auto_vandute();
            cout << "Masiniile compacte vandute:"<<endl;
            stoc_masiniMonovolum.afisare_nr_auto_vandute();
        }
        break;
        case 13:
        {
            cout << "In stoc exista " << stoc_masiniMonovolum.get_nr_auto_stoc() - stoc_masiniMonovolum.get_numar_auto_monovolum_sh() << " Monovolume noi"<<endl;
            cout << "In stoc exista " << stoc_masiniMonovolum.get_numar_auto_monovolum_sh() << " Monovolume second hand"<<endl;
        }
        break;
        case 14:
        {
            cout << "Numarul de autoturisme: ";
            cin >> n;
            v = new Automobil * [n];
            for (int i = 0; i < n; i++)
            {
                string tip;
                cout << "Tipul autoturismului " << i+1 << " (Mini, Mica, Compacta, Monovolum) : ";
                cin >> tip;
                if (tip == "Mini")
                {
                    v[i] = new Mini;
                    cin >> *v[i];
                    stoc_masini.insert({v[i], false});
                }
                else if (tip == "Mica")
                {
                    v[i] = new Mica;
                    cin >> *v[i];
                    stoc_masini.insert({v[i], false});
                }
                else if (tip == "Compacta")
                {
                    v[i] = new Compacta;
                    cin >> *v[i];
                    stoc_masini.insert({v[i], false});
                }
                else if (tip == "Monovolum")
                {
                    v[i] = new Monovolum;
                    cin >> *v[i];
                    stoc_masini.insert({v[i], (*v[i]).get_tip_auto()});
                }
                else
                {
                    cout<<"Date invalide. Programul se va inchide!";
                    return 0;
                }
            }
            cout<<endl;
            for (it = stoc_masini.begin(); it != stoc_masini.end(); it++)
            {
                cout << *(*it).first;
                if ((*it).second==true)
                    cout << "Masina este second hand"<<endl<<endl;
                else if ((*it).second==false)
                    cout << "Masina este noua" <<endl<<endl;
            }
        }
        break;
        default:
            cout << "Optiunea nu exista! Meniul se va reseta!"<<endl<<endl;
            break;
        }
    }
    return 0;
}
