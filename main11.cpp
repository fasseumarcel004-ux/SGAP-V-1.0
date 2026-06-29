#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <string>

namespace sgap {
    struct Etudiant {
        uint32_t id;
        std::string nom;
        bool estPresent;
    };
    
    void afficher(const std::vector<Etudiant>& classe) {
        for (const auto& e : classe) {
            std::cout << e.id << " | " << e.nom << " | "
                      << (e.estPresent ? "P" : "A") << "\n";
        }
        std::cout << "\n";
    }
    
    // TODO : Compléter cette fonction
    void supprimerParId(std::vector<Etudiant>& classe, uint32_t id) {
        auto trouve  =  std::find_if(classe.begin(), classe.end(), [id](const Etudiant& n){
            return n.id == id ;
        });
        if(trouve != classe.end()){
            classe.erase(trouve);
            std::cout << "Element supprime avec succes \n";

        }else{
            std::cout << "Aucun element ne correspond \n";
        }
    }
}

int main() {
    std::vector<sgap::Etudiant> classe = {
        {12345, "Stella", true},
        {12346, "Amara", false},
        {12347, "Fatou", true}
    };
    
    std::cout << "Avant suppression :\n";
    sgap::afficher(classe);
    

    sgap::supprimerParId(classe,12346);
    std::cout << "Apres suppression :\n";
    sgap::afficher(classe);
    
    return 0;
}