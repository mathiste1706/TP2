#include <iostream>
#include "Entree.h"
#include "Tableau.h"
#include "Agenda.hpp"
using namespace std; 

int main() {
    
    Entree entree1("nom1", "11111");
    entree1.afficher();

    Tableau tabTailleDef(10); // Apelle constructeur par defaut de Tableau
    cout<< "tailleMax: "<<tabTailleDef.getTailleMax()<<endl;
    cout<< "nbElements: "<<tabTailleDef.getNbElements()<<endl;

    Tableau tab1(4);
    tab1.ajouter("nom2", "2222");
    cout<< "nbElements: "<<tab1.getNbElements()<<endl;
    cout<< "tab1\n";
    tab1.afficher();

    Tableau tabCopie(tab1);
    cout<< "tabCopie ajout entree\n";
    tabCopie.afficher();
    tabCopie.ajouter("nom_copie", "copppp");

    tab1.ajouter("nom3","3333");

    cout<< "check tab1 apres ajout entree\n";
    tab1.afficher();
    
    cout<<"tabCopie apres ajout entree ds tab1\n";
    tabCopie.afficher();

    tabCopie.supprimer("nom2", "2222");

    cout<< "tabCopie apres suppression de entre2\n";
    tabCopie.afficher();

    cout<< "tab1 apres suppression de entre2 ds tabCopie\n";
    tab1.afficher();

    tabCopie.ajouter("nom2", "2222");
    tabCopie.ajouter("nom3","3333");
    tabCopie.ajouter("nom3","4444");
    tabCopie.ajouter("nomM","MMMM");

    cout<<"tab Copie apres ajout 2 et 3 et 4\n";
    tabCopie.afficher();

    cout<<"tab Copie apres suppression 2 et 3 et 4\n";
    tabCopie.supprimer("nom2", "2222");
    tabCopie.supprimer("nom_copie", "copppp");
    tabCopie.supprimer("nom3");
    tabCopie.afficher();
    tabCopie.~Tableau();

    Agenda agenda(3);
    agenda.ajouter("nom3", "3333");
    agenda.ajouter("nom3","4444");
    agenda.ajouter("nom2", "2222");
    agenda.ajouter("nom5", "5555");
    cout<<"agenda apres ajout 2, 3, 4 et 5\n";
    agenda.afficher();


    Agenda agendaCopie(agenda);
    cout<<"agenda copie\n";
    agendaCopie.afficher();
    Agenda agendaConcat=agendaConcat.concat(agenda, agendaCopie);
    cout<<"agenda concat return un 3eme agenda\n";
    agendaConcat.afficher();

    cout<<"agenda concat ds un agenda existant erreur attendu\n";
    agendaConcat.concat(agenda);

    Agenda agenda4(4);
    agenda4.ajouter("nom6", "6666");
    agenda4.concat(agenda);
    cout<<"agenda concat ds un agenda\n";
    agenda4.afficher();

    cout<<"suppression nom2\n";
    agenda4.supprimer("nom2", "2222");
    agenda4.afficher();
    cout<<"suppression nom3\n";
    agenda4.supprimer("nom3");
    agenda4.afficher();

   // agendaPrConcact

    /*
    cout<< "Seg Fault Attendue\n";
    tabCopie.~Tableau();
    tabCopie.afficher();
    */

    // question 5 on doit remplacer Tableau tableau par Tableau *tableau et faire soit des new pour les allocations de
    // tableau ou tableau=Tableau(tailleMax);
    // Aussi Agenda::Agenda(int tailleMax) : tableau(tailleMax) devient un constructeur classique
    // et on doit créer un destructeur comme pour tableau

    return 0;
}
