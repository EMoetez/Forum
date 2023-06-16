#include "Rubrique.h"
#include<string>
#include<vector>
#include <sstream>
#include<iostream>
#include <fstream>
#include<ostream>
using namespace std;

Rubrique::Rubrique(string t, string dc, string ae,int id_rubrique_)
{
theme = t;
dateCreation = dc;
adresseEmailAnimateur = ae;
id_rubrique=id_rubrique_;
}
int Rubrique::getIDRubrique()const{return id_rubrique;}
string Rubrique::getTheme() const { return theme; }
string Rubrique::getDateCreation() const { return dateCreation; }
string Rubrique::getAdresseEmailAnimateur() const { return adresseEmailAnimateur; }
void Rubrique:: setTheme(string t) { theme = t; }
void Rubrique::setDateCreation(string dc) { dateCreation = dc; }
void Rubrique::setAdresseEmailAnimateur(string ae) { adresseEmailAnimateur = ae; }
void Rubrique::setId(int aee) { id_rubrique = aee; }



 istream& operator>>(istream& in, Rubrique& r) {
    string t;
    string dateCre;
    string emailAnim;
    cout <<endl;
    int id;

     cout << "Saisir le ID de la rubrique : ";
    in >> id;
    r.setId(id);

    cout << "Saisir le theme de la rubrique : ";
    in >> t;
    r.setTheme(t);

    cout << "Saisir la date de creation de la rubrique : ";
    in >> dateCre;
    r.setDateCreation(dateCre);

    cout << "Saisir l adresse email de l animateur : ";
    in >> emailAnim;
    r.setAdresseEmailAnimateur(emailAnim);
   /* Site s;
    cin >> s;
    r.ajouterSite(s);*/
    return in;
}


void Rubrique::ajouterSite(const Site& site) {
    listeSitesInternet.push_back(site);
}

const vector<Site> Rubrique::getSites() const {
    return listeSitesInternet;
}

ostream& operator<<(ostream& out, Rubrique& r) {
    out << " le theme de la rubrique            : "<<r.theme<<endl;

    out << " la date de creation de la rubrique : "<<r.dateCreation<<endl;

    out << " l adresse email de l animateur     : "<< r.adresseEmailAnimateur<<endl;
    for(unsigned i=0;i<r.listeSitesInternet.size();i++)
    {
        cout << r.listeSitesInternet[i];
    }

    return out;
}

Rubrique::~Rubrique(){}

void Rubrique:: sauvegarder(const Rubrique& r) {
    //Site s;
    ofstream fichier("rubrique.txt", ios::app);
    if (fichier) {
        fichier << r.id_rubrique <<"|"<<r.theme<<"|"<<r.dateCreation <<  "|"<<r.adresseEmailAnimateur<<  "|" <<endl;
        fichier.close();
        cout << "La rubrique a ete sauvegarde dans le fichier rubriques.txt." << endl;
    }
    else {
        cerr << "Erreur : impossible d'ouvrir le fichier rubriques.txt." << endl;
    }
}

void Rubrique::  rechercher_rubrique_par_id(int id_rub_rech) {
      Site s;
    ifstream fichier("rubrique.txt");
    if (fichier.is_open()) {
        string ligne;
        while (getline(fichier, ligne))
            {
                  stringstream sos(ligne);
                  string theme_;
                  string dateCreation_;
                  string adresseEmailAnimateur_;
                  int id_rubrique_;

                  sos >> id_rubrique_;
                  sos.ignore();
                  getline(sos, theme_, '|');
                  getline(sos, dateCreation_, '|');
                  getline(sos, adresseEmailAnimateur_, '|');


                  if (id_rubrique_== id_rub_rech)
                       {
                          theme= theme_;
                          dateCreation= dateCreation_;
                          adresseEmailAnimateur =adresseEmailAnimateur_;
                          id_rubrique=id_rubrique_;

                          }}
        fichier.close();}}

void Rubrique::AfficherRubrique(int id_rubrique) {
    ifstream fichier("rubrique.txt");
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier rubrique.txt" << endl;
        return;
    }


    string ligne;
    bool rubriqueTrouvee = false;
    while (getline(fichier, ligne)) {
        int idR;
        istringstream iss(ligne);
        iss >> idR;
        if (idR == id_rubrique) {

            rubriqueTrouvee = true;
            cout << "Rubrique :" << endl;
            cout << "ID : " << idR << endl;


            string theme, dateCreation, adresseEmailAnimateur;
            iss.ignore();
            getline(iss, theme, '|');
            getline(iss, dateCreation, '|');
            getline(iss, adresseEmailAnimateur, '|');
            cout << "Theme : " << theme << endl;
            cout << "Date de creation : " << dateCreation << endl;
            cout << "Adresse email de l'animateur : " << adresseEmailAnimateur << endl;


            vector<pair<int, pair<string, string> > > sitesAssocies;
            int idSite;
            string url, responsable;
            while (iss >> idSite) {
                iss.ignore();
                getline(iss, url, '|');
                getline(iss, responsable, '|');
                sitesAssocies.push_back(make_pair(idSite, make_pair(url, responsable)));
            }


            cout << "Sites associes :" << endl;
            for (unsigned int  i = 0; i < sitesAssocies.size(); i++) {
    const pair<int, pair<string, string> >& site = sitesAssocies[i];
                cout << "ID : " << site.first << endl;
                cout << "URL : " << site.second.first << endl;
                cout << "Adresse email du responsable : " << site.second.second << endl;
            }

            break;
        }
    }

    if (!rubriqueTrouvee) {
        cout << "La rubrique avec l'ID " << id_rubrique << " n'a pas été trouvée." << endl;
    }
}




#include <algorithm>

void Rubrique::supprimer_rubrique_(int id_r) {
    fstream fichier("rubrique.txt", ios::in | ios::out);
    if (fichier) {
        ofstream temp("temp.txt");
        string ligne;
        while (getline(fichier, ligne)) {
            stringstream sos(ligne);
                   string theme_;
                   string dateCreation_;
                   string adresseEmailAnimateur_;
                   int id_rubrique_;
                  sos >> id_rubrique_;
                  sos.ignore();
                  getline(sos, theme_, '|');
                  getline(sos, dateCreation_, '|');
                  sos.ignore();
                  getline(sos, adresseEmailAnimateur_, '|');

            if (id_r != id_rubrique_) {
                temp << ligne << endl;
            }
        }
        temp.close();
        fichier.close();
        remove("rubrique.txt");
        rename("temp.txt", "rubrique.txt");

        cout << "La rubrique avec l'ID " << id_r << " a ete supprime." << endl;
    } else {
        cout << "Erreur : impossible d'ouvrir le fichier rubrique.txt." << endl;
    }
}

