#include <iostream>
#include <vector>
#include <cstdint>
#include <string>

namespace sgap {
    struct Etudiant {
        uint32_t id;
        std::string nom;
        bool estPresent;
    };
    
    void afficher(const std::vector<Etudiant>& classe) {
        std::cout << "=== Liste etudiants ===\n";
        for (const auto& e : classe) {   // ✅ const auto& pour lecture
            std::cout << e.id << " | " << e.nom << " | "
                      << (e.estPresent ? "Present" : "Absent") << "\n";
        }
        std::cout << "\n";
    }
    
    void validerTousPresents(std::vector<Etudiant>& classe) {
        for (auto& e : classe) {
            e.estPresent = true;
        }
    }
    
    void validerParId(std::vector<Etudiant>& classe, uint32_t id) {
        for (auto& e : classe) {
            if (e.id == id) {
                e.estPresent = true;
                break;   // ✅ ID unique = arrêt immédiat
            }
        }
    }
    
    int compterPresents(const std::vector<Etudiant>& classe) {
        int s = 0;
        for (const auto& e : classe) {   // ✅ const auto& = lecture seule
            if (e.estPresent) {
                ++s;
            }
        }
        return s;
    }
}

int main() {
    std::vector<sgap::Etudiant> classe = {
        {12345, "Stella", false},
        {12346, "Amara", false},
        {12347, "Fatou", false}
    };
    
    std::cout << "1. Tous absents :\n";
    sgap::afficher(classe);
    
    std::cout << "2. Validation ID 12346 :\n";
    sgap::validerParId(classe, 12346);
    sgap::afficher(classe);
    
    std::cout << "3. Tous valides :\n";
    sgap::validerTousPresents(classe);
    sgap::afficher(classe);
    
    int nombrePresents = sgap::compterPresents(classe);
    std::cout << "Presents : " << nombrePresents << "/" << classe.size() << "\n\n";
    
    std::cout << "4. Ajout etudiant :\n";
    classe.push_back({12348, "Tamo", false});
    sgap::afficher(classe);
    
    std::cout << "Taille finale : " << classe.size() << "\n";
    
    return 0;
}