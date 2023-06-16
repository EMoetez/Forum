#include "Admins.h"
#include "Profil.h"
#include <fstream>
#include <string>

using namespace std;
Admin::Admin(int Id_profil, string nom, string prenom, string adresse, string date_naissance, string courriel, int num_de_telephone, int id_Admin)
    : Profil(Id_profil, nom, prenom, adresse, date_naissance, courriel, num_de_telephone) {
    id_admin = id_Admin;
}



Admin::~Admin() {
}

void Admin::creeAdmin() const {
    ofstream outputFile("Admin.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << Id_profil << "|" << nom << "|" << prenom << "|" << adresse << "|" << date_naissance << "|" << courriel << "|" << num_de_telephone << "|" << id_admin << endl;
        outputFile.close();
        cout << "Les informations de l'administrateur ont été enregistrées dans " << "Admin.txt" << endl;
    } else {
        cout << "Impossible d'ouvrir le fichier " << "Admin.txt" << endl;
    }
}

