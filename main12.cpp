#include <iostream>
#include <fstream>
#include <string>

// TODO : namespace sgap (même si simple, bonne habitude)
namespace{
   
}

int main() {
    std::string nom;
    int age;
    
    // 1. Demander nom et âge
    std::cout << "Nom : ";

    std::cin >> nom;
    std::cout << "Age : ";
    // TODO : std::cin >> age
    std::cin >> age;
    
    // 2. Écrire dans profil.txt
    // TODO : std::ofstream
    std::ofstream f("profil.txt");
    if(!f.is_open()){
        std::cout << "ERROR : Impossible d'ouvrir le fichier \n";
        return 1;
    }
    f << "Nom : [" << nom << "]\n";
    f << "Age : [" << age << "]\n";
    f.close();
    std::cout << "Fichier écrit avec succès \n";
    
    // 3. Relire et afficher
    std::ifstream fichier("profil.txt");
    if(!fichier.is_open()){
        std::cout << "ERROR : fichier introuvable \n"; 
    }
    std::string ligne;
    while(std::getline(fichier,ligne)){
        std::cout << ligne << "\n";
    }
    fichier.close();

    return 0;
}