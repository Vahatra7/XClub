#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <ctime>
#include <windows.h>
#include "Personne.h"
using namespace std ;

//Constructeur
Personne::Personne() : nom("X"),sexe("m"),age(1)
{
    naissance.jour=1;
    naissance.mois=1;
    naissance.s_mois="Janvier";
    naissance.annee=1900;
}

//Destructeur
Personne::~Personne()
{

}

//Changer nom
void Personne::setnom(string s)
{
    nom=s;
}

//Changer naissance
void Personne::setnaissance(Date d)
{
    naissance=d;
}

//Obtenir le nom
string Personne::getnom()
{
    return nom;
}

//obtenir naissance
Date Personne::getnaissance()
{
    return naissance;
}

int Personne::getage()
{
    return age;
}

string Personne::getsex()
{
    return sexe;
}
//voir si deux personne sont née le meme jour
bool Personne::memeAge(Personne const &b) const
{
    if (naissance.jour == b.naissance.jour &&
        naissance.mois == b.naissance.mois &&
        naissance.annee == b.naissance.annee  )
        return true;
    else
        return false;
}

//voir si une personne est plus jeune qu 'une autre
bool Personne::plusJeune(Personne const &b) const
{
    int x1=naissance.annee,y1=b.naissance.annee,
        x2=naissance.mois ,y2=b.naissance.mois ,
        x3=naissance.jour ,y3=b.naissance.jour ;
    if (x1!=y1)
    {
        if (x1>y1)
            return true;
        else
            return false;
    }
    else
    {
        if (x2!=y2)
        {
            if (x2>y2)
               return true;
            else
               return false;
        }
        else
        {
            if (x3<=y3)
                return false;
            else
                return true ;
        }
    }
}

//operateur ==
bool operator == (Personne const &a,Personne const &b)
{
    if (a.memeAge(b))
        return true;
    else
        return false;
}

//operateur !=
bool operator != (Personne const &a,Personne const &b)
{
    if (a==b)
        return false;
    else
        return true;
}

//operateur <
bool operator < (Personne const &a,Personne const &b)
{
    if (a.plusJeune(b))
        return true;
    else
        return false;
}

//operateur >
bool operator > (Personne const &a,Personne const &b)
{
    if (a<b || a==b)
        return false;
    else
        return true;
}

//operateur >=
bool operator >= (Personne const &a,Personne const &b)
{
    if (a<b)
        return false;
    else
        return true;
}

//operateur <=
bool operator <= (Personne const &a,Personne const &b)
{
    if (a>b)
        return false;
    else
        return true;
}

//operateur << pour un flux ostream
ostream& operator << (ostream &flux,Personne &a)
{
    flux << a.nom << spacer(a.nom) ;
    if (a.naissance.jour<10) flux << "0" ;
    flux << a.naissance.jour
         << " " << a.naissance.s_mois << " " << a.naissance.annee;
    return flux;
}
//operateur >> pour un flux istream
istream& operator >> (istream &flux,Personne &a)
{
    string s,q;
    start:
    a.nom=recueil_nom();
    c(241);cout << "\nEntrez 'm' si la personne est de sexe masculin,autre sinon!" ;
    c(242);cout << "\n\tsexe:";
    c(248);getline(flux,s);
    if (s=="m" || s=="M")
    {
        a.sexe="m";c(241);cout << "\nIl est n\202 le " ;
    }
    else
    {
        a.sexe="f";c(241);cout << "\nElle est n\202e le " ;
    }
    a.naissance.annee=recueil_annee();
    a.age=search_age(a.naissance.annee);
    a.naissance.s_mois=recueil_mois(a.naissance.annee);
    a.naissance.mois=moisToInt(a.naissance.s_mois);
    a.naissance.jour=recueil_jour(a.naissance.annee,a.naissance.mois);
    c(240);cout << "\nVerifiez bien vos donn\202es et entrez 'y' si c' est ok,autre pour retaper\n"
                   "les donn\202es:";c(248);getline(cin,q);sansEspace(q);
    if (q!="y" && q!="Y")
        goto start;
    return flux;
}

//operateur << pour un flux ofstream
ofstream& operator << (ofstream &flux,Personne &a)
{
    flux << a.nom << spacer(a.nom);
    if (a.naissance.jour<10)
        flux << "0" ;
    flux << a.naissance.jour << " " ;
    if (a.naissance.mois<10)
        flux << "0" ;
    flux << a.naissance.mois << " " << a.naissance.annee << " " << a.sexe ;
    return flux;
}

