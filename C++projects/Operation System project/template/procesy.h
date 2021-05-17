#include <iostream>
#include <vector>

class Procesy
{
    public:
    std::string nazwa;
      int czas_przyjscia;
    int czas_wykonania;


    Procesy();
    Procesy(std::string nazwa, int czas_przyjscia, int czas_wykonania);
    void wczytaj();
    void wypisz();

    std::vector<Procesy> dane;
};
