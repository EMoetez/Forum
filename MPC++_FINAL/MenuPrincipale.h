#ifndef MENUPRINCIPALE_H
#define MENUPRINCIPALE_H
#include"Rubrique.h"
#include"Documentation.h"
#include"Auteur.h"
#include"Message.h"
#include"Profil.h"
#include"Site.h"
#include<string>
#include<vector>
#include <iostream>
#include <ostream>
#include <istream>
#include "Admins.h"




using namespace std;


class Menu_principal
{
    public:
        Menu_principal();
        virtual ~Menu_principal();
        void lancer();
        void lancer_Menu_visiteur();
        void lancer_menu_creation();
        void lancer_menu_principal();
        void afficher_Menu();
        void afficher_menu_rubrique();
        void lancer_Menu_Profils();
        void afficher_Menu_Profils();
        void lancer_Menu_Auteurs();
        void afficher_Menu_Auteurs();
        void lancer_Menu_Messages();
        void afficher_Menu_Messages();
        void afficherProfilsRubrique();
        void creerRubrique() ;
        void afficherMessagesAuteur();
        void afficherMessagesOrdreChronologique();
        int convertirEnEntier(const std::string& str);
        int convertirDateEnNombre(const std::string& date);
        int comparerDates(const std::string& date1, const std::string& date2);
        void trierMessagesParDate(std::vector<Message>& messagess);
        void afficherRubriques() ;
        void afficherSite();
         void gererSites();
         void afficherMessagesRubrique();
         void gererRubriques() ;
         void afficherMessagesJour();
         void ajouterSiteARubrique();
         void sauvegarder(string&);
         void supprimer_rubrique();
         void supprimer_site();
         void creerSite();
         void afficherMessagesRubrique(int id_rub_rech);
        //void afficherMessagesJour();
        // void sauvegarder(string&);
    protected:
    public:
        vector<Rubrique> rubriques;
};

#endif // MENUPRINCIPALE_H
