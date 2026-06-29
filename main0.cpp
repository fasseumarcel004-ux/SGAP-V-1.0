#include<iostream>
#include<string>
int main(){
    std::string  prenom;
    std::cout<<"Entre ton prénom : ";
    std::cin >> prenom;
    int a,b;
    std::cout<<"Frappe un entier : ";
    std::cin >> a;
    std::cout<<"Frappe un entier : ";
    std::cin >> b;

    std::cout<<"Bonjour "<<prenom<<std::endl;
    std::cout<<"Somme = "<<a+b<<std::endl;
    std::cout<<"Difference = "<<a-b<<std::endl;
    std::cout<<"Produit = "<<a*b<<std::endl;
    std::cout<<"Division = "<<a/b<<std::endl;
    if(a<b){
        std::cout<<a<<" inferieur à "<<b<<"\n";
    }else if(a>b){
        std::cout<<a<<" superieur à "<<b<<"\n";
    }else{
        std::cout<<a<<" égal à "<<b<<"\n";
    }
    return 0;

}