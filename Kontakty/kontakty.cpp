#include <iostream>
#include "kontakty.h"
#include <fstream>
#include <cstdlib>
#include <cstdio>


using namespace std;

void Kontakty::usun_puste_linie(){
    fstream plik;
    plik.open("plik.txt", ios::in | ios::out);
    string linia;
    string *wszystko = new string[200];
    int pom=0;
    while(getline(plik, linia))
    {
        if(linia!=""){
        wszystko[pom]=linia;
        pom++;
        }
    }
    plik.close();
    if(remove("plik.txt")==0)
        {
            ofstream plik("plik.txt");
        }
        plik.open("plik.txt", ios::in | ios::out);
    for (int i = 0; i<pom+4; i++)
    {
        if(wszystko[i]!="")
        {
        plik << wszystko[i] << endl;
        }
    }
    plik.close();

}
void Kontakty::wyswietl(){
    fstream plik;
    plik.open("plik.txt", ios::in);
    if(plik.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku!";
        exit(0);
    }
    string linia;
    while(getline(plik, linia))
        {
            cout << linia << endl;
        }
    plik.close();
}
void Kontakty::dodaj(){
    fstream plik;
    plik.open("plik.txt", ios::app);
    cout << "Podaj imie:" << endl;
    cin >> imie;
    plik << endl << imie;
    cout << "Podaj Nazwisko:" << endl;
    cin >> nazwisko;
    plik << endl << nazwisko;
    cout << "Podaj adres email:" << endl;
    cin >> email;
    plik << endl << email;
    cout << "Podaj numer:" << endl;
    cin >> numer_tel;
    plik << endl << numer_tel;
    plik.close();
}
void Kontakty::usun(){
    int a;
    cout << "Podaj numer kontaktu, ktory chcesz usunac: " ;
    cin >> a;

    fstream plik,pomoc;
    if(remove("pomoc.txt")==0)
        {
            ofstream plik("pomoc.txt");
        }


    plik.open("plik.txt", ios::in | ios::out);
    pomoc.open("pomoc.txt", ios::in | ios::out);

    int nr_linii= (a-1)*4;
    string linia, linia_pom;
    int aktualny_nr=0;

    while(getline(plik, linia))
        {
            if((aktualny_nr != nr_linii) & (aktualny_nr != nr_linii+1) & (aktualny_nr != nr_linii+2) & (aktualny_nr != nr_linii+3))
            {
                pomoc << linia << endl;
            }
            aktualny_nr++;
        }

     //   plik.seekg(0);
     //   pomoc.seekg(0);
        plik.close();
        pomoc.close();
        if(remove("plik.txt")==0)
        {
            ofstream plik("plik.txt");
        }
        plik.open("plik.txt", ios::in | ios::out);
        pomoc.open("pomoc.txt", ios::in | ios::out);

        while(getline(pomoc, linia_pom))
        {
                plik << linia_pom << endl;
        }
    plik.close();
    pomoc.close();
}
void Kontakty::edytuj(){
    int a;
    cout << "Podaj numer kontaktu, który chcesz edytowac: " ;
    cin >> a;

    fstream plik,pomoc;
    if(remove("pomoc.txt")==0)
        {
            ofstream plik("pomoc.txt");
        }

    plik.open("plik.txt", ios::in | ios::out);
    pomoc.open("pomoc.txt", ios::in | ios::out);

    int nr_linii= (a-1)*4;
    string linia, linia_pom;
    int aktualny_nr=0, aktualny_nr2=0;
    string dane;
    while(getline(plik, linia))
        {
            if((aktualny_nr != nr_linii) & (aktualny_nr != nr_linii+1) & (aktualny_nr != nr_linii+2) & (aktualny_nr != nr_linii+3))
            {
                pomoc << linia << endl;
            }
            else{
                cout << "Podaj nowe dane:" << endl;
                cin >> dane;
                pomoc << dane << endl;
            }
            aktualny_nr++;
        }

     //   plik.seekg(0);
     //   pomoc.seekg(0);
        plik.close();
        pomoc.close();
        if(remove("plik.txt")==0)
        {
            ofstream plik("plik.txt");
        }
        plik.open("plik.txt", ios::in | ios::out);
        pomoc.open("pomoc.txt", ios::in | ios::out);

        while(getline(pomoc, linia_pom))
        {
                if (aktualny_nr != aktualny_nr2)
                {
                    plik << linia_pom << endl;
                }
                else
                {
                    plik << linia_pom << endl;
                }
                aktualny_nr2++;
        }
    plik.close();
    pomoc.close();
}
void Kontakty::sortuj(){
    cout << endl<< "Podaj, po ktorym polu chcesz sortowac" << endl;
    cout << "1 - IMIE, 2 - NAZWISKO, 3 - EMAIL, 4 - NUMER TELEFONU" << endl;
    int wybor;
    cin >> wybor;

    fstream plik;
    plik.open("plik.txt", ios::in | ios::out);
    string linia, pierwsze;
    string *wszystko = new string[200];
    int pom=0;
    while(getline(plik, linia))
    {
        wszystko[pom]=linia;
        pom++;
    }
    plik.close();

    switch (wybor){
case 1:
     for (int i=0; i<pom-1; i=i+4){
        for (int j=0; j<pom-1; j=j+4){
            if (wszystko[j]>wszystko[j+4])
            {
                swap(wszystko[j], wszystko[j+4]);
                swap(wszystko[j+1], wszystko[j+5]);
                swap(wszystko[j+2], wszystko[j+6]);
                swap(wszystko[j+3], wszystko[j+7]);
            }
        }
    }
    break;
case 2:
     for (int i=1; i<pom-1; i=i+4){
        for (int j=1; j<pom-1; j=j+4){
            if (wszystko[j]>wszystko[j+4])
            {
                swap(wszystko[j], wszystko[j+4]);
                swap(wszystko[j-1], wszystko[j+3]);
                swap(wszystko[j+1], wszystko[j+5]);
                swap(wszystko[j+2], wszystko[j+6]);
            }
        }
    }
    break;
case 3:
    for (int i=2; i<pom-1; i=i+4){
        for (int j=2; j<pom-1; j=j+4){
            if (wszystko[j]>wszystko[j+4])
            {
                swap(wszystko[j], wszystko[j+4]);
                swap(wszystko[j-1], wszystko[j+3]);
                swap(wszystko[j-2], wszystko[j+2]);
                swap(wszystko[j+1], wszystko[j+5]);
            }
        }
    }
    break;
case 4:
    for (int i=3; i<pom-1; i=i+4){
        for (int j=3; j<pom-1; j=j+4){
            if (wszystko[j]>wszystko[j+4])
            {
                swap(wszystko[j], wszystko[j+4]);
                swap(wszystko[j-1], wszystko[j+3]);
                swap(wszystko[j-2], wszystko[j+2]);
                swap(wszystko[j-3], wszystko[j+1]);
            }
        }
    }
    break;
    }
     if(remove("plik.txt")==0)
        {
            ofstream plik("plik.txt");
        }
        plik.open("plik.txt", ios::in | ios::out);
    for (int i = 0; i<pom+4; i++)
    {
        if(wszystko[i]!="")
        {
        plik << wszystko[i] << endl;
        }
    }
    plik.close();
}

