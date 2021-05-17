#include"aeroby.h"
#include<iostream>
#include<string>

aeroby::aeroby()
{

}
aeroby::aeroby(std::string nazwa,int czestotliwosc,int czas,int intensywnosc)
    :menu(nazwa,czestotliwosc),czas(czas),intensywnosc(intensywnosc)
{

}
void aeroby::wczytaj()
{
    std::cout<<"DODAWANIE NOWEGO CWICZENIA AEROBOWEGO"<<std::endl;
    std::cout<<"Podaj nazwe cwiczenia: ";
    std::getline(std::cin,nazwa);
    std::cout<<"Czestotliwosc w tygodniu:";
    std::cin>>czestotliwosc;
    std::cout<<"Dlugosc cwiczenia [min]: ";
    std::cin>>czas;
    std::cout<<"Intensywnosc [1-5] : ";
    std::cin>>intensywnosc;
    std::cin.ignore();
    podworko.push_back(aeroby(nazwa,czestotliwosc,czas,intensywnosc));
}
void aeroby::wyswietl()
{
    for(int i=0; i<podworko.size(); i++)
    {
        std::cout<<"Nazwa:                    "<<podworko[i].nazwa<<std::endl;
        std::cout<<"Czestotliwosc w tygodniu: "<<podworko[i].czestotliwosc<<std::endl;
        std::cout<<"Ilosc serii:              "<<podworko[i].czas<<std::endl;
        std::cout<<"Ilosc powtorzen:          "<<podworko[i].intensywnosc<<std::endl;
    }
}

aeroby::~aeroby()
{

}
