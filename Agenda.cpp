#include <optional>
#ifndef AGENDA_HPP
#define AGENDA_HPP

#include "Agenda.hpp"

using namespace std;

Agenda::Agenda(int tailleMax) {
    this->tableau=new Tableau(tailleMax);
}

Agenda:: Agenda(Agenda &agenda){
    this->tableau=new Tableau(*agenda.tableau);
}

Agenda::~Agenda() {
    if (tableau != nullptr) {
        delete tableau;
        tableau = nullptr; // Evite un pointeur inacessible
    }
}

Tableau* Agenda::getTableau() {
    return tableau;
}



void Agenda:: ajouter( string nom,  string numeroTel){
    this->tableau->ajouter(nom, numeroTel);
}
void Agenda:: supprimer( string nom,  string numeroTel){
    this->tableau->supprimer(nom, numeroTel);
}
void Agenda:: supprimer ( string nom){
    this->tableau->supprimer(nom);
}
void Agenda:: afficher(){
    this->tableau->afficher();
}

Agenda Agenda:: concat (Agenda &agenda1, Agenda &agenda2){
    
    int tailleMax=agenda1.tableau->getTailleMax()+agenda2.tableau->getTailleMax();
    this->tableau =new Tableau(tailleMax);

    Entree entree;
    for (int i=0; i<agenda1.tableau->getNbElements();i++){
        entree=Entree(agenda1.tableau->getEntree()[i]);
        this->ajouter(entree.getNom(), entree.getNumeroTel());
    }

    for (int i=0; i<agenda2.tableau->getNbElements();i++){
        entree=Entree(agenda1.tableau->getEntree()[i]);
        this->tableau->ajouter(entree.getNom(), entree.getNumeroTel());
    }
    return *this;
}

void Agenda:: concat(Agenda &agenda){
    Entree entree;
    if (agenda.tableau->getNbElements()<=(this->tableau->getTailleMax())-this->tableau->getNbElements()){
        for (int i=0; i<agenda.tableau->getNbElements();i++){
            entree=Entree(agenda.tableau->getEntree()[i]);
            this->tableau->ajouter(entree.getNom(), entree.getNumeroTel());
        }
    }
    else {
        cout<<"Erreur: Impossible de concatener!\nAgenda courant trop petit\n";
    }
}

    void Agenda:: operator +=(Entree &nvEntree) {
        this->ajouter(nvEntree.getNom(), nvEntree.getNumeroTel());

    }
    Agenda Agenda:: operator=(Agenda agenda) {
        return Agenda(agenda);
    }

    void Agenda:: operator+=(Agenda & agenda) {
        this->concat(agenda);
}
    bool Agenda:: operator==(Agenda& agenda) {

    bool comparaison=true;
    if (this->tableau->getNbElements()!=agenda.tableau->getNbElements()) {
        return false;
    }
    else {
        for (int i=0; i<this->tableau->getNbElements() and comparaison; i++) {
            if (this->tableau->getEntree()[i]!=agenda.tableau->getEntree()[i]) { // Definition de != pour Entree
                comparaison=false;
            }
        }
    }
    return comparaison;
}
string Agenda::operator[](string nom) {
    for (int i=0; i<tableau->getNbElements();i++) {
        if (tableau->getEntree()[i].getNom()==nom) {
            return tableau->getEntree()[i].getNom()+" "+tableau->getEntree()[i].getNumeroTel();
        }
    }
    return "Le nom "+nom+" n'a pas ete trouve";
}

Agenda& Agenda:: operator-=(string nom) {
    this->supprimer(nom);
    return *this;
}

void Agenda::operator()(char lettre) {
    for (int i=0; i<tableau->getNbElements();i++) {
        if (tableau->getEntree()[i].getNom()[0]==lettre) {
            cout<<tableau->getEntree()[i].getNom()<<endl;
        }
    }
}




ostream& operator<< (ostream& out, Agenda& agenda) { // << est aussi defini pour Entree et Tableau
    return out<<*(agenda.tableau);
}

bool operator/(string nom, Agenda& agenda) {        // Ajout fonction recherche dans tableau
    bool trouver=false;
    for (int i=0; i<agenda.getTableau()->getNbElements();i++) {
        if (agenda.getTableau()->getEntree()[i].getNom()==nom) {
            return true;
        }
    }
    return trouver;
}

#endif  //AGENDA_HPP