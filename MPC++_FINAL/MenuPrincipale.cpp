#include"MenuPrincipale.h"
#include"Rubrique.h"
#include"Documentation.h"
#include"Auteur.h"
#include"Message.h"
#include"Profil.h"
#include"Site.h"
#include"Documentation.h"
#include<string>
#include<vector>
#include <iostream>
#include <ostream>
#include <istream>
#include "Admins.h"
using namespace std;


bool verif_= false;
Menu_principal::Menu_principal(){}

Menu_principal::~Menu_principal(){}

void Menu_principal::afficher_Menu()
    {
        cout<<endl;
        cout << "                                ===        Bienvenue au forum        ===" << endl;
        cout << "                                                     " <<endl;
        cout << "                                 1.            Se connecter               " << endl;
        cout << "                                                     " <<endl;

        cout << "                                 2.           Creer un compte             " << endl;
        cout << "                                                     " <<endl;

        cout << "                                 3.     Continuer en tant que visiteur    " << endl;
        cout << "                                                     " <<endl;

        cout << "                                 4.              Quitter" << endl;

    }




void Menu_principal::gererRubriques() {
    int choix;
    do {
       cout <<                   "============================================"<< endl;

       cout << endl;
       cout << "                                     === Gestion des rubriques ===" << endl;
       cout<< ""<<endl;
       cout << "                                      1. Ajouter une rubrique" << endl;
       cout<< ""<<endl;
       cout << "                                      2. Afficher les rubriques" << endl;
       cout<< ""<<endl;
       cout << "                                      3. Afficher les messages d'une rubrique" << endl;
       cout<< ""<<endl;
       cout << "                                      4. Afficher les messages d'une rubrique par ordre chronologique" << endl;
       cout<< ""<<endl;
       cout << "                                      5. Afficher les profils qui ecrit dans une rubrique " << endl;
       cout<< ""<<endl;
       cout << "                                      6. Supprimer une rubrique" << endl;
       cout<< ""<<endl;
       cout << "                                      7. Retour au menu precedent" << endl;
       cout<< ""<<endl;
       cout<< ""<<endl;
       cout << "                                           Saisir un choix : ";
       cin >> choix;
       cin.ignore();

        switch (choix) {
            case 1:
                creerRubrique();
                break;
            case 2:
                afficherRubriques();
                break;

            case 3:
                int id_rub_recherche;
                cout<< "Donner l'ID du rubrique:     "<< endl;
                cin >> id_rub_recherche;
                afficherMessagesRubrique(id_rub_recherche);

                break;
            case 4:
                  afficherMessagesOrdreChronologique();
                  gererRubriques();

                break;
            case 5:
                afficherProfilsRubrique();
                gererRubriques();
                break;
            case 6:
                supprimer_rubrique();
                break;
            case 7:
                lancer_menu_principal();
            default:
                 cout<< ""<<endl;
                cout << "Choix invalide" << endl;
                 cout<< ""<<endl;
                break;
        }
    } while (true);
}

void Menu_principal::gererSites()
 {
    int choix;
    do {
        cout << endl;
        cout <<"============================================"<< endl;

        cout << "                                            === Gestion des sites ===" << endl;
        cout<< ""<<endl;
        cout << "                                          1. Ajouter un site a une rubrique" << endl;
        cout<< ""<<endl;
        cout << "                                          2. Afficher les sites d'une rubrique" << endl;
        cout<< ""<<endl;
        cout << "                                          3. Supprimer un site d'une rubrique" << endl;
        cout<< ""<<endl;
        cout << "                                          4. Retour au menu principal" << endl;
        cout<< ""<<endl;
        cout << "                                                  Saisir un choix : ";
        cin >> choix;
        cin.ignore();

        switch (choix) {
            case 1:
                ajouterSiteARubrique();
                break;
            case 2:
                afficherSite();
                break;
            case 3:
                supprimer_site();
                break;
            case 4:
                return; // Retour au menu principal
            default:
                cout << "Choix invalide !" << endl;
                break;
        }
    } while (true);
}

