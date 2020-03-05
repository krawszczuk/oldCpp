#include "meni.h"

void menu(drzewo *wezel,drzewo *korzen)
{
int opcja=0;
int szukaj;

while(opcja!=9)
{
    pisz("Wybierz opcje:");
    pisz("1-tworzenie drzewa-wczytanie z klawiatury");
    pisz("2-tworzenie drzewa-wczytanie z pliku");
    pisz("3-wyswietl bierzaca drzewo");
    pisz("4-zapisz do pliku bierzaca drzewo");
    pisz("5-dodaj element do drzewa");
    pisz("6-usun element z drzewa");
    pisz("7-znajdz element");
    pisz("8-usun drzewo z pamieci");
    pisz("9-wyjscie");
    pisz("");

    std::cin>>opcja;
    pisz("");

    switch(opcja)
    {
        case 1:
            {
                int n,liczba;
                pisz("Podaj ilu elementowe drzewo chcesz stworzyc");
                std::cin>>n;
                for(int i=0; i<n; i++)
                    {
                        pisz("Wprowadz liczbe");
                        do
                            {
                                std::cin>>liczba;
                                if(!(int(liczba)==liczba))
                                    pisz("Blad. Podaj liczbe.");
                            }while(!(int(liczba)==liczba));             //sprawdzanie czy wczytano liczbe

                        DodajWezel(korzen, liczba);
                    }
                break;
            }

        case 2:
            {
                zczytaj_z_plik(korzen,0);
                break;
            }

        case 3:
            {
                pisz("Aktualne posortowane drzewo: ");
                wyswietl(korzen);
                break;
            }

        case 4:
            {
                std::string nazwa_zapisu;

                pisz("Podaj nazwe pliku do ktorego chcesz zapisac");
                std::cin>>nazwa_zapisu;
                std::ofstream *plik2 = new std::ofstream;
                //plik2.open(nazwa_zapisu.c_str());

                zapisz(korzen, plik2);
                break;
            }

        case 5:
            {
                int nowa;
                pisz("Podaj liczbe jaka chcesz dodac");
                std::cin>>nowa;
                DodajWezel(korzen, nowa);
                break;
            }

        case 6:
            {
                int usuwana;
                std::string pomoc;
                pisz("podaj nazwe pliku pomocniczego");
                std::cin>>pomoc;
                std::ofstream *plikdel= new std::ofstream;
                //plikdel.open(pomoc.c_str());
                pisz("Podaj liczbe jaka chcesz usunac");
                std::cin>>usuwana;
                usun_element(korzen, plikdel, usuwana);
                break;
            }

        case 7:
            {
                pisz("Podaj szukana wartosc");
                std::cin>>szukaj;
                pisz("");
                if(wyszukaj(korzen,szukaj))
                    pisz("Podana liczba znajduje sie w drzewie");
                else
                    pisz("Nie znaleziono liczby");
                break;

            }

        case 8:
            {
                usun(korzen);
                break;
            }

        case 9:break;
        default:pisz("Blad.Podaj od 1 do 9");
    }

pisz("");
pisz("");
system("pause");
system("cls");
};
}
