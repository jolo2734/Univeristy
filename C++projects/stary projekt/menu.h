#pragma once
#include<iostream>
#include<string>
#include<vector>

class menu
{
public:
    friend class profil;//zaprzyjaznianie
    static int y;//zmienne statyczne
    static int z;
    std::string nazwa;
    int czestotliwosc;
    menu();
    virtual void wczytaj()=0;
    virtual void wyswietl()=0;//funkcje wirtualne
    menu(std::string nazwa,int czestotliwosc);//konstruktor
    ~menu();//destruktor
};
