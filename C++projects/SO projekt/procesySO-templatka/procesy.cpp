#include "procesy.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

Procesy::Procesy()
{
    std::cout<<"Konstruktor dziala(kiedy tworze obiekt)"<<std::endl;
}
Procesy::Procesy(std::string nazwa, int czas_przyjscia, int czas_wykonania)
:nazwa(nazwa),czas_przyjscia(czas_przyjscia),czas_wykonania(czas_wykonania)
{

}

void Procesy::wczytaj()
{

    std::ifstream plik;
    plik.open("dane_procesow.txt",std::ios::in);
    if(plik.good()==false)
    {
        std::cout<<"Nie udalo sie otworzyc pliku..."<<std::endl;
        exit(0);
    }
    std::cout<<"Wczytuje dane z pliku..."<<std::endl;
    int i=0;
    char znak;
    std::string a;
    int b;
    int c;
    if(plik.is_open())
    {
        while(plik>>znak)
        {
            plik>>a;
            plik>>b;
            plik>>c;
            dane.push_back(Procesy(a,b,c));
            i++;
        }
    }
    plik.close();
}

void Procesy::wypisz()
{
for(int i=0;i<dane.size();i++)
{
    std::cout<<"Nazwa: "<<dane[i].nazwa<<std::endl;
    std::cout<<"Czas przyjscia: "<<dane[i].czas_przyjscia<<std::endl;
    std::cout<<"Czas wykonania: "<<dane[i].czas_wykonania<<std::endl;
    std::cout<<std::endl;
}
}
