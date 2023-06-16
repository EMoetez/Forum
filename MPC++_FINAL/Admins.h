#ifndef ADMINS_H
#define ADMINS_H

#include "Profil.h"
#include <fstream>

class Admin : public Profil {
public:
    Admin();
    virtual ~Admin();
    Admin(int Id_profil, string nom, string prenom, string adresse, string date_naissance, string courriel, int num_de_telephone, int id_Admin);
    void creeAdmin() const;

private:
    int id_admin;
};

#endif // ADMINS_H




