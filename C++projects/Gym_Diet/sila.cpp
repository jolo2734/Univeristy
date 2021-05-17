#include"sila.h"
#include<iostream>
#include<string>

sila::sila()
{

}
sila::sila(std::string nazwa,int czestotliwosc,int serie,int powtorzenia)
    :menu(nazwa,czestotliwosc),serie(serie),powtorzenia(powtorzenia)
{

}

void sila::wczytaj()
{
    std::cout<<"DODAWANIE NOWEGO CWICZENIA SILOWEGO"<<std::endl;
    std::cout<<"Podaj nazwe cwiczenia: ";
    std::getline(std::cin,nazwa);
    std::cout<<"Czestotliwosc w tygodniu:";
    std::cin>>czestotliwosc;
    std::cout<<"Ilosc serii: ";
    std::cin>>serie;
    std::cout<<"Ilosc powtorzen: ";
    std::cin>>powtorzenia;
    std::cin.ignore();
    silownia.push_back(sila(nazwa,czestotliwosc,serie,powtorzenia));
}
void sila::wyswietl()
{
    for(unsigned int i=0; i<=silownia.size(); i++)
    {
        std::cout<<"Nazwa:                    "<<silownia[i].nazwa<<std::endl;
        std::cout<<"Czestotliwosc w tygodniu: "<<silownia[i].czestotliwosc<<std::endl;
        std::cout<<"Ilosc serii:              "<<silownia[i].serie<<std::endl;
        std::cout<<"Ilosc powtorzen:          "<<silownia[i].powtorzenia<<std::endl;
        std::cout<<std::endl;
    }
}
sila::~sila()
{

}
