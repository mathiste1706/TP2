//
// Created by Mathilde on 23/10/2024.
//

#ifndef TABLEAU_H
#define TABLEAU_H
#include "Entree.h"


class Tableau {
private:
    int tailleMax;
    Entree* entree;
    int nbElements;

public:
    explicit Tableau(int tailleMax=10);
    Tableau(Tableau& tableau);
    ~Tableau();
    int getTailleMax();
    int getNbElements();
    Entree* getEntree();
    void afficher();
    void ajouter(std::string nom, std::string numeroTel);
    void supprimer(std::string nom, std::string numeroTel);
    void supprimer(std::string nom);

};



#endif //TABLEAU_H
