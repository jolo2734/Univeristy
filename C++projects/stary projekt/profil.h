#pragma once
#include<iostream>
#include<string>

class profil
{
    std::string imie;
    std::string nazwisko;
    int wiek;
    float waga;
    float wzrost;
public:
    friend class menu;
    profil();
    void wyswietl();
    void edytuj();
    void kalorie();
    profil(profil&);
    ~profil();
};
