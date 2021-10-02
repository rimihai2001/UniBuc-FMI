#include <bits/stdc++.h>

using namespace std;



class Persoana
{
    static int nrpers;
    int id;
    string nume;
public:
    Persoana();
    Persoana(int);
    Persoana(string);
    Persoana(int,string);
    Persoana(const Persoana&);
    ~Persoana();
    Persoana& operator= (Persoana&);
    virtual void afisare();
    virtual string afisnume()
    {
        return nume;
    };
    static int afisarenumarpersoane()
    {
        return nrpers;
    };

    friend istream& operator>>(istream &, Persoana&);
    friend ostream& operator<<(ostream &, Persoana&);
};


class Abonat: public Persoana
{
    static int nrabonati;
    string nr_telefon;
public:
    Abonat();
    Abonat(string);
    Abonat (const Abonat&);
    ///Abonat(const Abonat& ob):Persoana(ob){}; constructor parametrizat cu referinta la clasa de baza
    ~Abonat();
    Abonat& operator= (Abonat&);
    virtual void afisare();
    friend istream& operator>>(istream&, Abonat&);
    friend ostream& operator<<(ostream&, Abonat&);
};


class Abonat_Skype: public Abonat
{
    static int nrabonati_Skype;
    string id_skype;
public:
    Abonat_Skype();
    Abonat_Skype(string);
    Abonat_Skype (const Abonat_Skype&);
    ~Abonat_Skype();
    Abonat_Skype& operator= (Abonat_Skype&);
    virtual void afisare();
    friend istream& operator>>(istream&, Abonat_Skype&);
    friend ostream& operator<<(ostream&, Abonat_Skype&);
};



class Abonat_Skype_Romania: public Abonat_Skype
{
    static int nrabonati_Skype_Romania;
    string adresa_mail;
public:
    Abonat_Skype_Romania();
    Abonat_Skype_Romania(string);
    Abonat_Skype_Romania(const Abonat_Skype_Romania&);
    ~Abonat_Skype_Romania();
    Abonat_Skype_Romania& operator= (Abonat_Skype_Romania&);
    virtual void afisare();
    friend istream& operator>>(istream&, Abonat_Skype_Romania&);
    friend ostream& operator<<(ostream&, Abonat_Skype_Romania&);
};


class Abonat_Skype_Extern: public Abonat_Skype
{
    static int nrabonati_Skype_Extern;
    string tara;
public:
    Abonat_Skype_Extern();
    Abonat_Skype_Extern(string);
    Abonat_Skype_Extern (const Abonat_Skype_Extern&);
    ~Abonat_Skype_Extern();
    Abonat_Skype_Extern& operator= (Abonat_Skype_Extern&);
    virtual void afisare();
    friend istream& operator>>(istream&, Abonat_Skype_Extern&);
    friend ostream& operator<<(ostream&, Abonat_Skype_Extern&);
};

class Agenda: public Persoana
{
    vector<Persoana*>Contacte_Persoana;
    vector<Abonat*>Contacte_Abonat;
    vector<Abonat_Skype*>Contacte_Abonat_Skype;
    vector<Abonat_Skype*>Contacte_Abonat_Skype_Tip;

public:
    Agenda() {};
    Agenda(int);
    Agenda (const Agenda&);
    ~Agenda() {};
    Agenda& operator=(Agenda&);
    friend istream& operator>>(istream&, Agenda&);
    friend ostream& operator<<(ostream&, Agenda&);
    void Add_Persoana(Agenda &a);
    void Afisare_Persoana(int);
    void Add_Abonat(Agenda &a);
    void Afisare_Abonat(int);
    void Add_Abonat_Skype(Agenda &a);
    void Afisare_Abonat_Skype(int);
    void Add_Abonat_Skype_Romania(Agenda &a);
    void Afisare_Abonat_Skype_Romania(int);
    void Add_Abonat_Skype_Extern(Agenda &a);
    void Afisare_Abonat_Skype_Extern(int);
    Persoana*& operator[](string);
};

