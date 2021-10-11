#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <string>
struct Date
{
    int jour;
    int mois;
    std::string s_mois;
    int annee;
};
class Personne
{
public:
    Personne();        //constructeur
    ~Personne();       //destructeur

    void setnom(std::string);
    void setnaissance(Date);
    std::string getnom();
    Date getnaissance();
    int getage();
    std::string getsex();

    bool memeAge(Personne const &) const;
    bool plusJeune(Personne const &) const;

protected:
    std::string nom;
    Date naissance;
    std::string sexe;
    int age;

friend std::istream& operator >> (std::istream &,Personne &);
friend std::ostream& operator << (std::ostream &,Personne &);
friend std::ofstream& operator << (std::ofstream &,Personne &);
friend std::ifstream& operator >> (std::ifstream &,Personne &);
};

bool operator == (Personne const&,Personne const&);
bool operator != (Personne const&,Personne const&);
bool operator <  (Personne const&,Personne const&);
bool operator >  (Personne const&,Personne const&);
bool operator <= (Personne const&,Personne const&);
bool operator >= (Personne const&,Personne const&);

//Prototypes des fonctions utilisées
void c(int x);
std::string recueil_nom();
int recueil_annee();
int search_age(int const a);
std::string recueil_mois(int const);
int recueil_jour(int const,int const);
int moisToInt(std::string const);
std::string intToMois(int const);
std::string spacer(std::string const);
int stringToInt(std::string const);
std::string finale(std::string);
void sansEspace(std::string &);
bool test(std::string const);

#endif // PERSONNE_H_INCLUDED
