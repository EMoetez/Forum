#ifndef ADMIN_H
#define ADMIN_H
#include <Profil.h>
#include<string>
#include<vector>
#include "Auteur.h"
#include <fstream>
#include <sstream>

using namespace std;
class Profil;
class Admin: public Profil
{
    public:
        Admin(int id_pr ,string n,string p,string adr,string dn,string cour ,int n_tel,int verif_admin);
        Admin creer_admin(int id);
        virtual ~Admin();
    protected:
    int Id_profil;
    string nom;
    string prenom;
    string adresse;
    string date_naissance;
    string courriel ;
    int num_de_telephone;
    int verif_Admin;
    vector <Auteur> Liste_auteurs;
    private:
};

#endif // ADMIN_H