Agenda a;

int Persoana::nrpers;
int Abonat::nrabonati;
int Abonat_Skype::nrabonati_Skype;
int Abonat_Skype_Extern::nrabonati_Skype_Extern;
int Abonat_Skype_Romania::nrabonati_Skype_Romania;

Persoana::Persoana()
{
    id=0;
    nume="necunoscut";
    nrpers++;
}

Persoana::Persoana(int x)
{
    id=x;
    nume="necunoscut";
    nrpers++;
}

Persoana::Persoana(string s)
{
    id=0;
    nume=s;
    nrpers++;
}

Persoana::Persoana(int x, string s)
{
    id=x;
    nume=s;
    nrpers++;
}

Persoana::Persoana(const Persoana& ob)
{
    id=ob.id;
    nume=ob.nume;
    nrpers++;
}

Persoana::~Persoana() {}

Persoana& Persoana::operator= (Persoana& ob)
{
    if (this != &ob)
    {
        id = ob.id;
        nume = ob.nume;
    }
    return *this;
}

void Persoana::afisare()
{
    cout<<"ID: ";
    cout<<id<<endl<<"Nume: "<<nume<<endl;
}

istream& operator>>(istream& in, Persoana& ob)
{
    in>>ob.id>>ob.nume;
    return in;
}

ostream& operator<<(ostream& out, Persoana& ob)
{
    out<<ob.id<<ob.nume;
    return out;
}

Abonat::Abonat()
{
    nr_telefon="necunoscut";
    nrabonati++;
}

Abonat::Abonat(string s)
{
    nr_telefon=s;
    nrabonati++;
}

Abonat::Abonat(const Abonat&ob)
{
    nr_telefon=ob.nr_telefon;
    nrabonati++;
}

Abonat::~Abonat() {}

Abonat& Abonat::operator=(Abonat &ob)
{
    if (this != &ob)
    {
        nr_telefon=ob.nr_telefon;
    }
    return *this;
}

void Abonat::afisare()
{
    cout<<"Numar Telefon: ";
    cout<<nr_telefon<<endl;
}

istream& operator>> (istream &in, Abonat &ob)
{
    in>>ob.nr_telefon;
    return in;
}

ostream& operator<< (ostream &out, Abonat &ob)
{
    out<<ob.nr_telefon;
    return out;
}


Abonat_Skype::Abonat_Skype()
{
    id_skype="necunoscut";
    nrabonati_Skype++;
}

Abonat_Skype::Abonat_Skype(string s)
{
    id_skype=s;
    nrabonati_Skype++;
}

Abonat_Skype::Abonat_Skype(const Abonat_Skype &ob)
{
    id_skype=ob.id_skype;
    nrabonati_Skype++;

}

Abonat_Skype::~Abonat_Skype() {}

Abonat_Skype& Abonat_Skype::operator=(Abonat_Skype &ob)
{
    if (this != &ob)
    {
        id_skype=ob.id_skype;
    }
    return *this;
}

void Abonat_Skype::afisare()
{
    cout<<"ID Skype: ";
    cout<<id_skype<<endl;
}

istream& operator>> (istream &in, Abonat_Skype &ob)
{
    in>>ob.id_skype;
    return in;
}

ostream& operator<< (ostream &out, Abonat_Skype &ob)
{
    out<<ob.id_skype;
    return out;
}

Abonat_Skype_Romania::Abonat_Skype_Romania()
{
    adresa_mail="necunoscut";
    nrabonati_Skype_Romania++;
}

Abonat_Skype_Romania::Abonat_Skype_Romania(string s)
{
    adresa_mail=s;
    nrabonati_Skype_Romania++;
}

