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
    srand(time(NULL));
    Procesy test;
    test.tworz_zapisz();
    test.wczytaj();
    sort(test.dane.begin(), test.dane.end(), sortowanie);//sortowanie po czasie przyjœcia
    test.wypisz();

    //ALORYTM ROUND ROBIN
    float czekanie=0;
    float dzialanie=0;
    int minimum;
    int indeks;
    int l=1;
    int maks_przyjscia;
    maks_przyjscia=test.dane[test.dane.size()-1].czas_przyjscia;

    vector<int>lista_przyjscie;
    vector<string>lista_nazw;
    int q;//kwant czasu
    int e;
    q=rand()%3+1;
    string a;
    int b,c;
    cout<<"Quantum of time: "<<q<<endl<<endl;
    int g=0;//lizcznik czasu wykonania+czasu czekania
    e=test.dane.size();
    for(unsigned int h=0; h<e; h++)//pêtla po iloœci procesow
    {

        if(test.dane.empty()==true)
        {
            break;
        }
        if(g>=test.dane[h].czas_przyjscia)
        {

            if(test.dane[h].czas_wykonania<=q)
            {
                cout<<"-->Process name: "<<test.dane[h].nazwa<<"     Execution time: "<<test.dane[h].czas_wykonania<<"s"<<endl;
                cout<<"Processing...";
                Sleep(test.dane[h].czas_wykonania*1000);
                dzialanie=dzialanie+test.dane[h].czas_wykonania;
                cout<<"End."<<endl;
                g=g+test.dane[h].czas_wykonania;
                cout<<endl;
                test.dane.erase(test.dane.begin()+h);
                h--;

            }
            else
            {
                for(unsigned int w=0; w<test.dane.size(); w++)
                {
                    if(test.dane[w].czas_przyjscia<=g)
                    {
                        lista_przyjscie.push_back(test.dane[w].czas_przyjscia);
                        lista_nazw.push_back(test.dane[w].nazwa);
                    }
                }
                cout<<"Compare: "<<endl;
                minimum=lista_przyjscie[0];
                indeks=0;
                for(unsigned int i=0; i<lista_przyjscie.size(); i++)
                {
                    cout<<"Name: "<<lista_nazw[i]<<" Arrival time: "<<lista_przyjscie[i]<<"s"<<endl;
                    if(lista_przyjscie[i]<minimum)
                    {
                        minimum=lista_przyjscie[i];
                        indeks=i;
                    }
                }
                if(test.dane[indeks].czas_wykonania>q)
                {
                    g=g+q;
                }
                else
                {
                    g=g+test.dane[indeks].czas_wykonania;
                }
                cout<<"-->Process name: "<<lista_nazw[indeks]<<"    Execution time: "<<q<<"s"<<endl;
                cout<<"Processing...";
                Sleep(test.dane[indeks].czas_wykonania*1000);
                dzialanie=dzialanie+test.dane[indeks].czas_wykonania;
                cout<<"Process stop"<<endl;
                cout<<endl;
                a=test.dane[indeks].nazwa;
                b=maks_przyjscia+1;//test.dane[indeks].czas_przyjscia
                c=test.dane[indeks].czas_wykonania-q;
                test.dane.push_back(Procesy(a,b,c));
                test.dane.erase(test.dane.begin()+indeks);
                lista_nazw.clear();
                lista_przyjscie.clear();
                h=-1;
                l++;
            }
        }
        /*ooooooooooooooooooooooooo
            else if(test.dane[h].czas_przyjscia<=test.dane[h+1].czas_przyjscia&&test.dane[h].czas_przyjscia!=0&&g<test.dane[h+1].czas_przyjscia)
            {
                cout<<"Wchodze do dziwnej pętli"<<endl;
                cout<<"-->Process name: "<<test.dane[h].nazwa<<"     Execution time: "<<q<<"[s]"<<endl;
                cout<<"Processing...";
                Sleep((test.dane[h].czas_wykonania)*1000);

                test.dane[h].czas_wykonania=test.dane[h].czas_wykonania-q;
                if(test.dane[h].czas_wykonania<=0)
                {
                    cout<<"End."<<endl;
                    test.dane.erase(test.dane.begin()+h);
                }
                else
                {
                        cout<<"Process stop"<<endl;
                }
                if(test.dane[indeks].czas_wykonania>q)
                {
                    g=g+q;
                }
                else
                {
                    g=g+test.dane[indeks].czas_wykonania;
                }
                cout<<endl;

                h--;

            }//ooooooooooooooooooooooooo*/
        else
        {
            cout<<endl;
            cout<<"Waiting for process..."<<test.dane[h].czas_przyjscia-g<<"s"<<endl;
            Sleep((test.dane[h].czas_przyjscia-g)*1000);
            czekanie=czekanie+test.dane[h].czas_przyjscia-g;
            g=test.dane[h].czas_przyjscia;
            h--;
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<"Total time of served: "<<g<<"s"<<endl;
    cout<<"Average execution time per one process: "<<dzialanie/e<<"s"<<endl;
    cout<<"Average waiting time per one process: "<<czekanie/e<<"s"<<endl;
    ofstream wyniki;
  wyniki.open("wyniki_test1.txt",ios::out);
        wyniki<<"Total time of served: "<<g<<"s"<<endl;
        wyniki<<"Average execution time per one process: "<<dzialanie/e<<"s"<<endl;
        wyniki<<"Average waiting time per one process: "<<czekanie/e<<"s"<<endl;

    wyniki.close();
    return 0;
}
