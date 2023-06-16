#include <iostream>
#ifndef AUTEUR_H
#define AUTEUR_H
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Auteur
{
    public:
        Auteur(int id_aut,string ps, int nbr_mssg , string dpm, string ddm);
        Auteur creer_auteur();
        void afficher_auteur()const;
        void chercher_un_auteur(int IdAuteur_rech);
        //void afficher_les_messages_dun_auteurs();
        void sauvegarder_auteur(Auteur & a);
        void supprimer_auteur(int ia);
        virtual ~Auteur();
   // protected:
        int id_auteur;
        string Pseudo;
        int nbr_de_messages;
        string date_premier_message;
        string date_dernier_message;


    private:
};

#endif // AUTEUR_H
