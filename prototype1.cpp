#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include <sstream>

namespace sgap {
    struct Heure {
        uint8_t heure;
        uint8_t minute;
    };
    
    struct Etudiant {
        uint32_t id;
        std::string nom;
        Heure arrivee;        // Heure d'arrivée réelle
        bool estPresent;      // Déduit de l'heure
    };
   
    // Constantes du système
    constexpr uint8_t HEURE_DEBUT = 8;
    constexpr uint8_t MINUTE_DEBUT = 30;
    constexpr uint8_t HEURE_ABSENCE = 10;
    

    // === IMPLÉMENTATIONS À COMPLÉTER ===

    bool estPresentSelonHeure(const Heure& h) {
        // TODO : Retourne true si arrivée avant 10h00
        if(h.heure < HEURE_ABSENCE) return true;
        return false;
    }

    bool estEnRetard(const Heure& h) {
        // TODO : Retourne true si arrivée entre 8h31 et 9h59
        if((h.heure == HEURE_DEBUT && (h.minute >= MINUTE_DEBUT+1)) || (h.heure == HEURE_DEBUT+1 &&  h.minute <= MINUTE_DEBUT+29)){
            return true;
        }
        return false;
    }

    bool estAbsent(const Heure& h) {
        if(h.heure >= HEURE_ABSENCE) return true;
        return false;
    }

    void mettreAJourStatut(Etudiant& e) {
        // TODO : e.estPresent = estPresentSelonHeure(e.arrivee)
        e.estPresent = estPresentSelonHeure(e.arrivee);
    }

    std::string statutToString(const Etudiant& e) {
        // TODO : Retourne "Present", "Retard", ou "Absent" selon l'heure
        if(estEnRetard(e.arrivee)) return "Retard";
        if(estPresentSelonHeure(e.arrivee)) return "Present";
        if(estAbsent(e.arrivee)) return "Absent";
        return "Inconnu";
    }

    bool ajouterEtudiant(std::vector<Etudiant>& liste, uint32_t id,
                                const std::string& nom, const Heure& arrivee) {
        bool idExist = false;
        for(auto &n : liste){
            if(id == n.id){
                idExist = true;
                break;
            }
        }
        if(idExist){
           std::cout << "Cet ID existe déjà\n";
           return false;
        }else{
            Etudiant nouveau;
            nouveau.id = id;
            nouveau.nom = nom;
            nouveau.arrivee = arrivee;
            mettreAJourStatut(nouveau);
            liste.push_back(nouveau);  
        }
        // TODO : Vérifier ID unique
        // TODO : Créer Etudiant, appeler mettreAJourStatut, push_back
        return true;
    }

    void afficherListe(const std::vector<Etudiant>& liste) {
        std::cout << "===== LISTES ETUDIANTS ====\n";
        for(const auto& n : liste){
            std::cout << n.id << " | " << n.nom << " | " << static_cast<int>(n.arrivee.heure) << "H" 
                      << static_cast<int>(n.arrivee.minute) << " | " << statutToString(n)
                      << "\n";
        }


        // TODO : En-tête avec colonnes
        // TODO : ID | Nom | Heure | Statut
        std::cout << "Totaux : " << liste.size() << "\n";
    }

    float tauxPresence(const std::vector<Etudiant>& liste) {
        // TODO : presents / total en float
        if(liste.size() == 0){
            return 0.0f;
        }
        int presence = 0 ;
        for(const auto& n : liste){
            if(!estAbsent(n.arrivee)){
                presence ++;
            }
        }
        return presence / static_cast<float>(liste.size());
    }

        
    

    int compterPresents(const std::vector<Etudiant>& liste) {
        // TODO : Compter estPresent == true
        int compteur = 0 ;
        for(const auto& n : liste){
            if(!estAbsent(n.arrivee)){
                compteur ++;
            }
        }
        return compteur;
    }

    int compterRetards(const std::vector<Etudiant>& liste) {
        // TODO : Compter estEnRetard(heure)
        int compteur = 0 ;
        for(const auto& n : liste){
            if(estEnRetard(n.arrivee)){
                compteur ++;
            }
        }
        return compteur;
    }

    int compterAbsents(const std::vector<Etudiant>& liste) {
        // TODO : Compter !estPresent
        int compteur = 0;
        for(const auto& n : liste){
            if(estAbsent(n.arrivee)){
                compteur ++;
            }
        }
        return compteur;
    }

