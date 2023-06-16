#include <sstream>
#include <iostream>
#include "Message.h"
#include<string>
#include<vector>
#include <fstream>
using namespace std;

Message :: Message(int id_a,string t ,string cont,int id ,string date_pub,int id_rubrique,int Id_rep)
{
     id_rub= id_rubrique;
     titre=t;
     id_auteur=id_a;
     contenu= cont;
     id_message= id;
     date_publication=date_pub;
     Id_mss_repondue=Id_rep;
    //ctor
}

void Message::rechercher_message_rep_par_id(int id_mssg_rep) {
    vector<Message> resultats;
    ifstream fichier("Messages.txt");
    if (fichier.is_open()) {
        string ligne;
        int comp_elts=0;
        while (getline(fichier, ligne))
            {
                  stringstream ss(ligne);
                  int id_a , id_m , id_r, id_rb ;
                  string t , cont, d_p;
                  ss >> id_a;
                  ss.ignore();
                  getline(ss, t, '|');
                  getline(ss, cont, '|');
                  ss >> id_m;
                  ss.ignore();
                  getline(ss, d_p, '|');
                  ss >> id_rb;
                  ss.ignore();
                  ss >> id_r;
                  if (id_r == id_mssg_rep)
                       {
                          comp_elts++;
                          Message m(id_a, t, cont, id_m, d_p,id_rb ,id_r);
                          m.afficher();
                       }
            }
         if (comp_elts==0)
            {cout<<"Pas de reponses a ce message! "<<endl;}
        fichier.close();
    }
    //return resultats;
}


void Message::  rechercher_message_par_id(int id_mssg_rech) {
   // Message resultat;
    ifstream fichier("Messages.txt");
    if (fichier.is_open()) {
        string ligne;
        while (getline(fichier, ligne))
            {
                  stringstream sos(ligne);
                  int id_r, id_rb;
                  int id_a ;
                  int  id_m ;

                  string t ;
                  string cont;
                  string d_p;
                  sos >> id_a;
                  sos.ignore();
                  getline(sos, t, '|');
                  getline(sos, cont, '|');
                  sos >> id_m;
                  sos.ignore();
                  getline(sos, d_p, '|');
                  sos >> id_rb;
                  sos.ignore();
                  sos >> id_r;

                  if (id_m == id_mssg_rech)
                       {
                         // Message resultat(id_a, t, cont, id_m, d_p, id_r);
                          id_auteur= id_a;
                          titre= t;
                          contenu =cont;
                          id_message = id_m;
                          date_publication =  d_p;
                          id_rub = id_rb;
                          Id_mss_repondue = id_r;

                       }

            }
        fichier.close();
    }
    //return resultat;
}






Message Message:: creer_message(int id_a) {
    int  id_r,id_mes, id_rb;
    string t, cont, d_p;

    cout << "Saisissez le titre du message : ";
    for(int i = 0; i < 29; i++)
                        {
                           cout <<endl;
                        }
    cin.ignore();
    getline(cin, t);
    cout << "Saisissez le contenu du message : ";
    for(int i = 0; i < 29; i++)
                        {
                           cout <<endl;
                        }
    getline(cin, cont);
    cout << "Saisissez l'ID du message  : ";
    for(int i = 0; i < 29; i++)
                        {
                           cout <<endl;
                        }
    cin >> id_mes;
    cout << "Saisissez la date de publication du message (format jj/mm/aaaa) : ";
    for(int i = 0; i < 29; i++)
                        {
                           cout <<endl;
                        }
    cin.ignore();
    getline(cin, d_p);
    cout << "Saisissez l'ID du rubrique  : ";
    for(int i = 0; i < 29; i++)
                        {
                           cout <<endl;
                        }
    cin >> id_rb;
    cout << "Saisissez l'ID du message en reponse (-1 si aucun) : ";
    for(int i = 0; i < 29; i++)
                        {
                           cout <<endl;
                        }
    cin >> id_r;

    Message mss(id_a, t, cont, id_mes, d_p, id_rb ,id_r);
    ofstream fichier("Messages.txt", ios::app); // ouverture du fichier en mode ajout
    if (fichier) { // si le fichier est ouvert avec succès
        fichier << mss.id_auteur <<"|" <<mss.titre <<  "|"<<mss.contenu <<"|" <<mss.id_message <<"|" <<mss.date_publication <<"|"<<mss.id_rub<<"|"<<mss.Id_mss_repondue << endl;
        fichier.close(); // fermeture du fichier
        cout << "Le message a été sauvegardé dans le fichier Messages.txt." << endl;
    }
    else {
        cerr << "Erreur : impossible d'ouvrir le fichier Messages.txt." << endl;
    }
    return mss;
}


