#include <iostream>
#include "kontakty.h"

using namespace std;

int main()
{
    Kontakty k1;
    cout << "###### Kontakty Telefoniczne ######"<<endl;
    cout << "Wybierz z menu co chcesz zrobic z lista kontaktow:"<<endl;
    while(true){
    k1.usun_puste_linie();
    cout << endl << "1 - Wyswietl Liste Kontaktow" << endl;
    cout << "2 - Dodaj Nowy Kontakt" << endl;
    cout << "3 - Edytuj Wybrany Kontakt" << endl;
    cout << "4 - Usun Wybrany Kontakt" << endl;
    cout << "5 - Sortuj Kontakty" << endl;
    cout << "0 - Wyjscie Z Programu" << endl;
    int wybor;
    cin >> wybor;
    switch(wybor){
case 1:
    k1.wyswietl();
    break;
case 2:
    k1.dodaj();
    break;
case 3:
    k1.edytuj();
    break;
case 4:
    k1.usun();
    break;
case 5:
    k1.sortuj();
    break;
case 0:
    return 1;

    }
    }


    return 0;
}
