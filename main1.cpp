#include<iostream>
#include<string>
int solde_initial = 100000;
int retirer(int a){
   return solde_initial = solde_initial - a;
}
int deposer(int a){
    return solde_initial = solde_initial + a;

}

int main(){
    int depot, choix ,retrait;
    

    do
    {  
        std::cout <<"\n1 - Voir solde\n";
        std::cout <<"2 - Déposer argent\n";
        std::cout <<"3 - Retirer argent\n";
        std::cout <<"4 - Quitter\n";
    

        std::cout <<"\n ##--Entrer votre choix--## : : ";
        std::cin>> choix;
        switch (choix)
        {
        case 1:
        
            std::cout <<solde_initial<<" FCFA";
            
            break;
        case 2:
        
            std::cout<<"Vous voulez déposer combien : ";
            std::cin>>depot;
            deposer(depot);
            break;
        case 3:
            std::cout<<"Vous voulez retirer combien : ";
            std::cin>>retrait;
            if (retrait > solde_initial){
                std::cout<<"Impossible de retirer cette somme d'argent, montant du solde insuffisant";
            }else{
                retirer(retrait);
            }
            break;
        case 4:
            break;
        default:
            std::cout<< "Numéro invalide";
            break;
        }
    } while(choix !=4);
    

    return 0;

}
