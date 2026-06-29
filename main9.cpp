#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

namespace sgap {
    struct Etudiant {
        uint32_t id;
        std::string nom;
        bool estPresent;
    };
    
    void afficher(const std::vector<Etudiant>& classe) {   // const& = pas de copie
        for (const auto& e : classe) {                     // const auto& = pas de copie
            std::cout << e.id << " | " << e.nom << " | "
                      << (e.estPresent ? "P" : "A") << "\n";
        }
    }
    
    void validerTousPresents(std::vector<Etudiant>& classe) {
        for (auto& e : classe) {
            e.estPresent = true;
        }
    }
    
    int compterPresents(const std::vector<Etudiant>& classe) {
        int s = 0;
        for (const auto& e : classe) {
            if (e.estPresent) {
                ++s;
            }
        }
        return s;
    }
}

int main() {
    // Création directe, pas de new[]
    std::vector<sgap::Etudiant> classe = {
        {12345, "Stella", false},
        {12346, "Amara", false},
        {12347, "Fatou", false}
    };
    
    // Ajout dynamique à la volée
    classe.push_back({12348, "Ibrahim", false});
    
    std::cout << "Taille : " << classe.size() << "\n\n";
    
    std::cout << "=== Avant ===\n";
    sgap::afficher(classe);
    
    sgap::validerTousPresents(classe);
    
    std::cout << "\n=== Apres ===\n";
    sgap::afficher(classe);
    
    std::cout << "\nPresents : " << sgap::compterPresents(classe) << "\n";
    
    // Pas de delete ! Pas de nullptr !
    return 0;
}