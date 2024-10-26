//
// Created by Mathilde on 23/10/2024.
//

#ifndef ENTREE_H
#define ENTREE_H
#include <iostream>


class Entree {
    // On a plus besoin de friend on a des getter
private:
    std::string nom;
    std::string numeroTel;

public:
    Entree(std::string nom="", std::string numeroTel="");

    // getter defini pour utiliser operateur <<
    std::string getNom();
    std::string getNumeroTel();

    void afficher();

    bool operator!=(const Entree &) const;
    friend std::ostream& operator<<(std::ostream& out, Entree &);
};


#endif //ENTREE_H
