#include <iostream>
#include <time.h>
#include <fstream>
#include <cstdlib>
using namespace std;
string nazwa;
int id_klasa, obrazenia_min, obrazenia_max, szansa_na_kryt, zdrowie, mana, szybkosc, poziom_char=1;
string nazwa_potwora[10];
int id_potwora[10], obrazenia_min_potwora[10], obrazenia_max_potwora[10], szansa_na_kryt_potwora[10], zdrowie_potwora[10], szybkosc_potwora[10];
bool poziom[10];
void walka(int lvlmob);
void wybor_walki();
void menu1();
void menu2();
void wczytaj();
void zapisz();
void wybor_klasy();
int main()
{   
    menu1();
    return 0;
}
void walka(int lvlmob)
{
    nazwa_potwora[0]="Wilk";{
        obrazenia_min_potwora[0]=5;
        obrazenia_max_potwora[0]=10;
        szansa_na_kryt_potwora[0]=5;
        zdrowie_potwora[0]=25;
        szybkosc_potwora[0]=4;
    }
    nazwa_potwora[1]="Bandyta";{
        obrazenia_min_potwora[1]=5;
        obrazenia_max_potwora[1]=10;
        szansa_na_kryt_potwora[1]=5;
        zdrowie_potwora[1]=25;
        szybkosc_potwora[1]=4;
    }
    nazwa_potwora[2]="Wojownik";{
        obrazenia_min_potwora[2]=5;
        obrazenia_max_potwora[2]=10;
        szansa_na_kryt_potwora[2]=5;
        zdrowie_potwora[2]=25;
        szybkosc_potwora[2]=4;
    }
    nazwa_potwora[3]="Ork";{
        obrazenia_min_potwora[3]=5;
        obrazenia_max_potwora[3]=10;
        szansa_na_kryt_potwora[3]=5;
        zdrowie_potwora[3]=25;
        szybkosc_potwora[3]=4;
    }
    nazwa_potwora[4]="Gryf";{
        obrazenia_min_potwora[4]=5;
        obrazenia_max_potwora[4]=10;
        szansa_na_kryt_potwora[4]=5;
        zdrowie_potwora[4]=25;
        szybkosc_potwora[4]=4;
    }
    nazwa_potwora[5]="Golem";{
        obrazenia_min_potwora[5]=5;
        obrazenia_max_potwora[5]=10;
        szansa_na_kryt_potwora[5]=5;
        zdrowie_potwora[5]=25;
        szybkosc_potwora[5]=4;
    }
    nazwa_potwora[6]="Nekromanta";{
        obrazenia_min_potwora[6]=5;
        obrazenia_max_potwora[6]=10;
        szansa_na_kryt_potwora[6]=5;
        zdrowie_potwora[6]=25;
        szybkosc_potwora[6]=4;
    }
    nazwa_potwora[7]="Arcymag";{
        obrazenia_min_potwora[7]=5;
        obrazenia_max_potwora[7]=10;
        szansa_na_kryt_potwora[7]=5;
        zdrowie_potwora[7]=25;
        szybkosc_potwora[7]=4;
    }
    nazwa_potwora[8]="Walkiria";{
        obrazenia_min_potwora[8]=5;
        obrazenia_max_potwora[8]=10;
        szansa_na_kryt_potwora[8]=5;
        zdrowie_potwora[8]=25;
        szybkosc_potwora[8]=4;
    }
    nazwa_potwora[9]="Dis Gierczak";{
        obrazenia_min_potwora[9]=5;
        obrazenia_max_potwora[9]=10;
        szansa_na_kryt_potwora[9]=5;
        zdrowie_potwora[9]=25;
        szybkosc_potwora[9]=4;
    }

    int licznik=0, char_hp=zdrowie, mob_hp=zdrowie_potwora[lvlmob], rzut_koscia_char, rzut_koscia_mob,dmg, kryt;
    srand(time(NULL));
    if(lvlmob==10)
    {
    cout<<"!!!!BOSS!!!!"<<endl;
    }
    cout<<"Walczysz z: "<<nazwa_potwora[lvlmob]<<endl;
    cout<<"Jego statystyki: "<<"."<<endl;
    cout<<"Obrazenia: "<<obrazenia_min_potwora[lvlmob]<<"-"<<obrazenia_max_potwora[lvlmob]<<"."<<endl;
    cout<<"Szansa na trafienie krytyczne: "<<szansa_na_kryt_potwora[lvlmob]<<"."<<endl;
    cout<<"Punkty zycia: "<<zdrowie_potwora[lvlmob]<<"."<<endl;
    cout<<"Szybkosc "<<szybkosc_potwora[lvlmob]<<"."<<endl;
    if(szybkosc==szybkosc_potwora[lvlmob])
    {
        cout<<"Rzut koscia zadecyduje o inicjatywie."<<endl;
        do
            {
            rzut_koscia_char=rand()%6+1;
            rzut_koscia_mob=rand()%6+1;
            if(rzut_koscia_char!=rzut_koscia_mob)
            {
                licznik=1;
            }
            }while(licznik!=1);
            cout<<"Twoj rzut: "<<rzut_koscia_char<<"."<<endl;
            cout<<"Rzut przeciwnika: "<<rzut_koscia_mob<<"."<<endl;
        }
        if(szybkosc>szybkosc_potwora[lvlmob]||rzut_koscia_char>rzut_koscia_mob)
        {
            cout<<"Zaczynasz."<<endl;
            licznik=0;
            do
            {
            dmg=0;
            dmg=rand()%(obrazenia_max-obrazenia_min)+obrazenia_min;
            kryt=rand()%100+1;
            if(kryt<=szansa_na_kryt&&kryt>=1)
            {
                cout<<"TRAFIENIE KRYTYCZNE!"<<endl;
                dmg*=2;
            }
            cout<<"Zadales "<<dmg<<" obrazen!"<<endl;
            mob_hp-=dmg;
            if(mob_hp<=0)
            {
                cout<<"Zdrowie przeciwnika "<<"0."<<endl;
                if(lvlmob==9)
                {
                    cout<<"Gratulacje! Ukonczyles gre."<<endl;
                    exit(0);
                }                
                cout<<"Wygrales!"<<endl;
                licznik++;
                break;
            }
            else
            {
                cout<<"Zdrowie przeciwnika "<<mob_hp<<"."<<endl;
            }
            dmg=0;
            dmg=rand()%(obrazenia_max_potwora[lvlmob]-obrazenia_min_potwora[lvlmob])+obrazenia_min_potwora[lvlmob];
            kryt=rand()%100+1;
            if(kryt<=szansa_na_kryt_potwora[lvlmob]&&kryt>=1)
            {
                cout<<"TRAFIENIE KRYTYCZNE"<<endl;
                dmg*=2;
            }
            cout<<"Przeciwnik zadal Ci "<<dmg<<" obrazen!"<<endl;
            char_hp-=dmg;
            if(char_hp<=0)
            {
                cout<<"Twoje zdrowie "<<"0."<<endl;
                cout<<"Przegrales!"<<endl;
                licznik++;
                exit(0);
            }
            else
            {
                cout<<"Twoje zdrowie "<<char_hp<<"."<<endl;
            }
            }while(licznik!=1);
        }
        else if(szybkosc<szybkosc_potwora[lvlmob]||rzut_koscia_char<rzut_koscia_mob)
        {
            cout<<"Przeciwnik atakuje pierwszy."<<endl;
            licznik=0;
            do
            {
                dmg=0;
                dmg=rand()%(obrazenia_max_potwora[lvlmob]-obrazenia_min_potwora[lvlmob])+obrazenia_min_potwora[lvlmob];
                kryt=rand()%100+1;
                if(kryt<=szansa_na_kryt_potwora[lvlmob]&&kryt>=1)
                {
                    cout<<"TRAFIENIE KRYTYCZNE"<<endl;
                    dmg*=2;
                }
                cout<<"Przeciwnik zadal Ci "<<dmg<<" obrazen!"<<endl;
                char_hp-=dmg;
                if(char_hp<=0)
                {
                    cout<<"Twoje zdrowie "<<"0."<<endl;
                    cout<<"Przegrales!"<<endl;
                    licznik++;
                    exit(0);
                }
                else
                {
                    cout<<"Twoje zdrowie "<<char_hp<<"."<<endl;
                }
                dmg=0;
                dmg=rand()%(obrazenia_max-obrazenia_min)+obrazenia_min;
                kryt=rand()%100+1;
                if(kryt<=szansa_na_kryt&&kryt>=1)
                {
                    cout<<"TRAFIENIE KRYTYCZNE!"<<endl;
                    dmg*=2;
                }
                cout<<"Zadales "<<dmg<<" obrazen!"<<endl;
                mob_hp-=dmg;
                if(mob_hp<=0)
                {
                    cout<<"Zdrowie przeciwnika "<<"0."<<endl;
                    cout<<"Wygrales!"<<endl;
                    licznik++;
                    break;
                }
                else
                {
                    cout<<"Zdrowie przeciwnika "<<mob_hp<<"."<<endl;
                }
        }while(licznik!=1);
    }
}
void wybor_walki()
{
    int wybor,licznik=0;
    cout<<"wybierz poziom"<<endl;
    cout<<"dostepne poziomy:"<<endl;
    poziom[0]=true;
    for(int i=0;i<poziom_char;i++)
    {
        poziom[i]=true;
    }
    do
    {
        for(int i=0;i<10;i++)
        {
            if(poziom[i]==true)
            cout<<"poziom: "<<i+1<<". ";
        }
        cout<<endl;
        cin>>wybor;
        if(wybor<1||wybor>10)
        {
            cout<<"wybierz poprawny poziom"<<endl;
        }
        else
        {
        if(poziom[wybor-1]==true)
        {
            int a=wybor;
            walka(a-1);
            if(wybor==poziom_char)
            {
            poziom[wybor]=true;
            poziom_char++;
            }  
            licznik=1;
        }
        else
        {
            cout<<"ten poziom jest niedostepny"<<endl;
        }
        }
    }while(licznik!=1);
    menu2();
}
void menu2()
{
    int wybor, licznik=0;
    cout<<"wybierz co chcesz zrobic"<<endl;
    do
    {
        cout<<"1: zapisz gre, 2: walka, 3: pokaz inforamcje o postaci, 4: idz do menu"<<endl;
        cin>>wybor;
        switch(wybor)
        {
            case 1:
                zapisz();
            break;
            case 2:
                wybor_walki();
            break;
            case 3:
            cout<<nazwa<<endl;
            cout<<"Obrazenia: "<<obrazenia_min<<"-"<<obrazenia_max<<endl;
            cout<<"Szansa na trafienie krytyczne: "<<szansa_na_kryt<<endl;
            cout<<"ilosc punktow zycia: "<<zdrowie<<endl;
            cout<<"ilosc punktow many: "<<mana<<endl;
            cout<<"Szybkosc: "<<szybkosc<<endl;
            break;
            case 4:
                menu1();
                licznik=1;
            break;
            default:
                cout<<"wpisz poprawna odpowiedz"<<endl;
            break;
        }
    }while(licznik!=1);
}
void menu1()
{
    int wybor, licznik=0;
    cout<<"wybierz co chcesz zrobic"<<endl;
    do
    {
    cout<<"1: rozpocznij nowa gre, 2: wczytaj gre, 3: zakoncz"<<endl;
    cin>>wybor;
    switch (wybor)
    {
        case 1:
            cout<<"rozpoczynam nowa gre"<<endl;
            licznik=1;
            wybor_klasy();
        break;
        case 2:
            cout<<"wczytywanie"<<endl;
            licznik=1;
            wczytaj();
        break;
        case 3:
            licznik=1;
            exit(0);
        break;
        default:
            cout<<"wpisz poprawna odpowiedz"<<endl;
        break;
    }
    }while(licznik!=1);
}
void wczytaj()
{
    int wybor,licznik=0,nr_linii=1;
    string linia;
    fstream plik;
    cout<<"Ktora gre chcesz wczytac ?"<<endl;
    do
    {
        cout<<"1: zapis1, 2: zapis2, 3: zapis3"<<endl;
        cin>>wybor;
        switch(wybor)
        {
            case 1:
                plik.open("zapis1",ios::in);
                while(getline(plik,linia))
                {
                    switch(nr_linii)
                    {
                        case 1:
                            nazwa=linia;
                        break;
                        case 2:
                            id_klasa=atoi(linia.c_str());
                        break;
                        case 3:
                            obrazenia_min=atoi(linia.c_str());
                        break;
                        case 4:
                            obrazenia_max=atoi(linia.c_str());
                        break;
                        case 5:
                            szansa_na_kryt=atoi(linia.c_str());
                        break;
                        case 6:
                            zdrowie=atoi(linia.c_str());
                        break;
                        case 7:
                            mana=atoi(linia.c_str());
                        break;
                        case 8:
                            szybkosc=atoi(linia.c_str());
                        break;
                        case 9:
                            poziom_char=atoi(linia.c_str());
                        break;
                    }
                    nr_linii++;
                }
                plik.close();
                licznik=1;
            break;
            case 2:
                plik.open("zapis2",ios::in);
                while(getline(plik,linia))
                {
                    switch(nr_linii)
                    {
                        case 1:
                            nazwa=linia;
                        break;
                        case 2:
                            id_klasa=atoi(linia.c_str());
                        break;
                        case 3:
                            obrazenia_min=atoi(linia.c_str());
                        break;
                        case 4:
                            obrazenia_max=atoi(linia.c_str());
                        break;
                        case 5:
                            szansa_na_kryt=atoi(linia.c_str());
                        break;
                        case 6:
                            zdrowie=atoi(linia.c_str());
                        break;
                        case 7:
                            mana=atoi(linia.c_str());
                        break;
                        case 8:
                            szybkosc=atoi(linia.c_str());
                        break;
                    }
                    nr_linii++;
                }
                plik.close();
                licznik=1;
            break;
            case 3:
                plik.open("zapis3",ios::in);
                while(getline(plik,linia))
                {
                    switch(nr_linii)
                    {
                        case 1:
                            nazwa=linia;
                        break;
                        case 2:
                            id_klasa=atoi(linia.c_str());
                        break;
                        case 3:
                            obrazenia_min=atoi(linia.c_str());
                        break;
                        case 4:
                            obrazenia_max=atoi(linia.c_str());
                        break;
                        case 5:
                            szansa_na_kryt=atoi(linia.c_str());
                        break;
                        case 6:
                            zdrowie=atoi(linia.c_str());
                        break;
                        case 7:
                            mana=atoi(linia.c_str());
                        break;
                        case 8:
                            szybkosc=atoi(linia.c_str());
                        break;
                    }
                    nr_linii++;
                }
                plik.close();
                licznik=1;
            break;
            default:
                cout<<"wprowadz poprawna odpowiedz"<<endl;
            break;
        }
    }while(licznik!=1);
    menu2();
}
void zapisz()
{
    int wybor,licznik=0;
    fstream plik;
    cout<<"Gdzie chcesz zapisac gre ?"<<endl;
    do
    {
        cout<<"1: zapis1, 2: zapis2, 3: zapis3"<<endl;
        cin>>wybor;
        switch(wybor)
        {
            case 1:
                plik.open("zapis1",ios::out);
                plik<<nazwa<<endl;
                plik<<id_klasa<<endl;
                plik<<obrazenia_min<<endl;
                plik<<obrazenia_max<<endl;
                plik<<szansa_na_kryt<<endl;
                plik<<zdrowie<<endl;
                plik<<mana<<endl;
                plik<<szybkosc<<endl;
                plik<<poziom_char;
                plik.close();
                licznik=1;
            break;
            case 2:
                plik.open("zapis2",ios::out);
                plik<<nazwa<<endl;
                plik<<id_klasa<<endl;
                plik<<obrazenia_min<<endl;
                plik<<obrazenia_max<<endl;
                plik<<szansa_na_kryt<<endl;
                plik<<zdrowie<<endl;
                plik<<mana<<endl;
                plik<<szybkosc<<endl;
                plik<<poziom_char;
                plik.close();
                licznik=1;
            break;
            case 3:
                plik.open("zapis3",ios::out);
                plik<<nazwa<<endl;
                plik<<id_klasa<<endl;
                plik<<obrazenia_min<<endl;
                plik<<obrazenia_max<<endl;
                plik<<szansa_na_kryt<<endl;
                plik<<zdrowie<<endl;
                plik<<mana<<endl;
                plik<<szybkosc<<endl;
                plik<<poziom_char;
                plik.close();
                licznik=1;
            break;
            default:
                cout<<"wprowadz poprawna odpowiedz"<<endl;
            break;
        }
    }while(licznik!=1);
    menu2();
}
void wybor_klasy()
{
    int licznik=0;
    do
    {
        cout<<"podaj jaka klase chcesz wybrac"<<endl;
        cout<<"1.Lowca, 2.Wojownik, 3.Mag"<<endl;
        cin>>id_klasa;
        switch(id_klasa)
        {
            case 1:
            nazwa="Lowca";
            obrazenia_min=30;
            obrazenia_max=35;
            szansa_na_kryt=30;
            zdrowie=75;
            mana=10;
            szybkosc=10;
            cout<<"Twoja klasa to: "<<nazwa<<endl;
            licznik=1;
            break;
            case 2:
            nazwa="Wojownik";
            obrazenia_min=20;
            obrazenia_max=40;
            szansa_na_kryt=15;
            zdrowie=100;
            mana=10;
            szybkosc=5;
            cout<<"Twoja klasa to: "<<nazwa<<endl;
            licznik=1;
            break;
            case 3:
            nazwa="Mag";
            obrazenia_min=10;
            obrazenia_max=20;
            szansa_na_kryt=5;
            zdrowie=70;
            mana=40;
            szybkosc=7;
            cout<<"Twoja klasa to: "<<nazwa<<endl;
            licznik=1;
            break;
            default:
            cout<<"wpisz poprawna wartosc"<<endl;
            break;
        }
    }while(licznik!=1);
    menu2();
    }