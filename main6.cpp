#include <iostream>

int main() {
    int nombre;
    
    // 1. Demander à l'utilisateur : "Nombre d'etudiants : "
    std::cout << "Nombre d'etudiants : ";
    std::cin >> nombre;
    // 2. Allouer dynamiquement un tableau de int (IDs)
    int *ids = new int[nombre];
    //    int* ids = new int[nombre];
    // 3. Remplir : 1000, 1001, 1002...
    for(int i = 0; i<nombre ; ++i){
        ids[i] = 1000 + i; 
    }
    // 4. Afficher tous les IDs
    std::cout << "=== Liste ===\n";
    for(int i = 0; i < nombre ; ++i){
         std::cout << "ids : " << ids[i] << "\n";
    }
    // 5. Libérer : delete[] ids; ids = nullptr;
    delete[] ids;
    ids = nullptr ;
    return 0;
}