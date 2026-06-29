#include <iostream>

namespace math {
    void doubler(int* ptr) {   // Pointeur vers int
        if (ptr != nullptr) {   // ✅ Vérification obligatoire
            *ptr *= 2;            // Déréférencement pour modifier
        }
    }
}

int main() {
    int a = 5;
    math::doubler(&a);        // Passe l'adresse de a
    std::cout << a << "\n";   // 10
    
    math::doubler(nullptr);   // ✅ Sécurisé, ne plante pas
    return 0;
}




int notes[5] = {10, 12, 15, 8, 14};

int* ptr = notes;        // ✅ ptr pointe vers notes[0]

std::cout << *ptr << "\n";      // 10 (notes[0])
std::cout << *(ptr + 1) << "\n"; // 12 (notes[1])
std::cout << ptr[2] << "\n";     // 15 (équivalent à *(ptr + 2))

   




#include <iostream>

int main() {
    int taille;
    std::cout << "Nombre d'etudiants : ";
    std::cin >> taille;
    
    // Allocation dynamique (taille inconnue à la compilation)
    int* notes = new int[taille];   // Tableau dynamique
    
    for (int i = 0; i < taille; ++i) {
        notes[i] = 10 + i;          // Remplissage
    }
    
    // Utilisation...
    
    delete[] notes;   // ✅ LIBÉRATION OBLIGATOIRE
    notes = nullptr;  // ✅ Éviter le dangling pointer
    
    return 0;
}


#include <iostream>
#include <string>
#include <cstdint>

namespace sgap {
    struct Etudiant {
        uint32_t id;
        std::string nom;
        bool estPresent;
    };
}

int main() {
    int nombre;
    std::cout << "Nombre d'etudiants : ";
    std::cin >> nombre;
    
    // Allocation dynamique
    sgap::Etudiant* classe = new sgap::Etudiant[nombre];
    
    // Remplissage
    for (int i = 0; i < nombre; ++i) {
        classe[i].id = 12345 + i;
        classe[i].nom = "Etudiant " + std::to_string(i + 1);
        classe[i].estPresent = false;
    }
    
    // Affichage
    std::cout << "=== Liste ===\n";
    for (int i = 0; i < nombre; ++i) {
        std::cout << classe[i].id << " | " << classe[i].nom << "\n";
    }
    
    // Libération
    delete[] classe;
    classe = nullptr;
    
    return 0;
}