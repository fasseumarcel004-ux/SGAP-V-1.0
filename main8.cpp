#include <iostream>
namespace sgap{
    struct Data {
      int v;
    };

    void show(const Data& d) {
        std::cout << d.v << "\n";
    }

}


int main() {
    constexpr std::size_t TAILLE = 3;
    sgap::Data tab[TAILLE];
    tab[0] = {10};
    tab[1] = {20};
    tab[2] = {30};
    for (std::size_t i = 0; i < TAILLE; ++i) {
        sgap::show(tab[i]);
    }
    return 0;
}   