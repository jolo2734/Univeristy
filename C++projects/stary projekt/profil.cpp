#include"profil.h"
#include<iostream>
#include<string>
#include"menu.h"
#include<cstdlib>

profil::profil()
{
    imie="Bartlomiej";
    nazwisko="Matejuk";
    wiek=20;
    waga=85;
    wzrost=180;//wartosci domniemane
}
void profil::wyswietl()
{
    std::cout<<imie;
    std::cout<<" "<<nazwisko<<std::endl;
    std::cout<<"Wiek   : "<<wiek<<" lat"<<std::endl;
    std::cout<<"Waga   : "<<waga<<" kg"<<std::endl;
    std::cout<<"Wzrost : "<<wzrost<<" cm"<<std::endl;
}
void profil::edytuj()
{
std::string ximie;
std::string xnazwisko;
int xwiek;
float xwaga;
float xwzrost;
float bmi;
std::cout<<"Nowe imie : "<<std::endl;
std::getline(std::cin,ximie);
std::cout<<"Nowe nazwisko : "<<std::endl;
std::getline(std::cin,xnazwisko);
std::cout<<"Nowy wiek : "<<std::endl;
std::cin>>xwiek;
std::cout<<"Nowa waga : [kg]"<<std::endl;
std::cin>>xwaga;
std::cout<<"Nowy wzrost : [cm]"<<std::endl;
std::cin>>xwzrost;
bmi=10000*xwaga/(xwzrost*xwzrost);
std::cout<<"Twoje BMI : "<<bmi<<" - ";
if(bmi>=25)
    {
        std::cout<<"MASZ NADWAGE, TRUDNIEJ CIE UKRASC"<<std::endl;
    }
if(bmi>=18 && bmi<25)
    {
    std::cout<<"JESTES IDEALNA/Y, PRZYNAJMNIEJ TWOJA WAGA TAK MOWI..."<<std::endl;
    }
if(bmi<18)
    {
        std::cout<<"ZACZNIJ JESC, CHUDYCH SIE GORZEJ PRZYTULA"<<std::endl;
    }
imie=ximie;
nazwisko=xnazwisko;
wiek=xwiek;
waga=xwaga;
wzrost=xwzrost;
}
profil::~profil()
{

}

void profil::kalorie()
{
    int q,s;
    float bialko,wegle,tluszcze;
    float zapotrzebowanie;
    zapotrzebowanie=66.5+(13.7*waga)+(5*wzrost)-(6.8*wiek);
    std::cout<<"OBLICZANIE ZAPOTRZEBOWANIA KALORYCZNEGO"<<std::endl;
        std::cout<<"Jaka jest twoja aktywnosc w ciagu tygodnia?: "<<std::endl;
        std::cout<<"1 - mala(siedzacy tryb zycia)"<<std::endl;
        std::cout<<"2 - srednia(2-4 treningi w tygodniu)"<<std::endl;
        std::cout<<"3 - duza(ciezka praca fizyczna/5-7 treningow)"<<std::endl;
        std::cin>>s;
        if(s==1)
            zapotrzebowanie=zapotrzebowanie*1.1;
        if(s==2)
        zapotrzebowanie=zapotrzebowanie*1.5;
        if(s==3)
            zapotrzebowanie=zapotrzebowanie*2;
    std::cout<<" 1 - chce schudnac"<<std::endl;
    std::cout<<" 2 - chce przytyc"<<std::endl;
    std::cout<<" 3 - chce utrzymac wage"<<std::endl;
    std::cin>>q;
    if(q==1)
    {
        zapotrzebowanie=zapotrzebowanie-(0.15*zapotrzebowanie);
        std::cout<<"Twoje zapotrzebowanie wynosi : "<<zapotrzebowanie<<"kcal"<<std::endl;
    }
    if(q==2)
    {
        zapotrzebowanie=zapotrzebowanie+(0.15*zapotrzebowanie);
        std::cout<<"Twoje zapotrzebowanie wynosi : "<<zapotrzebowanie<<"kcal"<<std::endl;

    }
    if(q==3)
    {
        std::cout<<"Twoje zapotrzebowanie wynosi : "<<zapotrzebowanie<<"kcal"<<std::endl;
    }
    bialko=waga*2;
        tluszcze=0.25*zapotrzebowanie;
        wegle=(zapotrzebowanie-tluszcze-(bialko*4))/4;
        tluszcze=tluszcze/9;
        std::cout<<std::endl;
        std::cout<<"Przykladowy rozklad makroskladnikow"<<std::endl;
        std::cout<<"Bialko:      "<<bialko<<"g"<<std::endl;
        std::cout<<"Weglowodany: "<<wegle<<"g"<<std::endl;
        std::cout<<"Tluszcze:    "<<tluszcze<<"g"<<std::endl;
}
