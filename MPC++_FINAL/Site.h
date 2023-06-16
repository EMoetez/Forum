#ifndef SITE_H
#define SITE_H
#include<string>
#include<vector>
#include <fstream>

using namespace std;

class Site
{
    public:
        Site();
        virtual ~Site();
        Site(string ai, string aer,int id_site);
        string getAdresseInternet() const;
        string getAdresseEmailResponsable() const;
        void setAdresseInternet(string ai);
        int getIDSite()const;
        void setAdresseEmailResponsable(string aer);
        friend istream& operator>>(istream& in, Site& s);
        friend ostream& operator<<(ostream& out, Site& s);
        void afficher_site();
       void sauvegarder(const Site&);
       void rechercher_site_par_id(int id_site_rech);
       void setId(int id);
void supprimer_site_(int id_s);


    protected:
    private:
        string adresseInternet;
        string adresseEmailResponsable;
        int id_site;
};

#endif // SITE_H
