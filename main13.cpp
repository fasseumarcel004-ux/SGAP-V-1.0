#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

namespace sgap {
    struct Etudiant {
        std::string nom;
        int note;   // ✅ int pour simplifier
    };
}

int main() {
    constexpr std::size_t TAILLE = 3;
    std::vector<sgap::Etudiant> eleves;
    
    // Saisie
    for (std::size_t i = 0; i < TAILLE; ++i) {
        sgap::Etudiant temp;
        std::cout << "Nom : ";
        std::cin >> temp.nom;
        std::cout << "Note : ";
        std::cin >> temp.note;
        eleves.push_back(temp);
    }
    
    // Écriture CSV
    std::ofstream f("notes.csv");
    if (!f.is_open()) {
        std::cout << "ERROR\n";
        return 1;
    }
    
    f << "Nom,Note\n";   // ✅ Sans espaces
    for (const auto& e : eleves) {
        f << e.nom << "," << e.note << "\n";   // ✅ CSV pur
    }
    f.close();
    
    // Lecture CSV
    std::ifstream fichier("notes.csv");
    if (!fichier.is_open()) {
        std::cout << "ERROR\n";
        return 1;
    }
    
    std::string ligne;
    std::getline(fichier, ligne);   // ✅ Ignorer l'en-tête
    
    float somme = 0.0f;
    int compteur = 0;
    
    std::cout << "\n=== Relecture ===\n";
    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne);
        std::string nom, noteStr;
        
        std::getline(ss, nom, ',');
        std::getline(ss, noteStr, ',');
        
        int note = std::stoi(noteStr);   // ✅ Conversion
        
        std::cout << nom << " : " << note << "\n";
        
        somme += note;
        ++compteur;
    }
    
    if (compteur > 0) {
        std::cout << "Moyenne : " << somme / compteur << "\n";
    }
    
    fichier.close();
    return 0;
}