
#include <iostream>
#include <string>
using namespace std;

class Etudiant{
    public:
       string nom;
       int age;
       void afficher(){
        cout << "nom : "<<nom<<endl;
        cout << "age : "<<age<<endl;
       }
};
int main (){
    Etudiant e1;
    e1.nom = "STELLA";
    e1.age = 20;
    e1.afficher();

    return 0;
}