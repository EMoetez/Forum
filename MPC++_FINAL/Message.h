#ifndef MESSAGE_H
#define MESSAGE_H
#include<string>
#include<vector>
#include <fstream>
using namespace std;
class Message
{
    public:
        Message(int id_a=0,string t="Sans_titre",string cont="Pas_de_contenu",int id=0,string date_pub="Pas_de_date",int id_rubrique=0,int Id_rep= -1 );
        Message creer_message(int id_a);
        void rechercher_message_rep_par_id(int id_mssg_rep) ;
        void rechercher_message_par_id(int id_mssg_rech);
        void afficher_messages_du_jour(string date_p);
        void afficher() const ;
        void supprimer_message_fichier(int id_message) ;
        void sauvegarder_message(const Message& mss);
        virtual ~Message();
   // protected:
        int id_auteur;
        int id_message;
        string titre;
        string contenu;
        string date_publication;
        int  Id_mss_repondue;
        int id_rub;

};

#endif // MESSAGE_H
