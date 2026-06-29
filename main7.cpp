#include <iostream>
#include <string>
#include <cstdint>

namespace sgap {
    struct Etudiant {
        uint32_t id;
        std::string nom;
        bool estPresent;
    };
    
    Etudiant* creerClasse(int taille) {
        Etudiant* eleves = new Etudiant[taille];
        for (int i = 0; i < taille; ++i) {
            eleves[i].id = 12345 + static_cast<uint32_t>(i);
            eleves[i].nom = "Etudiant " + std::to_string(i + 1);
            eleves[i].estPresent = false;
        }
        return eleves;
    }
    
    void afficher(const Etudiant* classe, int taille) {
        std::cout << "=== Liste ===\n";
        for (int i = 0; i < taille; ++i) {
            std::cout << classe[i].id << " | "
                      << classe[i].nom << " | "
                      << (classe[i].estPresent ? "P" : "A") << "\n";
        }
        std::cout << "\n";
    }
    
    void validerTousPresents(Etudiant* classe, int taille) {
        for (int i = 0; i < taille; ++i) {
            classe[i].estPresent = true;
        }
    }
    
    void validerParId(Etudiant* classe, int taille, uint32_t id) {  // ✅ uint32_t
        for (int i = 0; i < taille; ++i) {
            if (classe[i].id == id) {
                classe[i].estPresent = true;
                break;
            }
        }
    }
    
    int compterPresents(const Etudiant* classe, int taille) {  // ✅ ++s
        int s = 0;
        for (int i = 0; i < taille; ++i) {
            if (classe[i].estPresent) {
                ++s;
            }
        }
        return s;
    }
    
    void libererClasse(Etudiant*& classe) {
        delete[] classe;
        classe = nullptr;
    }
}

int main() {
    int taille;
    std::cout << "Nombre d'etudiants : ";
    std::cin >> taille;
    
    sgap::Etudiant* maClasse = sgap::creerClasse(taille);
    
    std::cout << "\n1. Tous absents :\n";
    sgap::afficher(maClasse, taille);
    
    std::cout << "2. Validation ID 12346 :\n";
    sgap::validerParId(maClasse, taille, 12346);
    sgap::afficher(maClasse, taille);
    
    std::cout << "3. Tous valides :\n";
    sgap::validerTousPresents(maClasse, taille);
    sgap::afficher(maClasse, taille);
    
    int presents = sgap::compterPresents(maClasse, taille);
    std::cout << "4. Nombre de presents : " << presents << "/" << taille << "\n";
    
    sgap::libererClasse(maClasse);
    
    return 0;
}