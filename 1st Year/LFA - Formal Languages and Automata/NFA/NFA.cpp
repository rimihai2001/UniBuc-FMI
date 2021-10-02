#include <bits/stdc++.h>

using namespace std;

ifstream fin ("NFA_Mihai_Radu-Ioan.in");
ofstream fout ("NFA_Mihai_Radu-Ioan.out");

char mat[100][100],cuvant[100],litera_tranzitie;
int stari_finale[100], n, m, stare_initiala, f, x, y, nrcuvinte, sstart, send;


struct stocare
{
    char cuv[100];
    int cuvindexpos, stare_curenta, drum[1000], ldrum;
} v[10000];


int main()

{
    fin >> n >> m; //citire numar de noduri si numar de muchii

    for(int i = 1 ; i <= m ; i++ ) //citire muchii
    {
        fin>> x >> y >> litera_tranzitie;
        mat[x][y]=litera_tranzitie;
    }

    fin>>stare_initiala; //citire nod stare initiala

    fin>>f; //citire numar noduri finale

    for( int i = 1; i <= f ; i++ ) //citire noduri finale
        fin >> stari_finale[i];


    fin >> nrcuvinte; //citire numar cuvinte de verificat

    for( int i=1; i<=nrcuvinte; i++)
    {
        //cout<<i<<endl;
        fin >> cuvant; //citire cuvinte de verificat
        cout << "Cuvantul numarul " << i << ": " << endl << endl;
        cout << "Status: Incepere verificare! " << endl;

        //stare_initialaializarea primului element din vector
        strcpy(v[1].cuv,cuvant);
        v[1].cuvindexpos = 0;
        v[1].stare_curenta = stare_initiala;
        v[1].drum[1] = stare_initiala;
        v[1].ldrum = 1;
        sstart = 1;
        send = 1;
        bool ok = 0;
        cout << "Status: Se verifica... " << endl;

        while( ok == 0 )
        {
            if( sstart > send )
            {
                //codul se opreste in momentul in care s-au verificat toate elementele
                //se afiseaza faptul ca nu este acceptat cuvantul
                ok = 1;
                fout << "NU" << endl;
                cout << "Status: Verificare finalizata!" << endl << endl;
            }
            else if( v[sstart].cuvindexpos == strlen(v[sstart].cuv) )
            {
                //daca cuvantul este vid, atunci verificam daca se afla intr-o stare finala
                for( int k = 1 ;  k <= f ; k++ )
                {
                    if( v[sstart].stare_curenta == stari_finale[k] )
                    {
                        //daca este stare_curenta finala, atunci afisam ca este acceptat si traseul
                        ok = 1;
                        fout << "DA" << endl;
                        cout << "Status: Verificare finalizata!" << endl << endl;
                        fout << "Traseu: ";
                        for( int z = 1 ; z<=v[sstart].ldrum ; z++ )
                            fout << v[sstart].drum[z] << " ";
                        fout << endl;
                    }
                }
            }
            else
            {
                for( int j = 0 ; j < n ; j++)
                {
                    //verificam daca exista o tranizitie ce are litera actuala a cuvantului
                    if( v[sstart].cuv[v[sstart].cuvindexpos] == mat[v[sstart].stare_curenta][j] )
                    {
                        //adaugam la sfarsit un nou element, care contine cuvantul, starea noua si drumul parcurs pana acum
                        send++;
                        strcpy( v[send].cuv, v[sstart].cuv );
                        v[send].cuvindexpos = v[sstart].cuvindexpos + 1;
                        v[send].stare_curenta = j;

                        for( int r = 1 ; r <= v[sstart].ldrum ; r++ )
                            v[send].drum[r] = v[sstart].drum[r];

                        v[send].ldrum = v[sstart].ldrum + 1;
                        v[send].drum[v[send].ldrum] = j;
                    }
                }
            }
            sstart++;
        }
    }
    cout << "VERIFICATI FISIERUL DE IESIRE PENTRU A VEDEA DACA CUVINTELE AU FOST ACCEPTATE!" << endl;
    return 0;
}