void Menu_principal :: lancer_menu_principal()
{
        cout<<endl;
        cout << "                                  ===              Menu Principal            ===" << endl;
        cout << "                                                       " <<endl;
        cout << "                                   1.            Gerer les messages             " << endl;
        cout << "                                                       " <<endl;

        cout << "                                   2.             Gerer mon profil              " << endl;
        cout << "                                                       " <<endl;

        cout << "                                   3.            Gerer les rubriques            "  << endl;
        cout << "                                                       " <<endl;

        cout << "                                   4.             Gerer les auteurs             " << endl;
        cout << "                                                       " <<endl;

        cout << "                                   5.             Gerer les sites               " << endl;
        cout << "                                                       " <<endl;

        cout << "                                   6.              Se deconnecter               " << endl;


        int choix;

          do {
              cout << "                           Saisir un choix : ";
              cin >> choix;
              cin.ignore();

              switch (choix)
                {
                  case 1:
                      lancer_Menu_Messages();
                      lancer_menu_principal();
                      break;
                  case 2:
                      lancer_Menu_Profils();
                      lancer_menu_principal();
                      break;
                  case 3:
                      gererRubriques();
                      lancer_menu_principal();
                      break;
                  case 4:
                      lancer_Menu_Auteurs();
                      lancer_menu_principal();
                      break;
                  case 5:
                   gererSites();
                   lancer_menu_principal();
                    break;
                  case 6:
                     cout << "Au revoir !" << endl;
                     lancer();
                      break;
                  default:
                      cout << "Choix invalide" << endl;
                      break;
                }
          }
          while (choix != 6);

}


void Menu_principal::lancer()
{

        afficher_Menu();
        int choix;

              cout << "                         Saisir un choix:          ";
              cin >> choix;
              cin.ignore();




                 if (choix==1)

                 {
                       int choix_ad;
                       cout <<"Se connecter en tant qu'un admin ( 1: OUI/0: Non)"<<endl;
                       cin>> choix_ad;
                       if (choix_ad==1)
                          {
                              int id_;
                               cout <<"Donner l'ID de l'admin"<<endl;
                               cin >>id_;
                               if (id_==99)
                                    {
                                         cout<< "Vous etes connecte en tant que admin :"<<endl;
                                         verif_= true;
                                         lancer_menu_principal();
                                    }
                          }



                       int id_c;
                       cout <<"                                Donner votre ID: " <<endl;
                       cin >> id_c;
                       Auteur Bu(0,"SansPseudo",0,"0","0");
                       Auteur Au(0,"SansPseudo",0,"0","0");

                       Au.chercher_un_auteur(id_c);
                       if (Bu.id_auteur!=Au.id_auteur)
                       {
                           lancer_menu_principal();
                       }
                       else
                       {
                        cout<< "                                                        "<<endl;
                        cout<< "             Impossible de se connecter au forum, veuillez reessaye!!"<<endl;
                        cout<< "                                                        "<<endl;
                        cout<< "                                                        "<<endl;
                        lancer();
                       }


                 }


                  else if (choix==2)
                  {
                      lancer_menu_creation();
                      lancer_menu_principal();

                  }

                 else if (choix==3)
                      {
                          lancer_Menu_visiteur();
                      }



                 else if (choix==4)
                      cout << "                        Au revoir !        " << endl;
                 else
                      cout << "                      Choix invalide      " << endl;
}















