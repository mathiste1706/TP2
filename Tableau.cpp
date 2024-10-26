//
// Created by Mathilde on 23/10/2024.
//

#include "Tableau.h"

using namespace std;

Tableau::Tableau(int tailleMax) {
    this->tailleMax = tailleMax;
    this->entree = new Entree[tailleMax];
    this->nbElements = 0;

}
Tableau::Tableau(Tableau &tableau) {
    this->tailleMax = tableau.tailleMax;
    this->nbElements = tableau.nbElements;
    this->entree = new Entree[tableau.tailleMax];

    for (int i = 0; i < this->tailleMax; i++) {
        this->entree[i] = tableau.entree[i];
    }
}
Tableau::~Tableau() {
    //std::cout << "Tableau destructor called" << std::endl;
    if (entree != nullptr) {
        delete[] entree;
        entree = nullptr; // Evite un pointeur inacessible
      //  cout << "Tableau destructor called successfully" << endl;
    }
}

int Tableau:: getTailleMax(){
    return this->tailleMax;
}
int Tableau::getNbElements(){
    return this->nbElements;
}

Entree* Tableau:: getEntree(){
    return this->entree;
}

void Tableau::afficher() {
    for (int i = 0; i < this->tailleMax; i++) {
        cout<<i<<": ";
        this->entree[i].afficher();
        cout<<endl;
    }
}
void Tableau::ajouter(string nom, string numeroTel) {
    if (this->nbElements < this->tailleMax) {
        this->entree[this->nbElements] = Entree(nom, numeroTel);
        this->nbElements+=1;
    } else {
        cout<<"Erreur ajouter tableau plein\n";
    }
}
void Tableau::supprimer(string nom, string numeroTel) {
    bool  boolTrouve=false;
    for (int i = 0; i < this->nbElements && !boolTrouve; i++) {
        if (this->entree[i].nom==nom and this->entree[i].numeroTel==numeroTel) {
            boolTrouve=true;
            if (i!=nbElements){
                entree[i]=entree[nbElements-1];
            }
            // Pour que l'entree supprimee ne soit plus afficher meme si afficher est apellee en suivant
            entree[nbElements-1].nom="";
            entree[nbElements-1].numeroTel="";
            this->nbElements--;
        }
    }
}
void Tableau::supprimer(string nom) {
    
    int index = 0;
      while (index < this->nbElements) {
        if (this->entree[index].nom == nom) {
            /// Pour que l'entree supprimee ne soit plus afficher meme si afficher est apellee en suivant
             if (index!=nbElements){
                entree[index]=entree[nbElements-1];
            }
            this->entree[this->nbElements - 1].nom = "";
            this->entree[this->nbElements - 1].numeroTel = "";
            this->nbElements--;
        } else {
            index++;
        }
    }
}






