#include "Site.h"
#include<iostream>
#include <sstream>
using namespace std;
Site::Site(){}
Site::Site(string ai, string aer,int id=0)
{
    adresseInternet = ai;
    adresseEmailResponsable = aer;
    id_site=id;
}
Site::~Site(){}
int Site::getIDSite()const{return id_site; }
string Site:: getAdresseInternet() const { return
adresseInternet; }
string Site:: getAdresseEmailResponsable() const { return adresseEmailResponsable; }
void Site:: setAdresseInternet(string ai) { adresseInternet = ai; }
void Site::setAdresseEmailResponsable(string aer) { adresseEmailResponsable = aer; }
void Site::setId(int id) { id_site = id; }
istream& operator>>(istream& in, Site& s) {
    string url;
    string urlresp;
    int id;

    cout << "Saisir le id site : ";
    in >> id;
    s.setId(id);

    cout << "Saisir le url : ";
    in >> url;
    s.setAdresseInternet(url);

    cout << "Saisir le url responsable : ";
    in >> urlresp;
    s.setAdresseEmailResponsable(urlresp);

     return in;
}

ostream& operator<<(ostream& out, Site& s){
    out<<" l'ID site est                        : "<<s.getIDSite()<<endl;
    out << " l adresse internet                 : "<<s.adresseInternet<<endl;
    out << " le createur de adresse internet    : "<<s.adresseEmailResponsable<<endl;
    return out;
}


void Site:: sauvegarder(const Site& s) {
    ofstream fichier("site.txt", ios::app);
    if (fichier) {
        fichier <<s.id_site<<"|"<<s.adresseInternet<<"|" << s.adresseEmailResponsable<<"|"<<endl;
        fichier.close();
        cout << "Le site a ete sauvegarde dans le fichier site.txt." << endl;
    }
    else {
        cerr << "Erreur : impossible d'ouvrir le fichier site.txt." << endl;
    }
}


void Site::  rechercher_site_par_id(int id_site_rech) {

    ifstream fichier("site.txt");
    if (fichier.is_open()) {
        string ligne;
        while (getline(fichier, ligne))
            {
                  stringstream sos(ligne);
                  string adresseInternet_;
                  string adresseEmailResponsable_;
                  int id_site_;
                  sos >> id_site_;
                  sos.ignore();
                  getline(sos, adresseInternet_, '|');
                  getline(sos, adresseEmailResponsable_, '|');
                  if (id_site_== id_site_rech)
                       {
                          adresseInternet= adresseInternet_;
                          adresseEmailResponsable= adresseEmailResponsable_;
                          id_site=id_site_;
                          }}
        fichier.close();}}

void Site:: afficher_site()

{
        cout << " le url  est               : "<<adresseInternet<<endl;
    cout << " le email responsable est  : "<<adresseEmailResponsable<<endl;
}


void Site::supprimer_site_(int id_s) {

    fstream fichier("site.txt", ios::in | ios::out);
    if (fichier) {
        ofstream temp("temp.txt");
        string ligne;
        while (getline(fichier, ligne)) {
            stringstream sos(ligne);
                   string adresseInternet_;
        string adresseEmailResponsable_;
        int id_site_;
                  sos >> id_site_;
                  sos.ignore();
                  getline(sos, adresseInternet_, '|');
                  getline(sos, adresseEmailResponsable_, '|');
                  sos.ignore();

            if (id_s != id_site_) {
                temp << ligne << endl;
            }
        }
        temp.close();
        fichier.close();
        remove("site.txt");
        rename("temp.txt", "site.txt");

        cout << "Le site avec l'ID " << id_s << " a ete supprime." << endl;
    } else {
        cout << "Erreur : impossible d'ouvrir le fichier Messages.txt." << endl;
    }
}
