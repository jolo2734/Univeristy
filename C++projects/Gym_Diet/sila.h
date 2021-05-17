#pragma once
#include<iostream>
#include<string>
#include"menu.h"
#include<vector>

class sila:public menu//dziedziczenie
{
    int serie;
    int powtorzenia;

    std::vector<sila>silownia;//vector
public:
       const sila& operator=(const sila& sila)//operator przypisania deklaracja
       {
           this->serie=sila.serie;
           this->powtorzenia=sila.powtorzenia;
           return sila;//lub return *this
       }
    sila();
    sila(std::string nazwa,int czestotliwosc,int serie,int powtorzenia);
    void wczytaj();// funkcje wirtualne
    void wyswietl();
    ~sila();
};
