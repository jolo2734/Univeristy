#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <fstream>

using namespace std;

string temat, nick, linia, odpowiedz;
string tresc[5];
string odpA[5], odpB[5], odpC[5], odpD[5], odp[5];
int nr_linii=1;
int nr_pytania=1;
int punkty=0;
int ilosc_pytan=0;

int main()
{
    fstream plik;
    plik.open("quiz.txt", ios::in);

    if(plik.good()==false)
    {
        cout<<"Nie ma takiego pliku!"<<endl;
        exit(0);
    }

    while(getline(plik,linia))
    {
        switch(nr_linii)
        {
            case 1: temat=linia; break;
            case 2: nick=linia; break;
            case 3: tresc[nr_pytania-1]=linia; break;
            case 4: odpA[nr_pytania-1]=linia; break;
            case 5: odpB[nr_pytania-1]=linia; break;
            case 6: odpC[nr_pytania-1]=linia; break;
            case 7: odpD[nr_pytania-1]=linia; break;
            case 8: odp[nr_pytania-1]=linia; break;
        }
        if(nr_linii==8)
        {
            nr_linii=2;
            nr_pytania++;
        }
        nr_linii++;
    }

    ilosc_pytan=nr_pytania-1;

    for (int i=0; i<ilosc_pytan; i++)
    {
        cout<<"Ilosc pytan: "<<ilosc_pytan<<endl;
        cout<<"Twoje punkty: "<<punkty<<endl<<endl;
        cout<<"Pytanie nr "<<i+1<<". "<<endl<<tresc[i]<<endl;
        cout<<"A. "<<odpA[i]<<endl;
        cout<<"B. "<<odpB[i]<<endl;
        cout<<"C. "<<odpC[i]<<endl;
        cout<<"D. "<<odpD[i]<<endl;
        cout<<"Twoja odpowiedz: ";
        odpowiedz=getch();
        cout<<endl;

        if(odpowiedz==odp[i])
        {
            punkty++;
            cout<<"Brawo zdobyles punkt :)"<<endl;
        }
        else
        {
            cout<<"Niestety to nie byla dobra odpowiedz :("<<endl;
            cout<<"Poprawna odpowiedz to: "<<odp[i]<<endl;
        }
        cout<<endl;
        cout<<"Nacisnij dowolny przycisk alby przejsc do nastepnego pytania..."<<endl;
        getch();
        system("cls");
    }
        cout<<"Ilosc pytan: "<<ilosc_pytan<<endl;
        cout<<"Twoje punkty: "<<punkty<<endl<<endl;
    return 0;
}
