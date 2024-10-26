//
// Created by Mathilde on 23/10/2024.
//

#include "Entree.h"

using namespace std;

Entree::Entree(std::string nom, std::string numeroTel) {
    this->nom=nom;
    this->numeroTel=numeroTel;
}

string Entree:: getNom() {
    return nom;
}
string Entree::getNumeroTel() {
    return numeroTel;
}


void Entree::afficher() {
    cout << nom << " " << numeroTel << endl;
}

bool Entree:: operator!=(const Entree & entree) const {
    if (this->nom!=entree.nom or this->numeroTel!=entree.numeroTel) {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<(std::ostream& out, Entree & entree){
    return out<<entree.getNom()<< " "<< entree.getNumeroTel()<< endl;
}