void Menu_principal :: lancer_Menu_visiteur()
{
        cout<<endl;
        cout << "                                  ===              Menu visiteur           ===" << endl;
        cout << "                                            " <<endl;
        cout << "                                  1.            Afficher les messages         " << endl;
        cout << "                                            " <<endl;

        cout << "                                  2.             Afficher un profil           " << endl;
        cout << "                                            " <<endl;

        cout << "                                  3.            Afficher une rubrique         " << endl;
        cout << "                                            " <<endl;

        cout << "                                  4.             Afficher une auteur          " << endl;
        cout << "                                            " <<endl;

        cout << "                                  5.             Afficher un site             " << endl;
        cout << "                                            " <<endl;

        cout << "                                  6.         Retourner au menu precedent      " << endl;

        cout << "                                                  Saisir un choix :             ";


int choix;
              cin >> choix;
              cin.ignore();

                  if  (choix==1)
                  {
                         int choix_id_mssg;
                         cout <<"         Donner l'ID du message à chercher:"<<endl;
                         cin >> choix_id_mssg;


                         Message m__(0,"SansTitre","messageVide",0,"0",0);
                         m__.rechercher_message_par_id(choix_id_mssg);
                         m__.afficher();
                          lancer_Menu_visiteur();
                  }



                  else if (choix==2)
                      {

                       int choix_id_mssg;
                       cout <<"            Donner l'ID du profil à chercher:"<<endl;
                       cin >> choix_id_mssg;
                       Profil P_(0,"SansNom","SansPrenom","SansAdresse","SansDte","SansCourriel",0);
                       P_.chercher_profil_par_id(choix_id_mssg);
                       P_.afficher_profil();
                       lancer_Menu_visiteur();
                      }
                  else if (choix==3)
                  {
                    afficherRubriques();
                     lancer_Menu_visiteur();
                  }

                else if (choix==4)
                   {
                        int choix_id_aut;
                      cout <<"                   Donner l'ID de l'auteur :"<<endl;
                      cin >> choix_id_aut;
                      Auteur A_(0,"SansPseudo",0,"0","0");
                      A_.chercher_un_auteur(choix_id_aut);
                      A_.afficher_auteur();
                      lancer_Menu_visiteur();
                   }

                 else if (choix==5)
                 {
                   afficherSite();
                   lancer_Menu_visiteur();
                 }

                 else if (choix==6)
                 {
                   cout << "                Au revoir !" << endl;
                     afficher_Menu();
                 }

                 else
                      cout << "            Choix invalide" << endl;

                }

void Menu_principal::lancer_menu_creation()
{

        cout<<endl;
        cout << "                                 ===        Creer votre compte       ===" << endl;
        cout << "                                        " <<endl;

        Profil Profil_( 0 , "SansNom" , "SansPrenom" , "SansAdresse" , "SansDte" , "SansCourriel" , 0 );
        int choix_mssg;
        cout <<"Donner l'ID du profil : "<<endl;
        cin >> choix_mssg;
        Profil_.creer_profil(choix_mssg);
        Auteur A(0,"SansPseudo",0,"0","0");
        A.creer_auteur();

        cout<< "                                         "<<endl;
        cout<< "                                         "<<endl;

        lancer_menu_principal();

}













void Menu_principal::supprimer_site()
{
         Site s;
         Documentation d;
         int id_s;
         cout<<endl;
          cout<<"                                   Donner l'ID du site a supprimer : "<<endl;
          cin>>id_s;
          s.supprimer_site_(id_s);
          d.supprimerSiteDeRubrique(id_s);
}


void Menu_principal::creerRubrique(){
        Rubrique r;
        Site s;
        cin >> r;
        rubriques.push_back(r);
        r.sauvegarder(r);
    }
void Menu_principal::creerSite(){
        Site s;
        cin>>s;
        s.sauvegarder(s);

    }

void Menu_principal::ajouterSiteARubrique()
{
    Documentation d;
    Site s;
    int id_r;
    cout<<"                                           Donner l'ID Rubrique a la quelle vous voulez ajouter le site : ";
    cin>>id_r;
    cin>>s,
    s.sauvegarder(s);
    d.ajouterSiteARubrique(id_r,s.getIDSite());
}