void Message::afficher() const
            {
               cout<<"________________________________________"<<endl;
               cout << "ID auteur :             " << id_auteur << endl;
               cout<<"________________________________________"<<endl;
               cout << "Titre :            " << titre << endl;
               cout<<"________________________________________"<<endl;
               cout << "Contenu :              " << contenu << endl;
               cout<<"________________________________________"<<endl;
               cout << "ID du message :        " << id_message << endl;
               cout<<"________________________________________"<<endl;
               cout << "Date de publication :       " << date_publication << endl;
               cout<<"________________________________________"<<endl;
               cout << "ID de la rubrique :          " << id_rub << endl;

               cout<<"________________________________________"<<endl;

               cout << "ID de la réponse :          " << Id_mss_repondue << endl;
               cout<<"________________________________________"<<endl;

            }



void Message:: sauvegarder_message(const Message& mss) {
    ofstream fichier("Messages.txt", ios::app); // ouverture du fichier en mode ajout
    if (fichier) { // si le fichier est ouvert avec succès
        fichier << mss.id_auteur <<"|" <<mss.titre <<  "|"<<mss.contenu <<"|" <<mss.id_message <<"|" <<mss.date_publication <<"|"<<mss.id_rub<<"|"<<mss.Id_mss_repondue << endl;
        fichier.close(); // fermeture du fichier
        cout << "Le message a été sauvegardé dans le fichier Messages.txt." << endl;
    }
    else {
        cerr << "Erreur : impossible d'ouvrir le fichier Messages.txt." << endl;
    }
}
void Message:: afficher_messages_du_jour(string date_p)
{
     ifstream fichier("Messages.txt");
     if (fichier.is_open()) {
        string ligne;
        while (getline(fichier, ligne))
            {
                  stringstream sos(ligne);
                  int id_a ,id_rb;
                  int  id_m ;
                  int  id_r ;
                  string t ;
                  string cont;
                  string d_p;
                  sos >> id_a;
                  sos.ignore();
                  getline(sos, t, '|');
                  getline(sos, cont, '|');
                  sos >> id_m;
                  sos.ignore();
                  getline(sos, d_p, '|');
                  sos >> id_rb;
                  sos.ignore();
                  sos >> id_r;

                  if (d_p == date_p)
                       {
                         // Message resultat(id_a, t, cont, id_m, d_p, id_r);
                          id_auteur= id_a;
                          titre= t;
                          contenu =cont;
                          id_message = id_m;
                          date_publication =  d_p;
                          id_rub = id_rb;
                          Id_mss_repondue = id_r;

                       }

            }
        fichier.close();
    }
}

void Message::supprimer_message_fichier(int id_message) {
    // Ouvrir le fichier en lecture et en écriture
    fstream fichier("Messages.txt", ios::in | ios::out);
    if (fichier) {
        // Copier les lignes non concernées dans un nouveau fichier temporaire
        ofstream temp("temp.txt");
        string ligne;
        while (getline(fichier, ligne)) {
            stringstream sos(ligne);
                  int id_a ,id_rb;
                  int  id_m ;
                  int  id_r ;
                  string t ;
                  string cont;
                  string d_p;
                  sos >> id_a;
                  sos.ignore();
                  getline(sos, t, '|');
                  getline(sos, cont, '|');
                  sos >> id_m;
                  sos.ignore();
                  getline(sos, d_p, '|');
                  sos >> id_rb;
                  sos.ignore();
                  sos >> id_r;

            if (id_m != id_message) {
                temp << ligne << endl;
            }
        }
        temp.close();
        fichier.close();

        // Remplacer le fichier d'origine par le fichier temporaire
        remove("Messages.txt");
        rename("temp.txt", "Messages.txt");

        cout << "Le message avec l'ID " << id_message << " a été supprimé." << endl;
    } else {
        cout << "Erreur : impossible d'ouvrir le fichier Messages.txt." << endl;
    }
}

Message::~Message()
{
    //dtor
}
