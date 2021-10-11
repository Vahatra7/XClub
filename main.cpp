#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <list>
#include "Personne.h"
#include "Fonction.h"
#define erreur c(252);cout << endl << "\n\n\tDESOLE,UNE ERREUR EST SURVENUE DANS LE SYSTEME\n\n";
#define press c(247);cout << "\n\nAppuyez sur ENTRER pour continuer";
#define h hide();
#define enter getch();cout << endl ;
using namespace std;

int main()
{

    string quit,rep;
    Personne jeune,agE;
    int exec=1,n,m,M;
    intro();
    system("color F0");
    do
    {
    aujourdhui(exec);

    ifstream exist("Donnees.txt",ios::in);

    if (!exist)
    {
        ofstream donnees("Donnees.txt",ios::out);
        if(!donnees)
        {erreur goto sortie;}
        else
        {
            nombre(n,m,M);h
            list<Personne> membre(n);
            recueil(donnees,membre,m,M);
            press enter
            output(membre);
            jeune=minimal(membre);
            agE =maximal(membre);
            affichage_final(jeune,agE,membre);
            donnees.close();
        }
    }
    else
    {
        n=nb(exist,m,M);
        exist.close();
        list<Personne> membre(n);
        recuperation(membre);

        rep=choix(membre);

        if (rep=="2")
            ajout(membre,m,M);
        if (rep=="3")
            suppression(membre,m,M);
        if (rep=="1")
            condition(membre,m,M);

        if (membre.size()==0)
        {
            error_size();
            goto sortie;
        }
            output(membre);

        jeune=minimal(membre);
        agE=maximal(membre);
        affichage_final(jeune,agE,membre);
    }
    sortie:
    quit=quest(exec);
    }while (quit=="y" || quit=="Y");
    outro();
    return 0;
}