void Menu_principal::afficherRubriques(){
    Rubrique r(" "," "," ",0);
    int id_r;
        cout<<endl;
        cout<<"                                                    Donner l'ID rubrique a recherchee : ";
        cin>>id_r;
        cout<<"                                                           === La rubrique ==="<<endl;
        r.AfficherRubrique(id_r);

    }

    void Menu_principal::afficherSite(){
    Site s(" "," ",0);
    int id_s;
        cout<<endl;
        cout<<"                                    Donner l'ID site a recherchee : ";
        cin>>id_s;
        cout<<"                                         === Liste des site ==="<<endl;
        s.rechercher_site_par_id(id_s);
        s.afficher_site();

    }

    void Menu_principal::supprimer_rubrique()
    {
        Rubrique r;
        int id_r;
         cout<<endl;
          cout<<"                                           Donner l'ID rubrique a supprimer : "<<endl;
          cin>>id_r;
          r.supprimer_rubrique_(id_r);

    }





void Menu_principal::afficherMessagesRubrique() {}

void Menu_principal::afficherMessagesJour() {}


void Menu_principal:: afficher_Menu_Messages()
        {
        cout<<endl;
        cout << "                                            === Menu Messages === " << endl;
        cout << "                                            1. Ecrire un message   " << endl;
        cout << "                                            2. Afficher un message " << endl;
        cout << "                                            3. Afficher les reponses sur un message" << endl;
        cout << "                                            4. Afficher les messages du jour" << endl;
        cout << "                                            5. supprimer un message" << endl;
        cout << "                                            6. Quitter" << endl;
        }

void Menu_principal:: lancer_Menu_Messages()
{


        afficher_Menu_Messages();
        int choix;
        cout << "                                               Saisir un choix : ";
        cin >> choix;
           if(choix==1) {
                int choix_mssg;
                cout <<"                                     Donner l'ID de l'auteur:"<<endl;
                cin >> choix_mssg;

                Message mg;
                mg.creer_message(choix_mssg);
                //mg.sauvegarder_message( mg);
                lancer_Menu_Messages();
                       }
          else if (choix==2)
                      {

                int choix_id_mssg;
                cout <<"                                   Donner l'ID du message à chercher:"<<endl;
                cin >> choix_id_mssg;


                Message m_(0,"SansTitre","messageVide",0,"0",0);
                m_.rechercher_message_par_id(choix_id_mssg);
                m_.afficher();
                lancer_Menu_Messages();
                      }
            else if (choix==3)
                 {
                int id_mssg_reponses;
                Message liste_reponses;
                cout <<"                                      Donner l'ID du message:"<<endl;
                cin >> id_mssg_reponses;
               // liste_reponses.insert(liste_reponses.end(), rechercher_message_rep_par_id(id_mssg_reponses).begin(), rechercher_message_rep_par_id( id_mssg_reponses).end());
               liste_reponses.rechercher_message_rep_par_id(id_mssg_reponses);
                /*for(unsigned int i=0;i<liste_reponses.size();i++)
                      {
                          liste_reponses[i].afficher();
                      }*/
                 lancer_Menu_Messages();
                 }
            else if (choix==4)
            {
                string date_cherche;
                Message md;
                cout<<"Donnez la date de publication  :  "<<endl;
                cin>> date_cherche;
                md.afficher_messages_du_jour(date_cherche);
                md.afficher();
                lancer_Menu_Messages();
            }
            else if (choix==5)
                           {
                int choix_id;
                cout <<"Donner l'ID du message:"<<endl;
                cin >> choix_id;
                Message mssg;
                mssg.rechercher_message_par_id( choix_id) ;
                mssg.supprimer_message_fichier(choix_id);
                lancer_Menu_Messages();
                            }
            else if (choix==6)
                    {
                cout << "            " << endl;
                lancer_menu_principal();
                    }
            else
                    {
                cout << "Choix invalide !! " << endl;

                    }


}




void Menu_principal:: afficher_Menu_Auteurs()
        {


        cout<<endl;
        cout << "=== Menu Auteurs ===" << endl;
        cout << "1. Ajouter un auteur" << endl;
        cout << "2. Afficher un auteur" << endl;
        cout << "3. Modifier  un auteur" << endl;
        cout << "4. Verifier le profil d'un auteur" << endl;
        cout <<" 5. Afficher un auteur" << endl;
        cout << "6. supprimer un auteur" << endl;
        cout << "7. Quitter" << endl;

        }


