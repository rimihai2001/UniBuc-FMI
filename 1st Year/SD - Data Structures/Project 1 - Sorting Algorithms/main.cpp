#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

std::vector<std::string> v;
std::vector<std::string> copiev;

std::vector<double> w;
std::vector<double> copiew;

std::map<std::string,int> stringmap;
std::map<double,int> nrmap;

void resetnr()
{
    w.clear();
    w=copiew;
}

void checksortednr()
{
    int ok=1;
    for(unsigned long long i=1; i<w.size(); i++)
        if(w[i]<w[i-1]) ok=0;
    if(ok==1) cout<<"Array Sorted!"<<endl;
    else cout<<"ARRAY NOT SORTED!"<<endl;
}

void resetstr()
{
    v.clear();
    v=copiev;
}

void checksortedstr()
{
    int ok=1;
    for(unsigned long long i=1; i<v.size(); i++)
        if(v[i]<v[i-1]) ok=0;
    if(ok==1) cout<<"Array Sorted!"<<endl;
    else cout<<"ARRAY NOT SORTED!"<<endl;
}

string gen_randomstr(int len)
{

    string tmp_s;
    srand(time(0));
    static const char alphanum[] ="abcdefghijklmnopqrstuvwxyz";
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    return tmp_s;
}

void gen_descnr(unsigned long long n, unsigned long long maxim)
{
    for(unsigned long long i=1; i<=n-n/5; i++)
        if((maxim-i)>0)w.push_back(maxim-i);
        else w.push_back(1);
    for(unsigned long long i=n-n/5+1; i<=n; i++)
        w.push_back(maxim-1);
}

void gen_incnr(unsigned long long n, unsigned long long maxim)
{
    for(unsigned long long i=1; i<=n-n/5; i++)
        if(i<maxim)w.push_back(i);
        else w.push_back(maxim);
    for(unsigned long long i=n-n/5+1; i<=n; i++)
        w.push_back(1);
}

void gen_constantnr(unsigned long long n, unsigned long long maxim)
{
    for(unsigned long long i=1; i<=n; i++)
        w.push_back(maxim);
}


void gen_randomnr(unsigned long long n, unsigned long long maxim)
{
    for(unsigned long long i=1; i<=n; i++)
        w.push_back((rand()%32000)*maxim/32000+ 1);
}

void randomstr(int value)
{
    for(int i=1; i<=value; i++)
        v.push_back(gen_randomstr((rand()%50)+1));
}

void randomchar(int value)
{
    for(int i=1; i<=value; i++)
        v.push_back(gen_randomstr(1));
}

