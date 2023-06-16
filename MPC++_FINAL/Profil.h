#ifndef PROFIL_H
#define PROFIL_H
#include<string>
#include<vector>
#include "Auteur.h"
#include <fstream>
#include <sstream>

using namespace std;
class Profil
{
    public:
        Profil(int id_pr ,string n,string p,string adr,string dn,string cour ,int n_tel);
        Profil creer_profil(int id);
        void chercher_profil_par_id(int id_pr);
        void afficher_profil() const;
        void sauvegarder_profil(const Profil& Pr);
        void chercher_mssg_profil(int id_pr);
        void supprimer_profil(int id_pr_supp);
        //void ajouter_auteur(Auteur A);
        virtual ~Profil();
    protected:
    int Id_profil;
    string nom;
    string prenom;
    string adresse;
    string date_naissance;
    string courriel ;
    int num_de_telephone;
    vector <Auteur> Liste_auteurs;
    private:
};

#endif // PROFIL_H

