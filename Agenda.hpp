#include <iostream>
#include "Tableau.h"

class Agenda{
    
private:
    Tableau *tableau;

public:
    Agenda(int tailleMax=10);
    Agenda(Agenda &agenda);
    ~Agenda();
    Tableau* getTableau();
    Agenda concat (Agenda &agenda1, Agenda &agenda2);
    void concat(Agenda &agenda);
    void ajouter(std:: string nom, std:: string numeroTel);
    void supprimer(std:: string nom, std:: string numeroTel);
    void supprimer (std:: string nom);
    void afficher();

    // Operateurs n'utilisant pas des types de bases donc dans la classe
    void operator +=(Entree &nvEntree);
    Agenda operator=(Agenda);
    Agenda& operator+(Agenda&);
    void operator+=(Agenda &);
    bool operator==(Agenda&);
    std::string operator[](std::string nom);
    Agenda& operator-=(std::string nom);
    void operator()(char lettre);

    // friend pour les types de bases, que les operateurs utilisent en dehors de la classe
    friend std::ostream& operator<<(std::ostream& out, Agenda&);
    friend std::string;
};



bool operator/(std::string nom, Agenda&);