void Menu_principal:: lancer_Menu_Auteurs()
{


        afficher_Menu_Auteurs();
        int choix;

        cout << "Saisir un choix : ";
        cin >> choix;

            if(choix==1)
            {
                Auteur A(0,"SansPseudo",0,"0","0");
                A.creer_auteur();
                lancer_Menu_Auteurs();
            }
            else if (choix==2)
            {
                int choix_id_aut;
                cout <<"Donner l'ID de l'auteur :"<<endl;
                cin >> choix_id_aut;
                Auteur A(0,"SansPseudo",0,"0","0");
                A.chercher_un_auteur(choix_id_aut);
                A.afficher_auteur();
                lancer_Menu_Auteurs();

            }

            else if (choix==3)
                {
                    /* vector <Message> liste_rep;
                     liste_rep = rechercher_message_rep_par_id(int id_mssg_rep);
                     for(unsigned int i=0;i<liste_rep.size();i++)
                            {
                                 liste_rep[i].afficher();
                            }*/
                   cout<<"_______________________"<<endl;
                   cout<<"Pas encore developpees"<<endl;
                   cout<<"_______________________"<<endl;
                   lancer_Menu_Auteurs();
                }

            else if (choix==4)
                   {
                  /* int choix_id_aut;
                   cout <<"Donner l'ID de l'auteur :"<<endl;
                   cin >> choix_id_aut;
                   Profil P(0,"SansNom","SansPrenom","SansAdresse","SansDte","SansCourriel",0);
                   P.*/
                   cout<<"_______________________"<<endl;
                   cout<<"Pas encore developpees"<<endl;
                   cout<<"_______________________"<<endl;
                   lancer_Menu_Auteurs();
                   }

            else if(choix==5)
               {
                   afficherMessagesAuteur();
               }
            else if (choix==6)
            {
                int choix_id;
                cout <<"Donner l'ID du l'auteur a supprimer:"<<endl;
                cin >> choix_id;
                Auteur A(0,"SansPseudo", 0 , "0", "0");
                A.supprimer_auteur(choix_id);
                lancer_Menu_Auteurs();
            }

            else if (choix==7)
            {
                cout << "Au revoir !" << endl;
                afficher_Menu();

            }
            else
                   {
                       cout<<endl;
                       cout<<endl;
                       cout << "          Choix invalide!       " << endl;
                       cout<<endl;
                       cout<<endl;
                   }



}



void Menu_principal:: afficher_Menu_Profils()
    {
        cout<<endl;


        cout << "=== Menu Profil===" << endl;
        cout << "1. Ecrire un profil" << endl;
        cout << "2. Afficher un profil" << endl;
        cout << "3. Modifier un profil" << endl;
        cout << "4. supprimer un profil" << endl;
        cout << "5. Quitter" << endl;

    }


void Menu_principal:: lancer_Menu_Profils()
        {
        afficher_Menu_Profils();
        int choix;
        cout << "Saisir un choix : ";
        cin >> choix;

        if (choix==1)
                {
                         int choix_mssg;
                         cout <<"Donner l'ID du profil : "<<endl;
                         cin >> choix_mssg;
                         Profil P(0,"SansNom","SansPrenom","SansAdresse","SansDte","SansCourriel",0);
                         P.creer_profil(choix_mssg);
                         lancer_Menu_Profils();
                }
        else if (choix==2)
        {
                int choix_id_mssg;
                cout <<"Donner l'ID du profil à chercher:"<<endl;
                cin >> choix_id_mssg;


                Profil P(0,"SansNom","SansPrenom","SansAdresse","SansDte","SansCourriel",0);
                P.chercher_profil_par_id(choix_id_mssg);
                P.afficher_profil();
                lancer_Menu_Profils();
        }

        else if (choix==3)
                {
                  /* Vector<Message> liste_rep;
                   liste_rep = rechercher_message_rep_par_id(int id_mssg_rep);
                   for(unsigned int i=0;i<liste_rep.size();i++)
                      {
                          liste_rep[i].afficher();
                      }*/
                   cout<<"_______________________"<<endl;
                   cout<<"Pas encore developpees"<<endl;
                   cout<<"_______________________"<<endl;
                   lancer_Menu_Profils();
                }
        else if  (choix==4)
            {
                int choix_id_mssg;
                cout <<"Donner l'ID du profil à supprimer:"<<endl;
                cin >> choix_id_mssg;
                Profil P(0,"SansNom","SansPrenom","SansAdresse","SansDte","SansCourriel",0);
                P.supprimer_profil(choix_id_mssg);
                lancer_Menu_Profils();
            }
            else if (choix==5)
            {
                cout << "Au revoir !" << endl;
                lancer_Menu_Profils();            }
            else
                cout << "Choix invalide" << endl;

        }



