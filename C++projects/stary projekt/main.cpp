#include <iostream>
#include"menu.h"
#include"sila.h"
#include"aeroby.h"
#include"profil.h"
#include<string>

using namespace std;

int menu::y=0;
int menu::z=0;

int main()
{
    int n;

    sila plan;
    aeroby dziennik;
    profil osoba,czlowiek,ludzie;
    ludzie=czlowiek=osoba;//operator przypisania

    for(;;)
    {
        cout<<"_________________________________"<<endl;
        cout<<"MENU"<<endl;
        cout<<"Co chcesz zrobic?"<<endl;
        cout<<"  1 - dodaj cwiczenie silowe"<<endl;
        cout<<"  2 - wyswietl cwiczenia silowe"<<endl;
        cout<<"  3 - dodaj cwiczenie aerobowe"<<endl;
        cout<<"  4 - wyswietl cwiczenia aerobowe"<<endl;
        cout<<"  5 - wyswietl wszystkie cwiczenia"<<endl;
        cout<<"  6 - aktualizuj dane o sobie"<<endl;
        cout<<"  7 - wyswietl swoje dane"<<endl;
        cout<<"  8 - oblicz swoje zapotrzebowanie kaloryczne"<<endl;
        cout<<"  0 - WYJDZ!"<<endl;

        cout<<"Wybor : ";
        cin>>n;
        cin.ignore();//czyszczenie pamiêci
        cout<<endl;

        if(n==0)
            break;//wyjscie z petli nieskonczonej

        switch(n)//wykonanie menu
        {
        case 1:
            plan.wczytaj();
            menu::y++;
            break;
        case 2:
            plan.wyswietl();
            break;
        case 3:
            dziennik.wczytaj();
            menu::z++;
            break;
        case 4:
            dziennik.wyswietl();
            break;
        case 5:
            cout<<"CWICZENIA SILOWE"<<endl;
            cout<<"Ilosc cwiczen : "<<menu::y<<endl;
            plan.wyswietl();
            cout<<endl;
            cout<<"CWICZENIA AEROBOWE"<<endl;
            cout<<"Ilosc cwiczen : "<<menu::z<<endl;
            dziennik.wyswietl();
            break;
        case 6:
            osoba.edytuj();
            break;
        case 7:
            osoba.wyswietl();
            break;
        case 8:
            osoba.kalorie();
            break;
        }

    }
    return 0;
}