Abonat_Skype_Romania::Abonat_Skype_Romania(const Abonat_Skype_Romania &ob)
{
    adresa_mail=ob.adresa_mail;
    nrabonati_Skype_Romania++;
}

Abonat_Skype_Romania::~Abonat_Skype_Romania() {}


Abonat_Skype_Romania& Abonat_Skype_Romania::operator=(Abonat_Skype_Romania &ob)
{
    if (this != &ob)
    {
        adresa_mail=ob.adresa_mail;
    }
    return *this;
}

void Abonat_Skype_Romania::afisare()
{
    cout<<"Adresa Mail: ";
    cout<<adresa_mail<<endl;
}

istream& operator>> (istream &in, Abonat_Skype_Romania &ob)
{
    in>>ob.adresa_mail;
    return in;
}

ostream& operator<< (ostream &out, Abonat_Skype_Romania &ob)
{
    out<<ob.adresa_mail;
    return out;
}

Abonat_Skype_Extern::Abonat_Skype_Extern()
{
    tara="necunoscut";
    nrabonati_Skype_Extern++;
}

Abonat_Skype_Extern::Abonat_Skype_Extern(string s)
{
    tara=s;
    nrabonati_Skype_Extern++;
}

Abonat_Skype_Extern::Abonat_Skype_Extern(const Abonat_Skype_Extern &ob)
{
    tara=ob.tara;
    nrabonati_Skype_Extern++;
}

Abonat_Skype_Extern::~Abonat_Skype_Extern() {}

Abonat_Skype_Extern& Abonat_Skype_Extern::operator=(Abonat_Skype_Extern &ob)
{
    if (this != &ob)
    {
        tara=ob.tara;
    }
    return *this;
}

void Abonat_Skype_Extern::afisare()
{
    cout<<"Tara: ";
    cout<<tara<<endl;
}

istream& operator>> (istream &in, Abonat_Skype_Extern &ob)
{
    in>>ob.tara;
    return in;
}

ostream& operator<< (ostream &out, Abonat_Skype_Extern &ob)
{
    out<<ob.tara;
    return out;
}

void Agenda::Add_Persoana(Agenda &a)
{
    int id_p;
    string nume_p;
    cout<<"ID: ";
    cin>>id_p;
    cout<<"Nume: ";
    cin>>nume_p;
    Persoana *p = new Persoana(id_p,nume_p);
    a.Contacte_Persoana.push_back(p);
}

void Agenda::Afisare_Persoana(int x)
{
    Contacte_Persoana[x]->afisare();
}

void Agenda::Add_Abonat(Agenda &a)
{
    string s;
    cout<<"Numar Telefon: ";
    cin>>s;
    Abonat *p = new Abonat(s);
    a.Contacte_Abonat.push_back(p);
}

void Agenda::Afisare_Abonat(int x)
{
    Contacte_Abonat[x]->afisare();
}

void Agenda::Add_Abonat_Skype(Agenda &a)
{
    string s;
    cout<<"ID Skype: ";
    cin>>s;
    Abonat_Skype *p = new Abonat_Skype(s);
    a.Contacte_Abonat_Skype.push_back(p);
}

void Agenda::Afisare_Abonat_Skype(int x)
{
    Contacte_Abonat_Skype[x]->afisare();
}

void Agenda::Add_Abonat_Skype_Romania(Agenda &a)
{
    string s;
    cout<<"Adresa Mail: ";
    cin>>s;
    Abonat_Skype *p = new Abonat_Skype_Romania(s);
    a.Contacte_Abonat_Skype_Tip.push_back(p);
}

void Agenda::Afisare_Abonat_Skype_Romania(int x)
{
    Contacte_Abonat_Skype_Tip[x]->afisare(); ///upcasting si functii virtuale
}

void Agenda::Add_Abonat_Skype_Extern(Agenda &a)
{
    string s;
    cout<<"Tara: ";
    cin>>s;
    Abonat_Skype *p = new Abonat_Skype_Extern(s); ///downcasting
    a.Contacte_Abonat_Skype_Tip.push_back(p);
}

