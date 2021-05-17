#include <iostream>
#include "procesy.h"
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std;

bool sortowanie(const Procesy & l, const Procesy &r )
{
    return l.czas_przyjscia<r.czas_przyjscia;
}
int main()
{
    float czekanie=0;
    float dzialanie=0;
    srand(time(NULL));
    Procesy test;
    test.tworz_zapisz();
    test.wczytaj();
    sort(test.dane.begin(), test.dane.end(), sortowanie);//sortowanie po czasie przyjœcia
    test.wypisz();

    //ALORYTM FCFS

    int g=0;//lizcznik czasu wykonania+czasu czekania
    for(unsigned int h=0; h<test.dane.size(); h++)//pêtla po iloœci procesow
    {
        if(g>=test.dane[h].czas_przyjscia)
        {
            cout<<"-->Process name: "<<test.dane[h].nazwa<<"     Execution time: "<<test.dane[h].czas_wykonania<<"s"<<endl;
            cout<<"Processing...";
            Sleep(test.dane[h].czas_wykonania*1000);
            dzialanie=dzialanie+test.dane[h].czas_wykonania;
            cout<<"End."<<endl;
            g=g+test.dane[h].czas_wykonania;
            cout<<endl;
        }
        else
        {
            cout<<"Waiting for process...";
            cout<<test.dane[h].czas_przyjscia-g<<"s"<<endl;
            Sleep((test.dane[h].czas_przyjscia-g)*1000);
            czekanie=czekanie+test.dane[h].czas_przyjscia-g;
            cout<<"-->Process name: "<<test.dane[h].nazwa<<"     Execution time: "<<test.dane[h].czas_wykonania<<"s"<<endl;
            cout<<"Processing...";
            Sleep(test.dane[h].czas_wykonania*1000);
            dzialanie=dzialanie+test.dane[h].czas_wykonania;
            cout<<"End."<<endl;
            g=test.dane[h].czas_przyjscia+test.dane[h].czas_wykonania;
            cout<<endl;
        }
    }
    cout<<"Total time of served: "<<g<<"s"<<endl;
    cout<<"Average execution time per one process: "<<dzialanie/test.dane.size()<<"s"<<endl;
    cout<<"Average waiting time per one process: "<<czekanie/test.dane.size()<<"s"<<endl;
    ofstream wyniki;
    wyniki.open("wyniki_test1.txt",ios::out);
        wyniki<<"Total time of served: "<<g<<"s"<<endl;
        wyniki<<"Average execution time per one process: "<<dzialanie/test.dane.size()<<"s"<<endl;
        wyniki<<"Average waiting time per one process: "<<czekanie/test.dane.size()<<"s"<<endl;

    wyniki.close();
    return 0;
}