//operateur >> pour un flux ifstream
ifstream& operator >> (ifstream &flux,Personne &a)
{
    string s,t,u,v,w,x;
    unsigned int i;
    getline(flux,s);
    for (i=0;i<s.find("   ");i++)
        t+=s[i];
    a.nom=t;
    for (i=60;i<62;i++)
        u+=s[i];
    a.naissance.jour=stringToInt(u);
    for (i=63;i<65;i++)
        v+=s[i];
    a.naissance.mois=stringToInt(v);
    a.naissance.s_mois=intToMois(a.naissance.mois);
    for (i=66;i<70;i++)
        w+=s[i];
    a.naissance.annee=stringToInt(w);
    a.sexe=s[71];
    a.age=search_age(a.naissance.annee);
    return flux ;
}

//Transformmation d 'un string en entier >0
int stringToInt(string const s)
{
    int i;
    if (s.find(".")<s.size()-1 && s.find(".")>=0)
        return 0;
    else
    {
    istringstream ss(s);
    if (ss >> i)
    {
        if (i<0)
            i=0;
    }
    else
        i=0;
    return i;
    }
}

//Mettre la premiere lettre en majuscule et les autres en minuscule
string finale(string s)
{
    locale loc;
    string x;
    unsigned int i;
    x+=toupper(s[0],loc);
    for (i=0;i<s.size()-1;i++)
    {
        if (s[i]==' ')
            x+=toupper(s[i+1],loc);
        else
            x+=tolower(s[i+1],loc);
    }
    return x;
}

//Transformer le mois en un entier
int moisToInt(string const s)
{
    int i;
    if (s=="Janvier")
        i=1;
    if (s=="Fevrier")
        i=2;
    if (s=="Mars")
        i=3;
    if (s=="Avril")
        i=4;
    if (s=="Mai")
        i=5;
    if (s=="Juin")
        i=6;
    if (s=="Juillet")
        i=7;
    if (s=="Aout")
        i=8;
    if (s=="Septembre")
        i=9;
    if (s=="Octobre")
        i=10;
    if (s=="Novembre")
        i=11;
    if (s=="Decembre")
        i=12;
    return i;
}

//changement des mois en lettres
string intToMois(int const a)
{
    string s;
    if (a==1) s="Janvier";
    if (a==2) s="Fevrier";
    if (a==3) s="Mars";
    if (a==4) s="Avril";
    if (a==5) s="Mai";
    if (a==6) s="Juin";
    if (a==7) s="Juillet";
    if (a==8) s="Aout";
    if (a==9) s="Septembre";
    if (a==10) s="Octobre";
    if (a==11) s="Novembre";
    if (a==12) s="Decembre";
    return s;
}
void sansEspace(std::string &s)
{
    int x,y;
    unsigned int j,k=0;
    x=s.find(" ");
    y=s.size();
    if (x>=0 && x<y)
    {
        for (j=x;j<s.size();j++)
        {
            if (s[j]!=' ')
                k+=1;
        }

        if (k==0)
            s.resize(x);
    }
}
string recueil_nom()
{
    string s;
    unsigned int x,i,j=0;
    name:
    c(241);cout << "Entrez le nom complet!" ;
    c(242);cout << "\n\tnom:";
    c(248);getline(cin,s);
    if (s.size()<1)
    {
        do
        {
            c(252);cout << "Entrez un nom!!!";
            c(242);cout << "\n\tnom:";
            c(248);getline(cin,s);
        }while (s.size()<1);
    }
    if (s.find(" ")==0)
    {
        c(252);cout << "\nNe commencez pas par un espace svp!!!\n";
        goto name;
    }
    x=s.find("  ");
    if (x<s.size() && x>0)
    {
        for (i=x;i<s.size();i++)
        {
            if (s[i]!=' ')
                j+=1;
        }

        if (j==0)
            s.resize(x);
        else
        {
        c(252);cout << "\nNe mettez qu 'un seul espace entre les mots!!!\n";
        goto name;
        }
    }
    if (s.size()>57)
        s.resize(57);
    s=finale(s);
    return s;
}
//recueil de la valeur de l 'annee de naissance
int recueil_annee()
{
    int a;
    string s;
    time_t secondes;
    time(&secondes);
    tm today=*localtime(&secondes);
    c(242);cout << "\n\tann\202e:";
    c(248);getline(cin,s);
    sansEspace(s);
    a=stringToInt(s);
    if (a<1900 || a >(today.tm_year+1900))
    {
       do
       {
          c(252);cout << "R\202entrez l ' ann\202e!!";
          c(242);cout << "\n\tann\202e:";
          c(248);getline(cin,s);
          sansEspace(s);
          a=stringToInt(s);
       }while (a<1900 || a >(today.tm_year+1900));
    }
    return a;
}