void Agenda::Afisare_Abonat_Skype_Extern(int x)
{
    Contacte_Abonat_Skype_Tip[x]->afisare();
}

Agenda::Agenda(int x)
{
    int numar=x;
}

Agenda::Agenda(const Agenda& ob)
{
    Contacte_Abonat=ob.Contacte_Abonat;
    Contacte_Abonat_Skype=ob.Contacte_Abonat_Skype;
    Contacte_Abonat_Skype_Tip=ob.Contacte_Abonat_Skype_Tip;
    Contacte_Persoana=ob.Contacte_Persoana;
}

Agenda& Agenda::operator= (Agenda& ob)
{
    if (this != &ob)
    {
        Contacte_Abonat=ob.Contacte_Abonat;
        Contacte_Abonat_Skype=ob.Contacte_Abonat_Skype;
        Contacte_Abonat_Skype_Tip=ob.Contacte_Abonat_Skype_Tip;
        Contacte_Persoana=ob.Contacte_Persoana;
    }
    return *this;
}

istream& operator>>(istream& in, Agenda& ob)
{
    int nr;
    cout<<"Cititi numarul de abonati:";
    cin>>nr;
    for(int i=1; i<=nr; i++)
    {
        cout<<"Abonatul "<<i<<": "<<endl;
        cout<<"Persoana (id, nume): "<<endl;
        a.Agenda::Add_Persoana(a);
        cout<<"Abonat (Numar Telefon): "<<endl;
        a.Agenda::Add_Abonat(a);
        cout<<"Abonat Skype (ID Skype): "<<endl;
        a.Agenda::Add_Abonat_Skype(a);
        cout<<"Care este tipul abonatului?"<<endl;
        cout<<"1. Romania"<<endl;
        cout<<"2. Extern"<<endl;
        cout<<"Selectati tipul:"<<endl;
        int alegere;
        cin>>alegere;
        if(alegere==1)
        {
            cout<<"Abonat Skype Romania (Adresa Mail): "<<endl;
            a.Agenda::Add_Abonat_Skype_Romania(a);
        }
        if(alegere==2)
        {
            cout<<"Abonat Skype Extern (Tara): "<<endl;
            a.Agenda::Add_Abonat_Skype_Extern(a);
        }
    }
}

ostream& operator<<(ostream& os, Agenda& ob)
{
    for(int i=0; i<ob.Contacte_Persoana.size(); i++)
            {
                cout<<"Abonatul "<<i+1<<": "<<endl;
                a.Agenda::Afisare_Persoana(i);
                a.Agenda::Afisare_Abonat(i);
                a.Agenda::Afisare_Abonat_Skype(i);
                a.Agenda::Afisare_Abonat_Skype_Romania(i);
            }
}

Persoana*& Agenda:: operator[](string index)
{
    int poz=-1;
    for(int i=0; i<Contacte_Persoana.size(); i++)
    {
        if(Contacte_Persoana[i]->afisnume() == index)
            poz=i;
    }
    if(poz == -1)
    {
        cout<<"Persoana nu este abonata.";
    }
    else
    {
        a.Agenda::Afisare_Persoana(poz);
        a.Agenda::Afisare_Abonat(poz);
        a.Agenda::Afisare_Abonat_Skype(poz);
        a.Agenda::Afisare_Abonat_Skype_Romania(poz);
    }
};

