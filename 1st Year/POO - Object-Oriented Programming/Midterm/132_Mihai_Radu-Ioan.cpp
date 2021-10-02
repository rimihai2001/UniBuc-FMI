/*MIHAI Radu-Ioan
Grupa 132
Tutore Laborator: Adriana Ducoffe
Compilator: g++ -std=c++11 CodeBlocks*/


#include <bits/stdc++.h>

using namespace std;

int nr_random; //generare id unic calculator

class malware
{

    string tip_malware;
    float rating;
    int zi_infectare;
    int luna_infectare;
    int an_infectare;
    string nume_malware;
    string metoda_infectare;
    vector <string> registri_afectati;

public:
    void citire();
    void afisare();
    string get_tip_malware()
    {
        return tip_malware;
    };
    friend istream& operator>>(istream &, malware&);
    friend ostream& operator<<(ostream &, malware&);
};

istream& operator>> (istream &in, malware &ob) //supraincarcare operator de citire
{
    cout<<"Tip malware: ";
    in>>ob.tip_malware;
    cout<<endl;
    ob.rating=0;
    cout<<endl;
    cout<<"Data infectare (zi, luna, an): ";
    in>>ob.zi_infectare>>ob.luna_infectare>>ob.an_infectare;
    cout<<endl;
    if(ob.luna_infectare<1 || ob.luna_infectare>12 || ob.zi_infectare<1 || ob.zi_infectare>31) //exceptii si oprirea programului
    {
        cout<<"DATA INVALIDA!!! Programul se va inchide!";
        exit(0);
    }
    cout<<"Nume malware (in cazul in care sunt mai multe cuvinte, sa fie despartite prin _ in loc de spatiu): ";
    in>>ob.nume_malware;
    cout<<endl;
    bool met_inf;
    cout<<"Se cunoaste metoda de infectare? (0-NU, 1-DA) ";
    cin>>met_inf;
    cout<<endl;
    if(met_inf==1)
    {
        cout<<"Metoda infectare: ";
        in>>ob.metoda_infectare;
    }
    else ob.metoda_infectare="unknown";
    cout<<endl;
    cout<<"Cati registri sunt afectati? ";
    int nr_reg;
    cin>>nr_reg;
    for(int i=1; i<=nr_reg; i++)
    {
        cout<<"Registrul "<<i<<": ";
        string r;
        cin>>r;
        ob.registri_afectati.push_back(r);
    }
    return in;
}

ostream& operator<< (ostream &out, malware &ob) //supraincarcare operator de afisare
{
    cout<<"Tip malware: ";
    out<<ob.tip_malware;
    cout<<endl<<endl;;
    cout<<"Rating malware: ";
    out<<ob.rating;
    cout<<endl<<endl;;
    cout<<"Data infectare (zi, luna, an): ";
    out<<ob.zi_infectare<<" "<<ob.luna_infectare<<" "<<ob.an_infectare;
    cout<<endl<<endl;;
    cout<<"Nume malware: ";
    out<<ob.nume_malware;
    cout<<endl<<endl;;
    cout<<"Metoda infectare: ";
    out<<ob.metoda_infectare;
    cout<<endl<<endl;
    cout<<"Registri afectati: ";
    cout<<endl;
    for(int i=0; i<ob.registri_afectati.size(); i++)
    {
        cout<<"Registrul "<<i+1<<": ";
        string r;
        out<<ob.registri_afectati[i];
        cout<<endl;
    }
    return out;
}



void malware::citire()
{
    cout<<"Tip malware: ";
    cin>>tip_malware;
    cout<<endl;
    rating=0;
    cout<<endl;
    cout<<"Data infectare (zi, luna, an): ";
    cin>>zi_infectare>>luna_infectare>>an_infectare;
    cout<<endl;
    if(luna_infectare<1 || luna_infectare>12 || zi_infectare<1 || zi_infectare>31) //exceptii si oprirea programului
    {
        cout<<"DATA INVALIDA!!! Programul se va inchide!";
        exit(0);
    }
    cout<<"Nume malware (in cazul in care sunt mai multe cuvinte, sa fie despartite prin _ in loc de spatiu): ";
    cin>>nume_malware;
    cout<<endl;
    bool met_inf;
    cout<<"Se cunoaste metoda de infectare? (0-NU, 1-DA) ";
    cin>>met_inf;
    cout<<endl;
    if(met_inf==1)
    {
        cout<<"Metoda infectare: ";
        cin>>metoda_infectare;
    }
    else metoda_infectare="unknown";
    cout<<endl;
    cout<<"Cati registri sunt afectati? ";
    int nr_reg;
    cin>>nr_reg;
    for(int i=1; i<=nr_reg; i++)
    {
        cout<<"Registrul "<<i<<": ";
        string r;
        cin>>r;
        registri_afectati.push_back(r);
    }
}
void malware::afisare()
{
    cout<<"Tip malware: ";
    cout<<tip_malware;
    cout<<endl<<endl;;
    cout<<"Rating malware: ";
    cout<<rating;
    cout<<endl<<endl;;
    cout<<"Data infectare (zi, luna, an): ";
    cout<<zi_infectare<<" "<<luna_infectare<<" "<<an_infectare;
    cout<<endl<<endl;;
    cout<<"Nume malware: ";
    cout<<nume_malware;
    cout<<endl<<endl;;
    cout<<"Metoda infectare: ";
    cout<<metoda_infectare;
    cout<<endl<<endl;
    cout<<"Registri afectati: ";
    cout<<endl;
    for(int i=0; i<registri_afectati.size(); i++)
    {
        cout<<"Registrul "<<i+1<<": ";
        string r;
        cout<<registri_afectati[i];
        cout<<endl;
    }
}