//age
int search_age(int const a)
{
    int x;
    time_t secondes;
    time(&secondes);
    tm today=*localtime(&secondes);
    x=today.tm_year+1900-a;
    return x;
}
//recueil du mois de naissance
string recueil_mois(int const a)
{
    string s;int i;
    time_t secondes;
    time(&secondes);
    tm today=*localtime(&secondes);
    c(242);cout << "\n\tmois" ;
    c(244);cout << "(En lettres et sans accent!!)";
    c(242);cout << "\n\t:";c(248);
    getline(cin,s);
    sansEspace(s);
    s=finale(s);
    if (!test(s))
    {
        do
        {
            c(252);cout << "R\202entrez le mois!!" ;
            c(242);cout << "\n\tmois:";c(248);
            getline(cin,s);
            sansEspace(s);
            s=finale(s);
        }while (!test(s));
    }
    if (a==today.tm_year+1900)
    {
    i=moisToInt(s);

    if (i > today.tm_mon+1)
    {
        do
        {
            c(252);cout << "R\202entrez le mois!!" ;
            c(242);cout << "\n\tmois:";c(248);
            getline(cin,s);
            sansEspace(s);
            s=finale(s);
            if (test(s))
                i=moisToInt(s);
        }while (!test(s)  || i>today.tm_mon+1 );
    }
    }
    return s;
}

//recueil du jour de naissance
int recueil_jour(int const a,int const m)
{
    string s;
    time_t secondes;
    time(&secondes);
    tm today=*localtime(&secondes);
    int j;
    go:
    c(242);cout << "\n\tjour" ;
    c(244);cout << "(entier strictement positif,autrement ce sera pris comme un '1')";
    c(242);cout << "\n\t:" ;c(248);
    getline(cin,s);
    sansEspace(s);
    j=stringToInt(s);
    if (j==0) j=1;
    if (a%4==0 && m==2)
    {
        if (j>29)
        {
            do
            {
                c(252);s.clear();
                cout << "le mois que vous avez tap\202 avant ne peut pas avoir plus que 29 jours!\n";
                c(242); cout << "\tjour:";c(248);
                getline(cin,s);
                sansEspace(s);
                j=stringToInt(s);
                if (j==0) j=1;
            }while (j>29);
        }
    }
    if (a%4!=0 && m==2)
    {
        if (j>28)
        {
            do
            {
                c(252);s.clear();
                cout << "le mois que vous avez tap\202 avant ne peut pas avoir plus que 28 jours!\n";
                c(242); cout << "\tjour:";c(248);
                getline(cin,s);
                sansEspace(s);
                j=stringToInt(s);
                if (j==0) j=1;

            }while (j>28);
        }
    }
    if (m==4 || m==6 || m==9 || m==11)
    {
        if (j>30)
        {
            do
            {
                c(252);s.clear();
                cout << "le mois que vous avez tap\202 avant ne peut pas avoir plus que 30 jours!\n";
                c(242); cout << "\tjour:";c(248);
                getline(cin,s);
                sansEspace(s);
                j=stringToInt(s);
                if (j==0) j=1;
            }while (j>30);
        }
    }
    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        if (j>31)
        {
            do
            {
                c(252);s.clear();
                cout << "le mois que vous avez tap\202 avant ne peut pas avoir plus que 31 jours!\n";
                c(242); cout << "\tjour:";c(248);
                getline(cin,s);
                sansEspace(s);
                j=stringToInt(s);
                if (j==0) j=1;
            }while (j>31);
        }
    }
    if (a==today.tm_year+1900 && m==today.tm_mon+1 && j>today.tm_mday)
    {
        c(252);cout << "\nR\202entrez le jour svp car la date d\202passe celle du systeme";
        goto go;
    }

    return j;
}

//teste si l 'utilisateur a saisi un mois qui existe
bool test(string const s)
{
    if (s=="Janvier" || s=="Fevrier" || s=="Mars" || s=="Avril" || s=="Mai" || s=="Juin" ||
        s=="Juillet" || s=="Aout" || s=="Septembre" || s=="Octobre" || s=="Novembre" || s=="Decembre")
        return true;
    else
        return false;
}

//espacement dans l 'affichage
string spacer(string x)
{
    int i;
    string s;
    for (i=x.size();i<60;i++)
        s+=" ";
    return s;
}

//couleur des textes
void c(int x)
{
    HANDLE coul=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(coul,x);
}