    // === FICHIERS ===
    namespace fichier {

    
        bool sauvegarderCSV(const std::vector<Etudiant>& liste, 
                                            const std::string& chemin) {
            
            // TODO : Format CSV avec heure
            // id,nom,heure,minute,statut
            std::ofstream f(chemin);
            if(!f.is_open()){
                std::cout << "ERROR\n";
                return false;
            }
            f << "id,nom,heure,minute,statut\n";
            for(const auto& n : liste){
                f << n.id << "," << n.nom << "," << static_cast<int>(n.arrivee.heure) << "," << static_cast<int>(n.arrivee.minute)
                          << "," ;
                if(estEnRetard(n.arrivee)){
                    f << "R";
                }else if(estAbsent(n.arrivee)){
                    f << "A";
                }else{
                    f << "P";
                }
                f << "\n";
            }
            f.close();
            return true;
        }

        bool chargerCSV(std::vector<Etudiant>& liste, 
                                        const std::string& chemin) {
            
            std::ifstream fichier(chemin);
            if(!fichier.is_open()){
                std::cout << "ERROR\n";
                return false;
            }
            std::string ligne;
            std::getline(fichier, ligne);
            while(std::getline(fichier, ligne)){
                std::stringstream ss(ligne);
                std::string idStr,nomStr,heureStr,minuteStr,statutStr;
                if(std::getline(ss,idStr,',') && std::getline(ss,nomStr,',') && std::getline(ss,heureStr,',') 
                      && std::getline(ss,minuteStr,',') && std::getline(ss,statutStr)){
                    Etudiant e;
                    e.id = static_cast<uint32_t>(std::stoi(idStr));
                    bool idExist = false;
                    for(auto& n : liste){
                        if(n.id == e.id){
                            idExist = true;
                            break;
                        }
                    }
                    if(!idExist){
                        e.nom = nomStr;
                        e.arrivee.heure = static_cast<uint8_t>(std::stoi(heureStr));
                        e.arrivee.minute = static_cast<uint8_t>(std::stoi(minuteStr));
                        mettreAJourStatut(e);
                        liste.push_back(e);
                    }
                }
            }
            return true;
        }
    }

        // === MENU ===

    void afficherMenu() {
        std::cout << "\n========== SGAP Console v1.0 ==========\n";
        std::cout << "1. Ajouter un etudiant (avec heure d'arrivee)\n";
        std::cout << "2. Afficher la liste avec statuts\n";
        std::cout << "3. Taux de presence / retard / absence\n";
        std::cout << "4. Sauvegarder (CSV)\n";
        std::cout << "5. Charger (CSV)\n";
        std::cout << "0. Quitter\n";
        std::cout << "=======================================\n";
        std::cout << "Choix : ";
    }
    
}

int main() {
    std::vector<sgap::Etudiant> liste;
    int choix;

    do {
        sgap::afficherMenu();
        std::cin >> choix;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Saisie invalide. Entrez un nombre.\n";
            continue;
        }

        switch (choix) {
            case 1: {
                uint32_t id;
                std::string nom;
                int heure, minute;
                
                std::cout << "ID : ";
                std::cin >> id;
                std::cout << "Nom : ";
                std::cin >> nom;
                std::cout << "Heure d'arrivee (HH MM) : ";
                std::cin >> heure >> minute;
                
                sgap::Heure h {static_cast<uint8_t>(heure), 
                               static_cast<uint8_t>(minute)};
                if(sgap::ajouterEtudiant(liste, id, nom, h)){;
                     std::cout << "Etudiant ajouté. Statut : " 
                               << sgap::statutToString(liste.back()) << "\n";
                }else{
            
                }
                break;
            }
            case 2: {
                sgap::afficherListe(liste);
                break;
            }
            case 3: {
                std::cout << "Presents : " << sgap::compterPresents(liste) << "\n";
                std::cout << "Retards  : " << sgap::compterRetards(liste) << "\n";
                std::cout << "Absents  : " << sgap::compterAbsents(liste) << "\n";
                std::cout << "Taux presence : " << sgap::tauxPresence(liste) * 100.0f << "%\n";
                break;
            }
            case 4: {
                if (sgap::fichier::sauvegarderCSV(liste, "presences.csv")) {
                    std::cout << "Sauvegarde OK.\n";
                } else {
                    std::cout << "Erreur sauvegarde.\n";
                }
                break;
            }
            case 5: {
                if (sgap::fichier::chargerCSV(liste, "presences.csv")) {
                    std::cout << "Chargement OK.\n";
                } else {
                    std::cout << "Erreur chargement.\n";
                }
                break;
            }
            case 0: {
                std::cout << "Au revoir !\n";
                break;
            }
            default: {
                std::cout << "Choix invalide.\n";
            }
        }
    } while (choix != 0);
    return 0;
}