#include <iostream>
#include "Entree.h"
#include "Agenda.hpp"
using namespace std; 

int main() {

    Agenda agenda(6);
    Entree entree("nom3", "3333");
    agenda+=entree;
    agenda.ajouter("nom3","4444");
    //agenda.ajouter("nom2", "2222");
    //agenda.ajouter("nom5", "5555");
    cout<<"agenda apres ajout entree\n";
    cout<<agenda;

    Agenda agendaCopie=agenda;
    cout<< "agenda affectation =\n"<<agendaCopie;

    cout<< "nouvel agenda à partir d'une concatenation\n";
    Agenda agendaConcat;
    agendaConcat=agendaConcat.concat(agenda, agendaCopie);
    cout<<agendaConcat;

    bool comparaison=agenda==agendaCopie;
    cout<< "Compare agenda et agendaCopie vrai attendu: "<< comparaison <<endl;
    comparaison=agenda==agendaConcat;
    cout<< "Compare agenda et agendaConcat faux attendu: "<< comparaison<<endl;

    agenda+=agendaConcat;
    cout<<"concatenation dans un agenda existant\n" <<agenda<< endl;

    Entree entree2("nom0", "0000");
    agendaConcat+=entree2;

    cout<<"1ere occurence de nom3\n" <<agendaConcat["nom3"]<<endl;
    cout<<"1ere occurence de absent\n" <<agendaConcat["absent"]<<endl;

    agendaConcat-="nom3";
    cout<<"Suppression de toutes les entrees avec nom3\n"<< agendaConcat <<endl;

    cout<<"teste si le nom: \"absent\" est dans l'agenda : " <<"absent"/agendaConcat<<endl;
    cout<<"teste si le nom: \"nom0\" est dans l'agenda : " <<"nom0"/agendaConcat<<endl;

    Entree entre3("zzzz","999");
    agendaConcat+=entree;
    agendaConcat+=entre3;
    cout<<"\nAgendaConcat complet:\n"<<agendaConcat;

    cout<<"\nTous les noms commençant par n\n";
    agendaConcat('n');
    cout<<"\nTous les noms commençant par z\n";
    agendaConcat('z');

    return 0;
}
