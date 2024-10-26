#include <iostream>
#include "Tableau.h"

class Agenda{
    
private:
    Tableau tableau;
    //Tableau *tableau;

public:
    explicit Agenda(int tailleMax=10);
    Agenda(Agenda &agenda);
    Agenda concat (Agenda &agenda1, Agenda &agenda2);
    void concat(Agenda &agenda);
    void ajouter(std:: string nom, std:: string numeroTel);
    void supprimer(std:: string nom, std:: string numeroTel);
    void supprimer (std:: string nom);
    void afficher();

};