int shellSort(vector <double> &arr)
{
    for (unsigned long long gap = arr.size()/2; gap > 0; gap /= 2)
    {
        for (unsigned long long i = gap; i < arr.size(); i += 1)
        {
            unsigned long long j;
            double temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

int shellSortstr(vector <string> &arr)
{
    for (unsigned long long gap = arr.size()/2; gap > 0; gap /= 2)
    {
        for (unsigned long long i = gap; i < arr.size(); i += 1)
        {
            unsigned long long j;
            string temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

void quickSort1(vector<double> &str, unsigned long long left, unsigned long long right)
{
    unsigned long long i = left, j = right;
    double mid = str[(left + right) / 2];

    while (i <= j)
    {
        while (str[i] < mid)
            i++;
        while (str[j] > mid)
            j--;
        if (i <= j)
        {
            swap(str[i], str[j]);
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort1(str, left, j);
    if (i < right)
        quickSort1(str, i, right);
}

void quickSort2(vector<string> &str, unsigned long long left, unsigned long long right)
{
    unsigned long long i = left, j = right;
    string mid = str[(left + right) / 2];

    while (i <= j)
    {
        while (str[i] < mid)
            i++;
        while (str[j] > mid)
            j--;
        if (i <= j)
        {
            swap(str[i], str[j]);
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort2(str, left, j);
    if (i < right)
        quickSort2(str, i, right);
}

void mergefunction(vector<double> &str, unsigned long long l, unsigned long long m, unsigned long long r)
{
    unsigned long long i, j, k, nl, nr;
    nl = m-l+1;
    nr = r-m;
    double larr[nl], rarr[nr];
    for(i = 0; i<nl; i++)
        larr[i] = str[l+i];
    for(j = 0; j<nr; j++)
        rarr[j] = str[m+1+j];
    i = 0;
    j = 0;
    k = l;
    while(i < nl && j<nr)
    {
        if(larr[i] <= rarr[j])
        {
            str[k] = larr[i];
            i++;
        }
        else
        {
            str[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        str[k] = larr[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        str[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSort(vector<double> &str, unsigned long long l, unsigned long long r)
{
    unsigned long long m;
    if(l < r)
    {
        unsigned long long m = l+(r-l)/2;
        mergeSort(str, l, m);
        mergeSort(str, m+1, r);
        mergefunction(str, l, m, r);
    }
}

void mergefunctionstr(vector<std::string> &str, unsigned long long l, unsigned long long m, unsigned long long r)
{
    unsigned long long i, j, k, nl, nr;
    nl = m-l+1;
    nr = r-m;
    string larr[nl], rarr[nr];
    for(i = 0; i<nl; i++)
        larr[i] = str[l+i];
    for(j = 0; j<nr; j++)
        rarr[j] = str[m+1+j];
    i = 0;
    j = 0;
    k = l;
    while(i < nl && j<nr)
    {
        if(larr[i] <= rarr[j])
        {
            str[k] = larr[i];
            i++;
        }
        else
        {
            str[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        str[k] = larr[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        str[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSortstr(vector<std::string> &str, unsigned long long l, unsigned long long r)
{
    unsigned long long m;
    if(l < r)
    {
        unsigned long long m = l+(r-l)/2;
        mergeSortstr(str, l, m);
        mergeSortstr(str, m+1, r);
        mergefunctionstr(str, l, m, r);
    }
}
int main()
{
    unsigned long long a,n,t,mx;
    double x;
    string el;
    cout<<"Number of tests:  ";
    cin>>t;
    for(unsigned long long T=1; T<=t; ++T)
    {
        cout<<"Number of elements:  ";
        cin>>n;
        cout<<"Numbers (0) or Strings (1) ?  ";
        cin>>a;
        if(n>50000000) cout<<"TOO MANY ELEMENTS!"<<endl;
        if(a==0 and n<=50000000)
        {
            w.clear();
            cout<<"Maximum element (LESS THAN 10^19):  ";
            cin>>mx;
            cout<<endl;
            cout<<"1. Nearly sorted array"<<endl;
            cout<<"2. Nearly sorted array (decreasing)"<<endl;
            cout<<"3. Random array"<<endl;
            cout<<"4. Constant array"<<endl;
            cout<<"5. Custom (also for double)"<<endl;
            cout<<endl;
            cout<<"Type of Input: ";
            int TT;
            cin>>TT;
            if(TT==1)
                gen_incnr(n,mx);
            if(TT==2)
                gen_incnr(n,mx);
            if(TT==3)
                gen_randomnr(n,mx);
            if(TT==4)
                gen_constantnr(n,mx);
            if(TT==5)
                for(unsigned long long i=1; i<=n; i++)
                {
                    cin>>x;
                    w.push_back(x);
                }
            copiew=w;
            auto start = high_resolution_clock::now();
            sort(w.begin(),w.end());
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

            cout << "Time taken by STD Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortednr();
            resetnr();
            if(n<=50000){
            start = high_resolution_clock::now();
            for(unsigned long long i=0; i<w.size(); i++)
                for(unsigned long long j=0; j<w.size(); j++)
                    if(w[i]<w[j]) swap(w[i],w[j]);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Direct Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortednr();
            resetnr();}
            else cout<<"Direct Sort: Try Another Method!!!"<<endl;
            if(n<=50000){
            start = high_resolution_clock::now();
            for(unsigned long long i=0; i<w.size(); i++)
                for(unsigned long long j=0; j<w.size()-i-1; j++)
                    if(w[j+1]<w[j]) swap(w[j],w[j+1]);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Bubble Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortednr();
            resetnr();
            }
            else cout<<"Bubble Sort: Try Another Method!!!"<<endl;
            start = high_resolution_clock::now();
            shellSort(w);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Shell Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortednr();
            resetnr();
            start = high_resolution_clock::now();
            quickSort1(w, 0, w.size() - 1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Quick Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortednr();
            resetnr();
             if(n<=250000){
            start = high_resolution_clock::now();
            mergeSort(w,0,w.size()-1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Merge Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortednr();
            resetnr();}
            else cout<<"Merge Sort: Try Another Method!!!"<<endl;
            start = high_resolution_clock::now();
            for(auto i:w)
                nrmap[i]++;
            w.clear();
            for(auto i=nrmap.begin(); i!=nrmap.end(); i++)
                for(unsigned long long j=1; j<=i->second; j++)
                    w.push_back(i->first);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Count Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortednr();
            resetnr();
        }
        else if(a==1 and n<=50000000)
        {
            v.clear();
            cout<<"1. Characters"<<endl;
            cout<<"2. Strings"<<endl;
            cout<<"3. Custom"<<endl;
            cout<<endl;
            cout<<"Type of Input:";
            int TT;
            cin>>TT;
            if(TT==1)
            randomstr(n);
            if(TT==2)
                randomchar(n);
            else if(TT==3)
                for(unsigned long long i=1; i<=n; i++)
                {
                    cin>>el;
                    v.push_back(el);
                }
            copiev=v;
            auto start = high_resolution_clock::now();
            sort(v.begin(),v.end());
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by STD Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortedstr();
            resetstr();
            if(n<=50000){
            start = high_resolution_clock::now();
            for(unsigned long long i=0; i<v.size(); i++)
                for(unsigned long long j=0; j<v.size(); j++)
                    if(v[i]<v[j]) swap(v[i],v[j]);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Direct Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortedstr();
            resetstr();}
            else cout<<"Direct Sort: Try Another Method!!!"<<endl;
            if(n<=50000){
            start = high_resolution_clock::now();
            for(unsigned long long i=0; i<v.size(); i++)
                for(unsigned long long j=0; j<v.size()-i-1; j++)
                    if(v[j+1]<v[j]) swap(v[j],v[j+1]);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Bubble Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortedstr();}
            else cout<<"Bubble Sort: Try Another Method!!!"<<endl;
            resetstr();
            start = high_resolution_clock::now();
            shellSortstr(v);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Shell Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortedstr();
            resetstr();

            if(TT==1 and n>1000) cout<<"Quick Sort: Try Another Method!!!"<<endl;
            else{start = high_resolution_clock::now();
            quickSort2(v, 0, v.size() - 1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Quick Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortedstr();
            resetstr();}
            if(n<=500000){
            start = high_resolution_clock::now();
            mergeSortstr(v,0,v.size()-1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Merge Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortedstr();
            resetstr();}
            else cout<<"Merge Sort: Try Another Method!!!"<<endl;

            start = high_resolution_clock::now();
            for(auto i:v)
                stringmap[i]++;
            v.clear();
            for(auto i=stringmap.begin(); i!=stringmap.end(); i++)
                for(unsigned long long j=1; j<=i->second; j++)
                    v.push_back(i->first);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Count Sort: "
                 << duration.count() << " microseconds" << endl;
            checksortedstr();
            resetstr();

        }
    }
    return 0;
}