void Menu_principal::afficherMessagesRubrique(int id_rub_rech) {
    ifstream fichier("Messages.txt");
    if (fichier.is_open()) {
        string ligne;

        while (true)
        {
            if(getline(fichier, ligne))
            {


            stringstream sos(ligne);
            int id_a,id_rb;
            int id_m;
            int id_r;
            string t;
            string cont;
            string d_p;
            sos >> id_a;
            sos.ignore();
            getline(sos, t, '|');
            getline(sos, cont, '|');
            sos >> id_m;
            sos.ignore();
            getline(sos, d_p, '|');
            sos >>id_rb;
            sos.ignore();
            sos >> id_r;
            if (id_rb == id_rub_rech) {
                // Afficher le message associé à la rubrique
                cout << "Message :" << endl;
                cout << "ID du message : " << id_m << endl;
                cout << "Titre : " << t << endl;
                cout << "Contenu : " << cont << endl;
                cout << "ID de la rubrique : " << id_rb << endl;
                cout << "ID de l'auteur : " << id_a << endl;
                cout << "Date de publication : " << d_p << endl;
                cout << "-----------------------------------" << endl;
            }
            }
            else
            {
                cout<< "Pas de message dans cette rubrique"<<endl;
                break;
            }

        }




        fichier.close();
    }
    else {
        cerr << "Erreur : impossible d'ouvrir le fichier Messages.txt." << endl;
    }
}




void Menu_principal:: afficherMessagesOrdreChronologique()
{
    vector<Message> messagess;
    int id;
    cout<<"Saisissez ID rubrique: "<<endl;
    cin>>id;
    ifstream fichier("Messages.txt");
    if (fichier.is_open()) {
        string ligne;
        cout<<"   "<<endl;
        while (getline(fichier, ligne))
            {
                  stringstream sos(ligne);
                  int id_rub;
                  int id_a ;
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
                  sos >> id_rub;
                  sos.ignore();
                  sos >> id_r;
                  if (id == id_rub)
                       {
                          Message resultat(id_a, t, cont, id_m, d_p, id,id_r);
                          messagess.push_back(resultat);

                       }
            }
        trierMessagesParDate(messagess);

        for (unsigned int i=0; i<messagess.size();i++) {
                    messagess[i].afficher();
        }
        fichier.close();
    cout<<"     "<<endl;
    }
}
int Menu_principal::convertirEnEntier(const std::string& str) {
    int result = 0;
    for (unsigned int i=0;i<str.length();i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
        else {
            break;
        }
    }
    return result;
}
int Menu_principal::convertirDateEnNombre(const std::string& date) {
    std::stringstream ss(date);
    std::string jour, mois, annee;
    std::getline(ss, jour, '/');
    std::getline(ss, mois, '/');
    std::getline(ss, annee);

    int jourInt = convertirEnEntier(jour);
    int moisInt = convertirEnEntier(mois);
    int anneeInt = convertirEnEntier(annee);

    return anneeInt * 10000 + moisInt * 100 + jourInt;
}

