#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <string>
#include <vector>
void intro();
void aujourdhui(int const);
std::string quest(int &exec);
void outro();
void nombre(int &n,int &m,int &M);
void recueil(std::ofstream &,std::list<Personne> &,int const,int const);
void output (std::list<Personne> m);
Personne minimal(std::list<Personne>);
Personne maximal(std::list<Personne>);
std::vector<Personne> stock(Personne const,std::list<Personne>);
void affichage (int i,std::vector<Personne> m);
void affichage_final(Personne const,Personne const,std::list<Personne> const);
int nb(std::ifstream &,int &,int &);
void recuperation(std::list<Personne> &);
std::string choix(std::list<Personne>);
void hide();
void ajout(std::list<Personne> &,int const ,int const);
void error_size();
void suppr(int const ,std::list<Personne> &);
void suppression(std::list<Personne> &,int const ,int const);
void condition(std::list<Personne> &,int,int);
bool verification(Personne,std::list<Personne>,int const);
#endif // FONCTION_H_INCLUDED
