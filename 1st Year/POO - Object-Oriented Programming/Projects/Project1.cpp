#include <bits/stdc++.h>

using namespace std;

float ABSO[1000];

class Numar_Complex
{
    double re,im;
public:

    //constructors
    Numar_Complex();
    Numar_Complex(Numar_Complex &z);
    Numar_Complex(double re, double im);

    //destructor
    ~Numar_Complex();

    //setters
    void set(double re, double im);
    void setRe(double re);
    void setIm(double im);

    //getters
    double getRe();
    double getIm();


    //Abs
    double calcModul();

    //sum
    Numar_Complex operator+(Numar_Complex);
    //product
    Numar_Complex operator*(Numar_Complex);
    //divide
    Numar_Complex operator/(Numar_Complex);
    //out
    friend std::ostream& operator<<(std::ostream& os,Numar_Complex &z);
    //in
    friend std::istream& operator>>(std::istream& is,Numar_Complex &z);

    //friend class declaration
    friend class Vector_Complex;
};

class Vector_Complex
{
    int nrelem;
    Numar_Complex v[1000];
public:
    //constructors
    Vector_Complex();
    Vector_Complex(Numar_Complex &z, int nrelem);
    Vector_Complex(Vector_Complex &obj);

    //destructor
    ~Vector_Complex();

    friend std::istream& operator>>(std::istream& is, Vector_Complex &obj);
    friend std::ostream& operator<<(std::ostream& os, Vector_Complex &obj);

    //functions
    void sumelem();
    void sortabs();
    void arrabs();

};

Numar_Complex::Numar_Complex()
{
    this->re = 0;
    this->im = 0;
};

Numar_Complex::Numar_Complex(double re, double im)
{
    this->re = re;
    this->im = im;
};

Numar_Complex::Numar_Complex(Numar_Complex& r)
{
    this->re = r.re;
    this->im = r.im;
}
Numar_Complex::~Numar_Complex() {};

double Numar_Complex::getRe()
{
    return this->re ;
}

double Numar_Complex::getIm()
{
    return this->im ;
}

void Numar_Complex::set(double re, double im)
{
    this->re = re;
    this->im = im;
}

void Numar_Complex::setRe(double re)
{
    this->re = re;
}

void Numar_Complex::setIm(double im)
{
    this->im = im;
}

double Numar_Complex::calcModul()
{
    double m;

    m = this->re*this->re + this->im*this->im;

    m=sqrt(m);

    return m;
}

Numar_Complex Numar_Complex::operator+(Numar_Complex op2)
{

    Numar_Complex tmp;

    tmp.re = this->re + op2.re;

    tmp.im = this->im + op2.im;

    return tmp;
}

Numar_Complex Numar_Complex::operator*(Numar_Complex op2)
{
    Numar_Complex tmp;

    tmp.re = this->re * op2.re - this->im * op2.im;

    tmp.im = this->re * op2.im + this->im * op2.re;

    return tmp;
}

Numar_Complex Numar_Complex::operator/(Numar_Complex op2)
{
    Numar_Complex tmp;

    double op2modul = op2.re * op2.re + op2.im *op2.im;

    tmp.re = (this->re * op2.re + this->im *op2.im)/op2modul;

    tmp.im = (this->re *op2.im - this->im *op2.re)/op2modul;

    return tmp;
}

std::istream& operator>>(std::istream& is, Numar_Complex& z)
{
    cout<<"Real Part: ";
    is>>z.re;
    cout<<"Imaginary Part: ";
    is>>z.im;
    return is;
}


std::ostream& operator<<(std::ostream& os, Numar_Complex& z)
{
    if(!z.getIm())
        return os << z.getRe();

    if(z.getRe())
        os << z.getRe();

    if(z.getIm() >0)
        return os << '+' << z.getIm() << "*i";
    else
        return os << z.getIm() << "*i";

}

Vector_Complex::Vector_Complex()
{
    this->nrelem=0;
};

Vector_Complex::Vector_Complex(Numar_Complex &z, int nrelem)
{
    this->nrelem=nrelem;

    for(int i=1; i<=nrelem; i++)
        this->v[i]=z;
};


Vector_Complex::Vector_Complex(Vector_Complex &obj)
{
    this->nrelem=obj.nrelem;

    for(int i=1; i<=nrelem; i++)
        this->v[i]=obj.v[i];
};

Vector_Complex::~Vector_Complex() {};

std::istream& operator>>(std::istream& is, Vector_Complex& obj)
{
    cout<<"Number of elements: ";
    is>>obj.nrelem;
    for(int i=1; i<=obj.nrelem; i++)
    {
        cout<<"Element number "<<i<<": "<<endl;
        is>>obj.v[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, Vector_Complex &obj)
{
    cout<<endl;
    cout<<"Number of elements: ";
    os<<obj.nrelem<<endl;
    for(int i=1; i<=obj.nrelem; i++)
    {
        cout<<"Element number "<<i<<": ";
        os<<obj.v[i]<<endl;
    }
    return os;
}

void Vector_Complex::sumelem()
{
    Numar_Complex s;
    for(int i=1; i<=nrelem; i++)
        s = s + v[i];
    cout<<"The sum of the elements is: "<<s;
}

void Vector_Complex::sortabs()
{
    for(int i=1; i<=nrelem; i++)
        for(int j=i+1; j<=nrelem; j++)
            if(v[i].calcModul()>v[j].calcModul())
            {
                Numar_Complex temp;
                temp=v[j];
                v[j]=v[i];
                v[i]=temp;
            }

    cout<<"Array Sorted!"<<endl;
}

void Vector_Complex::arrabs()
{
    cout<<"Array of absolute values:"<<endl<<endl;
    for(int i=1; i<=nrelem; i++)
    {
        cout<<"Element number "<<i<<": ";
        ABSO[i]=v[i].calcModul();
        cout<<ABSO[i]<<endl;
    }
}

int main()
{
    Vector_Complex V;
    cin>>V;
    int ok=1,menuindex;
    while(ok!=0)
    {
        cout<<endl;
        cout<<"APPLICATION MENU"<<endl;
        cout<<"1. Print array of absolute values"<<endl;
        cout<<"2. Sort array by absolute values"<<endl;
        cout<<"3. Sum of elements"<<endl;
        cout<<"4. Print the array"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<endl;
        cout<<"Choose a number: ";
        cin>>menuindex;
        switch(menuindex){
        case 1:
            cout<<endl;
            V.arrabs();
            break;
        case 2:
            cout<<endl;
            V.sortabs();
            break;
        case 3:
            cout<<endl;
            V.sumelem();
            break;
        case 4:
            cout<<endl;
            cout<<V;
            break;
        case 0:
            cout<<endl;
            cout<<"Goodbye! Have a nice day!";
            ok=0;
            break;
        default:
            cout<<endl;
            cout<<"WRONG NUMBER!!!";
            break;
        }
        cout<<endl<<endl;
    }
    return 0;
}
