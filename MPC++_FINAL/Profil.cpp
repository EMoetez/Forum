#include "Profil.h"
#include <string>
#include <vector>
#include "Auteur.h"
#include <fstream>
#include <sstream>

using namespace std;

Profil::Profil(int id_pr, string n,string p,string adr,string dn,string cour ,int n_tel)
{
    Id_profil = id_pr;
    nom= n;
    prenom = p;
    adresse= adr;
    date_naissance=dn;
    courriel = cour;
    num_de_telephone = n_tel;

    //ctor
}


Profil  Profil::creer_profil(int id_ )
{
    int  num_tel;
    string n, pr,adr,courr, d_n;
    cout << "Saisissez le nom du profil : ";
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


    Profil Pr(id_, n, pr, adr, d_n, courr, num_tel);
    ofstream fichier("Profils.txt", ios::app); // ouverture du fichier en mode ajout
    if (fichier)
        { // si le fichier est ouvert avec succès
             fichier << Pr.Id_profil <<"|" <<Pr.nom <<"|"<<Pr.prenom <<"|" <<Pr.adresse<<"|"<<Pr.date_naissance <<"|" <<Pr.courriel <<"|"<<Pr.num_de_telephone << endl;
             fichier.close(); // fermeture du fichier
             cout << "Le message a été sauvegardé dans le fichier Messages.txt." << endl;
        }
    else
        {
        cerr << "Erreur : impossible d'ouvrir le fichier Messages.txt." << endl;
        }
    return Pr;
}


/*void Profil::ajouter_auteur(Auteur A,int id_profil)
{
 Liste_auteurs.push_back(A);
}*/



void Profil::chercher_profil_par_id(int id_pr)
{
ifstream fichier("Profils.txt");
    if (fichier.is_open())

        {
        string ligne;
        while (getline(fichier, ligne))
            {
                stringstream sos(ligne);
                int id_pr_;
                string n_;
                string p_;
                string adr_;
                string dn_;
                string cour_;
                int n_tel_;
                  sos >> id_pr_;
                  sos.ignore();
                  getline(sos, n_,'|');

                  getline(sos, p_ ,'|');

                  getline(sos, adr_ ,'|');

                  getline(sos, dn_ ,'|');

                  getline(sos, cour_,'|');

                  sos >> n_tel_;
                  if (id_pr_ == id_pr)
                       {
                         Id_profil = id_pr_;
                         nom = n_;
                         prenom = p_;
                         adresse = adr_;
                         date_naissance=dn_;
                         courriel = cour_;
                         num_de_telephone = n_tel_;
                       }
            }
        fichier.close();
    }
}


void Profil:: supprimer_profil(int id_pr_supp)
{
 // Ouvrir le fichier en lecture et en écriture
    fstream fichier("Profils.txt", ios::in | ios::out);
    if (fichier) {
        // Copier les lignes non concernées dans un nouveau fichier temporaire
        ofstream temp("temp.txt");
        string ligne;
        while (getline(fichier, ligne)) {
            stringstream sos(ligne);
                  int id_pr_;
                  string n_;
                  string p_;
                  string adr_;
                  string dn_;
                  string cour_;
                  int n_tel_;

                  sos >> id_pr_;
                  sos.ignore();
                  getline(sos, n_, '|');
                  getline(sos, p_, '|');
                  getline(sos, adr_, '|');
                  getline(sos, dn_, '|');
                  getline(sos, cour_, '|');
                  sos >> n_tel_;


            if (id_pr_ != id_pr_supp) {
                temp << ligne << endl;
            }
        }
        temp.close();
        fichier.close();

        // Remplacer le fichier d'origine par le fichier temporaire
        remove("Profils.txt");
        rename("temp.txt", "Profils.txt");

        cout << "Le message avec l'ID " << id_pr_supp << " a été supprimé." << endl;
    } else {
        cout << "Erreur : impossible d'ouvrir le fichier Profils.txt." << endl;
    }
}


void Profil :: chercher_mssg_profil(int id_pr)
{



}


void Profil:: afficher_profil() const
           {
               cout <<"________________________________________"<<endl;
               cout << "ID Profil :             " << Id_profil << endl;
               cout <<"________________________________________"<<endl;
               cout <<"Nom :                   " << nom << endl;
               cout <<"________________________________________"<<endl;
               cout <<"Prenom :                " << prenom << endl;
               cout <<"________________________________________"<<endl;
               cout <<"Adresse:                 "<< adresse<<endl;
               cout <<"________________________________________"<<endl;
               cout <<"date_naissance :         " << date_naissance << endl;
               cout <<"________________________________________"<<endl;
               cout <<"  Courriel :             " << courriel << endl;
               cout <<"________________________________________"<<endl;
               cout <<"num_de_telephone :       " << num_de_telephone << endl;
               cout <<"________________________________________"<<endl;

            }




void Profil ::sauvegarder_profil(const Profil& Pr)
 {
    ofstream fichier("Profils.txt", ios::app); // ouverture du fichier en mode ajout
    if (fichier)
                { // si le fichier est ouvert avec succès
        fichier << Pr.Id_profil <<"|" <<Pr.nom <<  "|"<<Pr.prenom <<"|" <<Pr.adresse<<"|"<<Pr.date_naissance <<"|" <<Pr.courriel <<"|"<<Pr.num_de_telephone << endl;
        fichier.close(); // fermeture du fichier
        cout << "Le message a été sauvegardé dans le fichier Profils.txt." << endl;
                }
    else {
        cerr << "Erreur : impossible d'ouvrir le fichier Profils.txt." << endl;
         }
 }





Profil::~Profil()
{
    //dtor
}
