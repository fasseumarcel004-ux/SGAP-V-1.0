#include <iostream>
#include <string>

namespace sgap {
    namespace stats {
        float tauxPresence(int nbPresents, int nbTotal) {
            return static_cast<float>(nbPresents)/nbTotal;
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
    int compterAbsents(int total, int presents) {
        return total - presents;
    }
    
}

int main() {
    int total;
    int presents;
    
    // TODO 1 : Demander à l'utilisateur le nombre total d'étudiants
    std::cout << "Nombre total d'etudiants : ";
    std::cin >> total;
    
    std::cout << "Demander le nombre de présents :";
    std::cin >> presents;
    
    // TODO 3 : Calculer absents, taux, évaluation
    int absents = sgap::compterAbsents(total,presents);
    float taux = sgap::stats::tauxPresence(presents,total);
    std::string eval = sgap::stats::evaluerSeance(taux);
    
    // TODO 4 : Afficher le bilan complet
    // "Presents : X | Absents : Y | Taux : Z.ZZ | Evaluation : [mot]"
    std::cout << "Presents : " << presents << " | Absents : " << absents << " | Taux : " << taux << " | Evaluation : " << eval << "\n";
    if(taux < 0.50f){
        std::cout << "ALERTE : Taux critique - Verification requise";
    }
    return 0;
}