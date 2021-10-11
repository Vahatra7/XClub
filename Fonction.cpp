#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <list>
#include "Personne.h"
#include "Fonction.h"
#include "alphabet.h"
#define ligne cout <<"-------------------------------------------------------------------------------";
#define press c(247);cout << "\n\nAppuyez sur ENTRER pour continuer";
#define enter getch();cout << endl;
using namespace std ;

void intro()
{
    int i;
    system("color 07");
    system("title XClub");
    cout << "\n\n\n\n\n\n";
    c(4);ligne cout << endl ;ligne cout << "\n||\t\t\t\t\t\t\t\t\t     ||\n";
    for (i=1;i<6;i++)
    {
        c(4);cout << "||\t\t        ";
        X(i,12);cout << "  ";C(i,14);L(i,13);U(i,10);B(i,11);
        c(4);cout << "\t\t     ||" ;fin(i);
    }
    c(4);cout <<"||\t\t\t\t\t\t\t\t\t     ||\n" ;ligne cout <<endl ;ligne
    Sleep(2000);
    system("cls");
    cout << "\n\n\n\n\n\n";
    ligne cout << endl ;ligne
    for (i=1;i<8;i++)
        cout << "\n||\t\t\t\t\t\t\t\t\t     ||";
    cout << endl ;ligne cout << endl ;ligne
    Sleep(800);
    system("cls");

    cout << "\n\n\n\n\n\n";
    ligne cout << endl;ligne c(4);cout << "\n||\t\t\t\t\t\t\t\t\t     ||\n||";
    c(2);cout << "\tCe programme sert \205 g\202rer les membres d'un club de tennis et affiche ";
    c(4);cout << "||\n||";
    c(2);cout << " le plus jeune et le plus ag\202 de ces membres...\t\t\t     ";
    c(4);cout << "||\n||\t\t\t\t\t\t\t\t\t     ||\n||\t\t\t\t\t\t\t\t\t     ||\n||";
    c(11);cout << "\t\t\t        D\202velopper par:";
    c(2);cout << "Vahatra RABODONANDRIANANDRAINA";
    c(4);cout << "||\n||\t\t\t\t\t\t\t\t\t     ||\n";
    ligne cout << endl;ligne
    Sleep(1000);
    c(8);cout << "\n\nAppuyez sur ENTRER";enter;
    system("cls");

//MAXIMISATION DE LA TAILLE DU CONSOLE--------------------------------------------------
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);
//---------------------------------------------------------------------------------------
}

void aujourdhui(int const exec)
{
    time_t s;
    time(&s);
    tm t=*localtime(&s);
    c(114);ligne
    c(226);cout << "\nExecution numero " << exec;
    c(114); cout << ": ";
    if (t.tm_mday<10)
        cout << "0";
    cout << t.tm_mday << " " << intToMois(t.tm_mon+1) << " " << t.tm_year+1900 << "\t\t\t";
    if (t.tm_hour<10) cout << "0";
    cout << t.tm_hour << ":";
    if (t.tm_min<10) cout << "0";
    cout << t.tm_min << "\t\t       " <<  endl;
    ligne
}

void outro()
{
    int i;
//TAILLE DU CONSOLE NORMALE--------------------------------------------------
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_NORMAL);
//---------------------------------------------------------------------------------------
system("color 07");
    cout << "\n\n\n\n\n\n";
    c(4);ligne cout << endl ;ligne cout << "\n||\t\t\t\t\t\t\t\t\t     ||\n";
    for (i=1;i<6;i++)
    {
        c(4);cout << "||\t\t        ";
        T(i,13);H(i,9);A(i,11);N(i,12);K(i,14);S(i,10);
        c(4);cout << "\t\t     ||" ;fin(i);
    }
    c(4);cout <<"||\t\t\t\t\t\t\t\t\t     ||\n" ;ligne cout <<endl ;ligne
    c(8);cout << "\n\nAppuyez sur ENTRER pour quitter";
    enter
}