class Computer
{

    int id;
    int rating_final;
    vector<malware> lista_malware;
    int nr_malware_inf;

public:
    void citire();
    void afisare();
    int get_nr_malware_inf()
    {
        return nr_malware_inf;
    };
};



void Computer::citire()
{
    nr_random++;
    id=nr_random;
    rating_final=0;
    cout<<"Numarul de malware de pe acest calculator este: ";
    cin>>nr_malware_inf;
    cout<<endl;
    for(int i=1; i<=nr_malware_inf; i++)
    {
        cout<<"Malware nr. "<<i<<": ";
        malware mal;
        cin>>mal;
        lista_malware.push_back(mal);
    }
}
void Computer::afisare()
{
    cout<<"ID Computer: ";
    cout<<id;
    cout<<endl<<endl;
    cout<<"Rating Computer: ";
    cout<<rating_final;
    cout<<endl<<endl;
    cout<<"Lista malware: "<<endl;
    for(int i=0; i<lista_malware.size(); i++)
    {
        cout<<"Malware nr. "<<i+1<<": "<<endl;
        cout<<lista_malware[i];
        cout<<endl;
    }
}

int main()
{
    vector<Computer> calculatoare_firma;
    bool ok=1;
    int opt;
    while(ok)
    {
        cout<<"Meniu : "<<endl;
        cout<<"1. Citirea, memorarea si afisarea a n calculatoare. (CERINTA PENTRU 5, DE LA A DOUA APELARE SE VA FOLOSI OPTIUNEA CA ADAUGARE) "<<endl;
        cout<<"2. Afisarea informatiilor pentru fiecare calculator (TREBUIE CITITE INAINTE FOLOSIND OPTIUNEA 1, CERINTA 1)"<<endl;
        cout<<"5. Afisare procent calculatoare infectate din firma (TREBUIE CITITE INAINTE FOLOSIND OPTIUNEA 1, CERINTA 4)"<<endl;
        cout<<"0. Iesire"<<endl<<endl;

        cout<<"Optiune : "<<endl;
        cin>>opt;

        if(opt == 1) //optiunea 1
        {
            int nr_calc;
            cout<<"Cititi numarul de calculatoare: ";
            cin>>nr_calc;
            for(int i=1; i<=nr_calc; i++)
            {
                cout<<"Calculatorul numarul "<<i<<": "<<endl;
                Computer calc;
                calc.citire();
                calculatoare_firma.push_back(calc);
            }

            for(int i=0; i<calculatoare_firma.size(); i++)
            {
                cout<<"Calculatorul numarul "<<i+1<<": "<<endl;
                calculatoare_firma[i].afisare();
            }
            cout<<endl<<endl;

        }
        else if(opt == 2) //optiunea 2
        {
             for(int i=0; i<calculatoare_firma.size(); i++)
            {
                cout<<"Calculatorul numarul "<<i+1<<": "<<endl;
                calculatoare_firma[i].afisare();
            }
            cout<<endl<<endl;
        }
        else if(opt == 5) //optiunea 5
        {
            int contor_c_inf=0;
            int total_calc=calculatoare_firma.size();
            //cout<<total_calc<<endl;
            for(int i=0; i<calculatoare_firma.size(); i++)
            {
                if(calculatoare_firma[i].get_nr_malware_inf()>0) contor_c_inf++;
                //cout<<contor_c_inf<<endl;
            }
            //cout<<contor_c_inf<<" "<<total_calc<<endl;
            double procent_calc_infectate=contor_c_inf*100;
            procent_calc_infectate=procent_calc_infectate/total_calc;
            cout<<"Procent calculatoare infectate: "<<procent_calc_infectate<<"%"<<endl;
            cout<<endl<<endl;

        }
        else if(opt == 0) //optiunea 0
        {
            cout<<"PROGRAMUL SE VA INCHIDE!!!"<<endl;
            ok=0;
        }
        else //optiune default/invalida
        {
            cout<<"Optiune invalida! Meniul se va reincarca!"<<endl;
        }

    }
    return 0;
}
