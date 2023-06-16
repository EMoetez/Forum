#include "Admin.h"
#include "Profil.h"
#include <string>
#include <vector>
#include "Auteur.h"
#include <fstream>
#include <sstream>

using namespace std;

Admin::Admin()
{
    //ctor
}

Admin::~Admin(){    //dtor
}
Admin::Admin(int id_pr, string n,string p,string adr,string dn,string cour ,int n_tel,int verif_admin):Profil(id_pr, n, p, adr, dn, cour , n_tel)
{
    verif_Admin =verif_admin;

    //ctor
}


Admin  Admin::creer_admin(int id_ )
{
    int  num_tel,id_adm;
    string n, pr,adr,courr, d_n;
    cout << "Saisissez le nom de l'admin : ";
    cin.ignore();
    getline(cin, n);
    cout << "Saisissez le prenom  : ";

    getline(cin, pr);
    cout << "Saisissez l'adresse  : ";
    getline(cin, adr);
    cout<< "Saisissez la date de naissance(format = jj/mm/aaaa):   "<<endl;
    getline(cin, d_n);
    cout << "Saisissez le courriel : "<<endl;
    //cin.ignore();
    getline(cin, courr);
    cout << "Saisissez le numero de telephone  : "<<endl;
    cin >> num_tel;
    getline(cin, courr);
    cout << "Saisissez l'ID admin  : "<<endl;
    cin >> id_adm;

    Admin Ad(id_, n, pr, adr, d_n, courr, num_tel,id_adm);
    ofstream fichier("Admin.txt", ios::app); // ouverture du fichier en mode ajout
    if (fichier)
        { // si le fichier est ouvert avec succès
             fichier << Ad.Id_profil <<"|" <<Ad.nom <<"|"<<Ad.prenom <<"|" <<Ad.adresse<<"|"<<Ad.date_naissance <<"|" <<Ad.courriel <<"|"<<Ad.num_de_telephone << "|"<< Ad.verif_Admin << endl;
             fichier.close(); // fermeture du fichier
             cout << "Le message a été sauvegardé dans le fichier Admin.txt." << endl;
        }
    else
        {
        cerr << "Erreur : impossible d'ouvrir le fichier Admin.txt." << endl;
        }
    return Ad;
}


/*void Profil::ajouter_auteur(Auteur A,int id_profil)
{
 Liste_auteurs.push_back(A);
}