string quest(int &exec)
{
    string y;
    c(124);cout << "\n\nEntrez 'y' si vous voulez continuer,autre sinon:";c(240);
    getline(cin,y);sansEspace(y);
    exec+=1;
    system("cls");
    return y;
}

void nombre(int &n,int &m,int &M)
{
    string s;
    c(240);
    cout << endl ;ligne
    cout << "\nCeci \202tant la premi\212re utilisation, on va d' abord ajouter les membres"
            " du club\ndans la base de donn\202es\n";ligne cout << "\n";

    c(245);cout << "D' abord,vous \210tes pri\202 d' entrer l '\203ge minimum et maximum requis pour"
            " \210tre\nmembre...\n";
    m:
    c(246);cout << "-Age minimum:" ;c(248);
    getline(cin,s);sansEspace(s);
    m=stringToInt(s);
    if (m==0)
    {
        c(252);cout << "Entrer un entier strictement positif\n";
        goto m;
    }
    if (m>=100)
    {
        c(252);cout << "N' exag\202rez pas!!!\n";
        goto m;
    }
    M:
    c(246);cout << "\n-Age maximum:" ;c(248);
    getline(cin,s);sansEspace(s);
    M=stringToInt(s);
    if (M==0 || M<m)
    {
        c(252);cout << "Entrer un entier sup\202rieur ou \202gal \205 l '\203ge minimum\n";
        goto M;
    }
    if (M>=150)
    {
        c(252);cout << "N' exag\202rez pas!!!\n";
        goto M;
    }
    c(245);cout << "\nVeuillez entrer l' effectif des membres:";
    c(248);getline(cin,s);sansEspace(s);
    n=stringToInt(s);
    if (n==0)
    {
        do
        {
            c(252);cout << "Entrez un entier strictement positif:";
            c(248);getline(cin,s);sansEspace(s);
            n=stringToInt(s);
        }while (n==0);
    }
}

void recueil(ofstream &b,list<Personne> &m,int const mi,int const ma)
{
    int i=1;
    Personne temporaire;
    list<Personne>::iterator it;
    if (mi<10) b << "0";
    b << mi << " " ;
    if (ma <10) b << "00";
    if (ma <100 && ma>=10) b << "0";
    b << ma;
    for (it=m.begin();it!=m.end();++it)
    {
        d:
        c(244);cout <<endl ;ligne
        c(245);cout << "\nDonn\202es du membre num\202ro " << i << endl ;
        cin >> temporaire;
        c(244);cout <<endl ;ligne
        if (temporaire.getage()<mi)
        {
            c(252); cout << "\nDonnez une autre personne car celle-l\205 est encore trop jeune\n";
            goto d;
        }
        if (temporaire.getage()>ma)
        {
            c(252);cout << "\nDonnez une autre personne car celle-l\205 est trop ag\202e\n";
            goto d;
        }
        *it=temporaire;
        if (i!=1)
        {
        if (!verification(temporaire,m,i))
            goto d;
        }
        b << endl ;
        b << temporaire;
        i+=1;
    }
}

void output (std::list<Personne> m)
{
    int i=1;
    Personne t;
    list<Personne>::iterator it;
    c(252);cout << endl;ligne
    c(252);cout << "\nVOICI LA LISTE ACTUELLE DES MEMBRES:";c(240);
    for (it=m.begin();it!=m.end();++it)
    {
        t=*it;
        c(244);cout << endl << i << ":" ;
        c(240);cout << t;
        i+=1;
    }
    c(252);cout << endl;ligne press enter
}