int main()
{
    int ok=1,MenuIndex;
    int n;
    cout<<"Introduceti numarul de abonati:";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"Abonatul "<<i<<": "<<endl;
        cout<<"Persoana (id, nume): "<<endl;
        a.Agenda::Add_Persoana(a);
        cout<<"Abonat (Numar Telefon): "<<endl;
        a.Agenda::Add_Abonat(a);
        cout<<"Abonat Skype (ID Skype): "<<endl;
        a.Agenda::Add_Abonat_Skype(a);
        cout<<"Care este tipul abonatului?"<<endl;
        cout<<"1. Romania"<<endl;
        cout<<"2. Extern"<<endl;
        cout<<"Selectati tipul:"<<endl;
        int alegere;
        cin>>alegere;
        if(alegere==1)
        {
            cout<<"Abonat Skype Romania (Adresa Mail): "<<endl;
            a.Agenda::Add_Abonat_Skype_Romania(a);
        }
        else if(alegere==2)
        {
            cout<<"Abonat Skype Extern (Tara): "<<endl;
            a.Agenda::Add_Abonat_Skype_Extern(a);
        }
        else
        {
            cout<<"Date incorecte. Aplicatia se inchide!"<<endl;
            ok=0;
            break;
        }
    }
    while(ok==1)
    {
        cout<<endl<<endl;
        cout<<"Meniu: "<<endl;
        cout<<"1.Adaugare abonat"<<endl;
        cout<<"2.Afisare lista"<<endl;
        cout<<"3.Cautare dupa nume"<<endl;
        cout<<"4.Afisare numar contacte"<<endl;
        cout<<"5.Downcasting"<<endl;
        cout<<"6.Upcasting"<<endl;
        cout<<"7.Iesire"<<endl;
        cout<<"SELECTATI OPTIUNEA: ";
        cin>>MenuIndex;
        cout<<endl;
        switch(MenuIndex)
        {
        case 1:
            cout<<"Abonatul nou"<<": "<<endl;
            cout<<"Persoana (id, nume): "<<endl;
            a.Agenda::Add_Persoana(a);
            cout<<"Abonat (Numar Telefon): "<<endl;
            a.Agenda::Add_Abonat(a);
            cout<<"Abonat Skype (ID Skype): "<<endl;
            a.Agenda::Add_Abonat_Skype(a);
            cout<<"Care este tipul abonatului?"<<endl;
            cout<<"1. Romania"<<endl;
            cout<<"2. Extern"<<endl;
            cout<<"Selectati tipul:"<<endl;
            int alegere;
            cin>>alegere;
            if(alegere==1)
            {
                cout<<"Abonat Skype Romania (Adresa Mail): "<<endl;
                a.Agenda::Add_Abonat_Skype_Romania(a);
            }

            if(alegere==2)
            {
                cout<<"Abonat Skype Extern (Tara): "<<endl;
                a.Agenda::Add_Abonat_Skype_Extern(a);
            }
            n++;
            break;
        case 2:
            for(int i=0; i<n; i++)
            {
                cout<<endl;
                cout<<"Abonatul "<<i+1<<": "<<endl;
                a.Agenda::Afisare_Persoana(i);
                a.Agenda::Afisare_Abonat(i);
                a.Agenda::Afisare_Abonat_Skype(i);
                a.Agenda::Afisare_Abonat_Skype_Romania(i);
                cout<<endl;
            }
            break;
        case 3:
        {
            cout<<"Nume abonat: ";
            string nume_cautare;
            cin>>nume_cautare;
            a[nume_cautare];
            cout<<endl;
        }
        break;
        case 4:
            cout<<"Numar contacte: "<<a.afisarenumarpersoane()/4<<endl;
            break;
        case 5:
            cout<<"Se poate regasi downcasting pe linia 456 a codului!"<<endl;
            break;
        case 6:
            cout<<"Se poate regasi upcasting pe linia 448 a codului!"<<endl;
            break;
        case 7:
        {
            cout<<endl;
            cout<<"Aplicatia se inchide. La revedere!"<<endl;
            ok=0;
        }
        break;
        default:
            cout<<endl;
            cout<<"COMANDA INCORECTA. Meniul va reporni!"<<endl;
            break;
        }
        cout<<endl<<endl;
    }
    return 0;
}
