#include <iostream>

using namespace std;

class Kontakty{
    public:
    string imie, nazwisko, email;
    string numer_tel;
    int nr_kontaktu;

    void usun_puste_linie();
    void wyswietl();
    void dodaj();
    void usun();
    void edytuj();
    void sortuj();
};