void hide()
{
    SetFileAttributes("Donnees.txt", FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
}

Personne minimal(list<Personne> m)
{
    Personne j,t;
    list<Personne>::iterator it;
    it=m.begin();
    j=*it;
    for (it=m.begin();it!=m.end();++it)
    {
        t=*it;
        if (t<j)
            j=t;
    }
    return j;
}

Personne maximal(list<Personne> m)
{
    Personne j,t;
    list<Personne>::iterator it;
    it=m.begin();
    j=*it;
    for (it=m.begin();it!=m.end();++it)
    {
        t=*it;
        if (t>j)
            j=t;
    }
    return j;
}

vector<Personne> stock(Personne const j,list<Personne> m)
{
    vector<Personne> l;
    Personne t;
    list<Personne>::iterator it;
    for (it=m.begin();it!=m.end();++it)
    {
        t=*it;
        if (t==j)
           l.push_back(t);
    }
    return l;
}

bool verification(Personne t,list<Personne> m,int const i)
{
    list<Personne>::iterator it;
    int a=0;
    Personne temp;
    for(it=m.begin();it!=m.end();++it)
    {
        a+=1;
        temp=*it;
        if (temp.getnom()==t.getnom() && a!=i)
        {
        if (temp==t && temp.getsex()==t.getsex())
           {
               c(252);cout << "\nCette personne est d\202j\205 membre,donnez une autre\n";
               return false;
           }
        else
           {
               c(252);cout << "\nSp\202cifiez le nom car un autre membre le porte d\202j\205\n";
               return false;
           }
        }
    }
    return true;
}

void affichage (int i,vector<Personne> m)
{
    int sexcount=0,j;
        for (j=0;j<i;j++)
        {
            c(241);if (i!=1) cout << "-";
            c(249);cout << m[j].getnom();
            if (i!=1) cout << endl;
            if (m[j].getsex()=="f")
                sexcount+=1;
        }
        if (i==1)
        {
            c(241);if (m[0].getsex()=="m") cout << ";il a ";
            else cout << ";elle a " ;
        }
        else
        {
            c(241);
            if (sexcount==i) cout << "Elles ont ";
            else cout << "Ils ont ";
        }
        c(249);cout << m[0].getage();
        if (m[0].getage()==1)
            {cout << " an ";c(241);cout<< "cette ann\202e,";}
        else
            {cout << " ans ";c(241);cout<< "cette ann\202e,";}
        if (i==1)
        {
            c(241);if (m[0].getsex()=="m") cout << "n\202 le ";
            else cout << "n\202e le " ;
        }
        else
        {
            c(241);
            if (sexcount==i) cout << "n\202es le ";
            else cout << "n\202s le ";
        }
        c(249);cout << m[0].getnaissance().jour << " " << m[0].getnaissance().s_mois << " " << m[0].getnaissance().annee << endl;

}

void affichage_final(Personne const j,Personne const v,list<Personne> m)
{
    unsigned int i,k=1;
    vector<Personne> mi,ma;
    c(241); cout << "\n\nActuellement:";
if (m.size()==1)
{
    c(241);cout << "il n'y a qu' un seul membre donc pas la peine de savoir le plus\n"
                  " jeune ou le plus \203g\202\n";
}
else
{
    mi=stock(j,m);
    i=mi.size();
    if (i==m.size())
    {
        c(241);cout << "\nTous les membres ont le m\210me \203ge:" << mi[0].getage()<< " ans.\n";
        k=0;
    }
    else
    {
        c(241);
        if (i==1)
           cout << "\nLe plus jeune des membres est ";
        else
            cout << "\nLes plus jeunes des membres sont:\n";
        affichage(i,mi);
    }
    if (k!=0)
    {
        ma=stock(v,m);
        i=ma.size();
        c(241);
        if (i==1)
           cout << "Le plus \203g\202 des membres est ";
        else
            cout << "Les plus \203g\202s des membres sont:\n";
        affichage(i,ma);
    }
}
}

int nb(ifstream &x,int &m,int &M)
{
    int n=0,i;
    string s,mm,MM;
    getline(x,s);sansEspace(s);
    for (i=0;i<2;i++)
        mm+=s[i];
    for (i=3;i<6;i++)
        MM+=s[i];
    m=stringToInt(mm);
    M=stringToInt(MM);
    c(249);
    while(getline(x,s))
    {
        n+=1;
    }
    if (n==0)
        cout << "\n\nActuellement , il n' y a aucun membre\n";
    else
    {
    cout << "\n\nActuellement , il y a " << n ;
    if (n==1) cout << " membre.\n";
    else cout << " membres.\n" ;
    }
    c(241);cout << "Pour \210tre membre, il faut avoir ";
    if (m!=M)
    cout << "entre " << m << " et " << M << " ans.\n";
    else
    {
        cout << m ;
        if (m==1) cout << " an.\n";
        else cout << " ans.\n";
    }
  return n;
}

void recuperation(list<Personne> &m)
{
    string s;
    Personne t;
    list<Personne>::iterator i;
    ifstream x("Donnees.txt",ios::in);
    getline(x,s);sansEspace(s);
    for (i=m.begin();i!=m.end();++i)
    {
        x >> t;
        *i=t;
    }
    x.close();
}


string choix(list<Personne> m)
{
    string r;
    if (m.size()!=0)
        output(m);
    c(245);
    cout << "\n\nQue voulez-vous faire?" << endl ;
    c(246);
    cout << "Entrez '1' pour modifier la condition sur l' \203ge\n"
         << "       '2' pour ajouter des membres\n";
    if (m.size()!=0)
         cout << "       '3' pour retirer un membre \n";
    cout << "       autre pour continuer sans rien faire";
    c(245);
    cout << "\nR\202ponse:";c(240);
    getline(cin,r);sansEspace(r);
    if (m.size()==0 && r=="3")
        r="no";
    return r;
}


void error_size()
{
    c(252);cout << "\nLa liste est vide\n";
}
void ajout(list<Personne> &m,int const mi,int const ma)
{
    int i,n,nb;
    string nn,y;
    Personne temporaire;

    ofstream x("Donnees.txt",ios::out|ios::app);
    if (x)
    {
        c(243);cout << "\nCombien de membres voulez-vous ajouter?";c(240);
        getline(cin,nn);sansEspace(nn);
        n=stringToInt(nn);
        if (n!=0)
        {
            nb=m.size();
            for (i=1;i<=n;i++)
            {

            d:
            c(248);cout <<endl ;ligne
            c(253);cout << "\nDonn\202es du membre num\202ro " << i+nb << endl ;
            cin >> temporaire;
            c(248);cout <<endl ;ligne
            if (temporaire.getage()<mi)
            {
                c(252); cout << "\nDonnez une autre personne car celle-l\205 est encore trop jeune\n";
                goto d;
            }
            if (temporaire.getage()>ma)
            {
                c(252);cout << "\nDonnez une autre personne car celle-l\205 est trop ag\202e\n";
                goto d;
            }
            m.push_back(temporaire);
            if (!verification(temporaire,m,i+nb))
            {
                c(242);cout << "Ou bien entrez 'fin' pour terminer l 'ajout de membres:";
                c(248);getline(cin,y);sansEspace(y);y=finale(y);
                if (y=="Fin")
                {
                    m.pop_back();
                    goto sortie;
                }

                else
                    goto d;
            }
            x << endl ;
            x << temporaire;
            }
            sortie:;

        }

    }
    else
    {c(12);cout << "\nUNE ERREUR EST SURVENUE\n";}
}

void suppr(int const x,list<Personne> &m)
{
    int j;
    list<Personne>::iterator it;
    it=m.begin();
    for (j=1;j<x;j++)
        ++it;
    m.erase(it);
}

void suppression(list<Personne> &m,int const mi,int const ma)
{
    unsigned int x;
    string xx,q="n";
    list<Personne>::iterator it;
    Personne temp;
        do
        {
            output(m);
            c(253);cout << "\nDonnez le num\202ro du membre \205 retirer:";c(248);
            getline(cin,xx);sansEspace(xx);
            x=stringToInt(xx);
            if (x<=m.size() && x>0)
            {
                suppr(x,m);
               if (m.size()==0)
                  q="n";
               else
               {
               c(242);cout << "\nEntrez 'y' si vous voulez encore en retirer,autre sinon:";c(248);
               getline(cin,q);sansEspace(q);
               }

            }
            else
                q="n";
        }while (q=="y" || q=="Y");
    SetFileAttributes("Donnees.txt",FILE_ATTRIBUTE_NORMAL);
    remove("Donnees.txt");
    ofstream d("Donnees.txt",ios::out);
    if (d)
    {
        if (mi<10) d << "0";
        d << mi << " " ;
        if (ma <10) d << "00";
        if (ma <100 && ma>=10) d << "0";
        d << ma;
        if (m.size()!=0)
        {
        for (it=m.begin();it!=m.end();++it)
        {
            temp=*it;
            d << endl ;
            d << temp ;
        }
        }
        d.close();
        if (m.size()!=0)
        output(m);
        c(253);cout << "\n\nEst-ce que vous voulez ajouter des membres?\n";
        c(248);cout << "Entrez 'y' si oui,autre sinon:";
        getline(cin,q);sansEspace(q);
        if (q=="y" || q=="Y")
           ajout(m,mi,ma);
        hide();
    }
    else
    {c(252);cout << "\nUNE ERREUR EST SURVENUE\n";}
}

void condition(list<Personne> &m,int mi,int ma)
{
    string s;
    int i;
    Personne temp;
    list<Personne>::iterator it;
    c(240);cout << "\nMODIFICATION:";
       mi:
       c(246);cout << "\n-Age minimum:" ;c(248);
       getline(cin,s);sansEspace(s);
       mi=stringToInt(s);
       if (mi==0)
       {
           c(252);cout << "Entrer un entier strictement positif\n";
           goto mi;
       }
       if (mi>=100)
       {
           c(252);cout << "N' exag\202rez pas!!!\n";
           goto mi;
       }
        ma:
       c(246);cout << "\n-Age maximum:" ;c(248);
       getline(cin,s);sansEspace(s);
       ma=stringToInt(s);
       if (ma==0 || ma<mi)
       {
           c(252);cout << "Entrer un entier sup\202rieur ou \202gal \205 l '\203ge minimum\n";
           goto ma;
       }
       if (ma>=150)
       {
           c(252);cout << "N' exag\202rez pas!!!\n";
           goto ma;
       }
    if (m.size()!=0)
    {
    c(240);cout << "\nVoulez-vous que la liste soit modifi\202e \205 partir de ces donn\202es?\n";
    c(244);cout << "(y si oui, autre si non):";
    c(248);getline(cin,s);sansEspace(s);
    }
    else
        s=="n";
    SetFileAttributes("Donnees.txt",FILE_ATTRIBUTE_NORMAL);
    remove("Donnees.txt");
    ofstream d("Donnees.txt",ios::out);
    if (d)
    {
        if (s=="y")
        {
            it=m.begin();
            i=0;
            do
            {
                i+=1;
                temp=*it;
                if (temp.getage()<mi || temp.getage()>ma)
                {
                    m.erase(it);
                    it=m.begin();
                    for (int j=1;j<i;j++)
                        ++it;
                    i=0;
                }
                else
                    ++it;
            }while (it!=m.end());
        }
            if (mi<10) d << "0";
            d << mi << " " ;
            if (ma <10) d << "00";
            if (ma <100 && ma>=10) d << "0";
            d << ma;
            if (m.size()!=0)
            {
            for (it=m.begin();it!=m.end();++it)
            {
                temp=*it;
                d << endl ;
                d << temp ;
            }
            }
            d.close();
            hide();
            if (m.size()!=0)
                output(m);
            else
                error_size();
            c(253);cout << "\nEntrez ";c(240);cout << 1;c(253);cout <<" si vous voulez ajouter des membres , ";
            if(m.size()!=0)
            {c(240);cout << 2 ;c(253);cout << " pour retirer un membre et";}
            cout << " autre pour continuer sans rien faire:";
            c(248);getline(cin,s);
            sansEspace(s);
            if (s=="1")
                ajout(m,mi,ma);
            if (s=="2" && m.size()!=0)
                suppression(m,mi,ma);

    }
    else
    {c(12);cout << "\nUNE ERREUR EST SURVENUE\n";}
}
