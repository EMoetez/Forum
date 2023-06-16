#include "Site.h"
#ifndef RUBRIQUE_H
#define RUBRIQUE_H
#include<string>
#include <fstream>
#include<vector>
using namespace std;
class Rubrique
{
    public:
        Rubrique() {}
        Rubrique(string t, string dc, string ae,int id_rubrique_);
        string getTheme() const;
        string getDateCreation() const;
        string getAdresseEmailAnimateur() const;
        int getIDRubrique() const;
        void setTheme(string t);
        void setDateCreation(string dc);
        void setAdresseEmailAnimateur(string ae);
void setId(int aee);

        void ajouterSite(const Site& );
        const vector<Site> getSites() const;

        virtual ~Rubrique();
        friend ostream&operator<<(ostream&out,Rubrique&r);
        friend istream&operator>>(istream&in,Rubrique&r);
        void sauvegarder(const Rubrique&);
        void  rechercher_rubrique_par_id(int id_rub_rech);
        void AfficherRubrique(int id);
        void supprimer_rubrique_(int id_r);



    private:
        string theme;
        string dateCreation;
        string adresseEmailAnimateur;
        vector<Site> listeSitesInternet;
        int id_rubrique;

};

#endif // RUBRIQUE_H
