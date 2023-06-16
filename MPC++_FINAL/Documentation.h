#ifndef DOCUMENTATION_H
#define DOCUMENTATION_H
#include<string>
#include"Site.h"
#include"Rubrique.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include <fstream>
#include<ostream>
class Documentation
{
    public:
        Documentation();
        virtual ~Documentation();
        void ajouterSiteARubrique(int id_rubrique, int id_site) ;
        void supprimerSiteDeRubrique( int id_site);

    protected:
    private:

};

#endif // DOCUMENTATION_H
