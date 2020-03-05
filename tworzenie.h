#ifndef TWORZENIE_H_INCLUDED
#define TWORZENIE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>



struct drzewo
    {
        int dane;
        drzewo *lewy;
        drzewo *prawy;
        char strona;
    };

void pisz(std::string co);

void DodajWezel(drzewo *&wezel, int wartosc);

void zczytaj_z_plik(drzewo *korzen,int a);

void wyswietl(drzewo *&wezel);
void zapisz(drzewo *&wezel,std::ofstream *plik2);

void usun_element(drzewo *korzen, std::ofstream *plikdel, int usuwana);

bool wyszukaj(drzewo *&wezel, int szukana);

void usun(drzewo *&korzen);
#endif
