#pragma once
#include<iostream>
#include<string>
#include"menu.h"
#include<vector>

class aeroby:public menu
{
    int czas;
    int intensywnosc;
    std::vector<aeroby>podworko;
public:
    aeroby();
    aeroby(std::string nazwa,int czestotliwosc,int czas,int intensywnosc);
    void wczytaj();
    void wyswietl();
    ~aeroby();
};