int Menu_principal::comparerDates(const std::string& date1, const std::string& date2) {
    int date1Int = convertirDateEnNombre(date1);
    int date2Int = convertirDateEnNombre(date2);

    if (date1Int < date2Int) {
        return -1;
    } else if (date1Int > date2Int) {
        return 1;
    } else {
        return 0;
    }
}
void Menu_principal::trierMessagesParDate(std::vector<Message>& messagess) {
    for (size_t i = 1; i < messagess.size(); ++i) {
        Message messageCourant = messagess[i];
        int dateCourante = convertirDateEnNombre(messageCourant.date_publication);
        size_t j = i;

        while (j > 0 && convertirDateEnNombre(messagess[j - 1].date_publication) > dateCourante) {
            messagess[j] = messagess[j - 1];
            --j;
        }

        messagess[j] = messageCourant;
    }
}


void Menu_principal::afficherProfilsRubrique() {
    int id;
    vector<Message> messagess;
    cout << "Saisissez ID rubrique: " << endl;
    cin >> id;

    ifstream fichierMessages("Messages.txt");
    ifstream fichierAuteurs("Auteurs.txt");

    if (fichierMessages.is_open()) {

        string ligne;
        while (getline(fichierMessages, ligne)) {
            stringstream sos(ligne);
            int id_rub;
            int id_a;
            int id_m;
            int id_r;
            string t;
            string cont;
            string d_p;

            sos >> id_a;
            sos.ignore();
            getline(sos, t, '|');
            getline(sos, cont, '|');
            sos >> id_m;
            sos.ignore();
            getline(sos, d_p, '|');
            sos >> id_rub;
            sos.ignore();
            sos >> id_r;
            if (id == id_rub) {
                Message resultat( id_a, t, cont, id_m, d_p, id,id_r);
                messagess.push_back(resultat);
            }
        }
        fichierMessages.close();
    }

    if (fichierAuteurs.is_open()) {
        vector<Auteur> auteurs;
        string ligne;
        while (getline(fichierAuteurs, ligne)) {
            stringstream sos(ligne);
            int id_a;
            string ps;
            int nbr;
            string datePremierMessage;
            string dateDernierMessage;
            sos >> id_a;
            sos.ignore();
            getline(sos, ps, '|');
            sos >> nbr;
            sos.ignore();
            getline(sos, datePremierMessage, '|');
            getline(sos, dateDernierMessage);
            Auteur auteur(id_a, ps, nbr, datePremierMessage, dateDernierMessage);
            auteurs.push_back(auteur);
        }
        fichierAuteurs.close();

        cout << "                         " << endl;
        for (unsigned int i=0;i<messagess.size();i++) {
            for (unsigned int j=0;j<auteurs.size();j++) {
                if (auteurs[j].id_auteur == messagess[i].id_auteur) {
                    auteurs[j].afficher_auteur();
                    break;
                }
            }
        }
        cout << "                        " << endl;
    }
}



void Menu_principal::afficherMessagesAuteur() {
    int id;
    vector<Message> messagess;
    cout << "Saisissez ID Auteurs: " << endl;
    cin >> id;

    ifstream fichierMessages("Messages.txt");
    if (fichierMessages.is_open()) {

        string ligne;
        while (getline(fichierMessages, ligne)) {
            stringstream sos(ligne);
            int id_rub;
            int id_a;
            int id_m;
            int id_r;
            string t;
            string cont;
            string d_p;

            sos >> id_a;
            sos.ignore();
            getline(sos, t, '|');
            getline(sos, cont, '|');
            sos >> id_m;
            sos.ignore();
            getline(sos, d_p, '|');
            sos >> id_rub;
            sos.ignore();
            sos >> id_r;
            if (id_a == id) {
                Message resultat( id_a, t, cont, id_m, d_p, id,id_r);
                messagess.push_back(resultat);
            }
        }
        fichierMessages.close();
    }


    cout << "                         " << endl;
        for (unsigned int i=0;i<messagess.size();i++)
            {

                 messagess[i].afficher();

            }


        cout << "                        " << endl;

}
