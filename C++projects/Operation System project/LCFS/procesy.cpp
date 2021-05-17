#include "procesy.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

Procesy::Procesy()
{

}
Procesy::Procesy(std::string nazwa, int czas_przyjscia, int czas_wykonania)
    :nazwa(nazwa),czas_przyjscia(czas_przyjscia),czas_wykonania(czas_wykonania)
{

}
void Procesy::tworz_zapisz()
{
    int x;//ilosc procesow
    x=rand()%9+1;
    int czas1[x];//przyjscia
    int czas2[x];//wykonania
    std::string nazwa_procesu[x];
    for(int i=0; i<x; i++)
    {
        nazwa_procesu[i]="SLEEPING_";
        czas1[i]=rand()%9;
        czas2[i]=rand()%3+1;
    }
    std::ofstream plik;
    plik.open("dane_procesow.txt",std::ios::out);//zapisywanie do pliku
    for(int j=0; j<x; j++)
    {
        plik<<j+1<<nazwa_procesu[j]<<j+1<<std::endl;
        plik<<czas1[j]<<std::endl;
        plik<<czas2[j]<<std::endl;
    }
    plik.close();
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
    for(int i=0; i<dane.size(); i++)
    {
        std::cout<<"Name: "<<dane[i].nazwa<<std::endl;
        std::cout<<"Arrival time: "<<dane[i].czas_przyjscia<<std::endl;
        std::cout<<"Execution time: "<<dane[i].czas_wykonania<<std::endl;
        std::cout<<std::endl;
    }
}
