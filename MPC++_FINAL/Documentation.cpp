#include "Documentation.h"
#include <sstream>
Documentation::Documentation(){}
Documentation::~Documentation()
{
}

void Documentation::ajouterSiteARubrique(int id_rubrique, int id_site) {

    ifstream fichier("rubrique.txt");
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier rubrique.txt" << endl;
        return;
    }


    ofstream temp("temp.txt");
    if (!temp) {
        cerr << "Erreur : impossible d'ouvrir le fichier temporaire" << endl;
        fichier.close();
        return;
    }


    bool rubriqueTrouvee = false;
    string ligne;
    while (getline(fichier, ligne)) {
        int idR;
        istringstream iss(ligne);
        iss >> idR;
        if (idR == id_rubrique) {

            string siteAttributs;
            while (iss >> siteAttributs) {

            }


            ifstream fichierSite("site.txt");
            if (!fichierSite) {
                cerr << "Erreur : impossible d'ouvrir le fichier site.txt" << endl;
                return;
            }
            string siteLigne;
            bool siteTrouve = false;
            while (getline(fichierSite, siteLigne)) {
                int idS;
                string url, responsable;
                istringstream issSite(siteLigne);
                issSite >> idS >> url >> responsable;
                if (idS == id_site) {

                    ostringstream oss;
                  oss << idS;
                  string idS_str = oss.str();
                    siteAttributs = "|" + idS_str + url + responsable;
                    rubriqueTrouvee = true;
                    siteTrouve = true;
                    break;
                }
            }
            if (!siteTrouve) {
                cerr << "Erreur : impossible de trouver le site avec l'identifiant " << id_site << endl;
                return;
            }


            temp << ligne.substr(0, ligne.find_last_of('|')) << siteAttributs << endl;

        } else {

            temp << ligne << endl;
        }
    }

    fichier.close();
    temp.close();


    remove("rubrique.txt");
    rename("temp.txt", "rubrique.txt");

    if (!rubriqueTrouvee) {
        cerr << "Erreur : impossible de trouver la rubrique avec l'identifiant " << id_rubrique << endl;
        return;
    }
}









void Documentation::supprimerSiteDeRubrique(int id_site) {
    ostringstream oss;
                  oss << id_site;
                  string idS_str = oss.str();

    ifstream fichier("rubrique.txt");
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier rubrique.txt" << endl;
        return;
    }


    ofstream temp("temp.txt");
    if (!temp) {
        cerr << "Erreur : impossible d'ouvrir le fichier temporaire" << endl;
        fichier.close();
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        string partie;
        string nouvelleLigne;
        bool siteTrouve = false;

        while (getline(iss, partie, '|')) {
            if (partie == idS_str) {

                siteTrouve = true;
                for (int i = 0; i < 3; i++) {
                    getline(iss, partie, '|');
                }
            } else {

                nouvelleLigne += partie + "|";
            }
        }
        if (siteTrouve) {

            temp << nouvelleLigne.substr(0, nouvelleLigne.size() - 1) << endl;
        } else {

            temp << ligne << endl;
        }
    }


    fichier.close();
    temp.close();


    if (remove("rubrique.txt") != 0) {
        cerr << "Erreur : impossible de supprimer le fichier rubrique.txt" << endl;
        return;
    }
    if (rename("temp.txt", "rubrique.txt") != 0) {
        cerr << "Erreur : impossible de renommer le fichier temp.txt en rubrique.txt" << endl;
        return;
    }
}
