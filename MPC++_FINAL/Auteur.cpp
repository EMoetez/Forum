#include <iostream>
#include "Auteur.h"
#include "Message.h"
#include<string>
#include<vector>
#include <fstream>
#include <sstream>

using namespace std ;

Auteur::Auteur(int id_aut,string ps, int nbr_mssg , string dpm, string ddm)
{
   id_auteur=id_aut;
   Pseudo = ps;
   nbr_de_messages = nbr_mssg;
   date_premier_message = dpm;
   date_dernier_message = ddm;

    //ctor
}



Auteur Auteur:: creer_auteur()
{
     int id_aut;
     string Ps;
     int ndm=0;
     string pr_mssg;
     string dr_mssg;

    cout << "Saisissez l'ID du l'auteur : ";
    cin >> id_aut;
    cout << "Saisissez le Pseudo de l'auteur : ";
    cin>>Ps;
    cout << "Saisissez la date du premier message : ";
    cin>>pr_mssg;
    cout << "Saisissez la date du dernier message ";
    cin>>dr_mssg;
    Auteur nouv_auteur(id_aut, Ps, ndm, pr_mssg,dr_mssg);

    ofstream fichier("Auteurs.txt", ios::app); // ouverture du fichier en mode ajout
    if (fichier) { // si le fichier est ouvert avec succès
        fichier << nouv_auteur.id_auteur <<"|" <<nouv_auteur.Pseudo <<  "|"<<nouv_auteur.nbr_de_messages <<"|" << nouv_auteur.date_premier_message <<"|" <<nouv_auteur.date_dernier_message <<endl;
        fichier.close(); // fermeture du fichier
        cout << "Le message a été sauvegardé dans le fichier Auteurs.txt." << endl;
    }
    else {
        cerr << "Erreur : impossible d'ouvrir le fichier Auteurs.txt." << endl;
    }
    return nouv_auteur;
}



void Auteur::chercher_un_auteur(int IdAuteur_rech)
{
ifstream fichier("Auteurs.txt");
    if (fichier.is_open())

        {
        string ligne;
        while (getline(fichier, ligne))
            {
                  stringstream sos(ligne);
                  int id_A ;
                  int  nbr_m ;
                  string p ;
                  string d_p_m;
                  string d_d_m;
                  sos >> id_A;
                  sos.ignore();
                  getline(sos, p, '|');
                  sos>>nbr_m;
                  sos.ignore();
                  getline(sos, d_p_m, '|');
                  getline(sos, d_d_m, '|');
                  if (id_A == IdAuteur_rech)
                       {
                          id_auteur=id_A;
                          Pseudo = p;
                          nbr_de_messages = nbr_m;
                          date_premier_message = d_p_m;
                          date_dernier_message = d_d_m;
                       }
            }
        fichier.close();
    }
}



void Auteur::afficher_auteur()const
{
               cout<<"_______________________________________________"<<endl;
               cout << "ID Auteur            :     " << id_auteur << endl;
               cout<<"_______________________________________________"<<endl;
               cout << "Pseudo               :     " << Pseudo << endl;
               cout<<"_______________________________________________"<<endl;
               cout << "Nombre de messages   :     "<< endl;
               cout<<"_______________________________________________"<<endl;
               cout << "date premier message :     " << date_premier_message << endl;
               cout<<"_______________________________________________"<<endl;
               cout<<"  date du dernier message :  " << date_dernier_message << endl;
               cout<<"_______________________________________________"<<endl;

}

void  Auteur::sauvegarder_auteur(Auteur & a)
{
  ofstream fichier("Auteurs.txt", ios::app); // ouverture du fichier en mode ajout
    if (fichier) { // si le fichier est ouvert avec succès
        fichier << a.id_auteur <<"|" <<a.Pseudo <<  "|"<<a.nbr_de_messages <<"|" << a.date_premier_message <<"|" <<a.date_dernier_message <<endl;
        fichier.close(); // fermeture du fichier
        cout << "Le message a été sauvegardé dans le fichier Messages.txt." << endl;
    }
    else {
        cerr << "Erreur : impossible d'ouvrir le fichier Messages.txt." << endl;
    }
}

void Auteur::supprimer_auteur(int ia)
{
 // Ouvrir le fichier en lecture et en écriture
    fstream fichier("Auteurs.txt", ios::in | ios::out);
    if (fichier) {
        // Copier les lignes non concernées dans un nouveau fichier temporaire
        ofstream temp("temp.txt");
        string ligne;
        while (getline(fichier, ligne)) {
                 stringstream sos(ligne);
                  int id_A ;
                  int  nbr_m ;
                  string p ;
                  string d_p_m;
                  string d_d_m;
                  sos >> id_A;
                  sos.ignore();
                  getline(sos, p, '|');
                  sos>>nbr_m;
                  sos.ignore();
                  getline(sos, d_p_m, '|');
                  getline(sos, d_d_m, '|');
            if (ia != id_A) {
                temp << ligne << endl;
            }
        }
        temp.close();
        fichier.close();

        // Remplacer le fichier d'origine par le fichier temporaire
        remove("Auteurs.txt");
        rename("temp.txt", "Auteurs.txt");

        cout << "Le message avec l'ID " << ia << " a été supprimé." << endl;
    } else {
        cout << "Erreur : impossible d'ouvrir le fichier Messages.txt." << endl;
    }
}




Auteur::~Auteur()
{
    //dtor
}
