#include <iostream>
#include <string>

namespace sgap::stats {
    float tauxPresence(int nbPresents, int nbTotal) {
        return static_cast<float>(nbPresents) / nbTotal;
    }
    
    std::string evaluerSeance(float taux) {
        if (taux > 0.90f) {
            return "Excellent";
        } else if (taux > 0.75f) {
            return "Bonne";
        }
        return "Faible";
    }
}

// ❌ CORRIGER CETTE FONCTION : supprimer les using, ajouter les préfixes
void afficherBilan(int presents, int total) {

    
    float t = sgap::stats(presents, total);
    std::cout << "Taux: " << t << " -> " << sgap::stats::evaluerSeance(t) << std::endl;
}