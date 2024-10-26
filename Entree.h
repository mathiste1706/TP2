//
// Created by Mathilde on 23/10/2024.
//

#ifndef ENTREE_H
#define ENTREE_H
#include <iostream>


class Entree {
    friend class Tableau;
    friend class Agenda;
private:
    std::string nom;
    std::string numeroTel;

public:
    explicit Entree(std::string nom="", std::string numeroTel="");
    void afficher();
};


#endif //ENTREE_H
