#include "tworzenie.h"




void pisz(std::string co)
{
    std::cout<<co;
    std::cout<<std::endl;
}


void DodajWezel(drzewo *&wezel, int wartosc)
{
    if (wezel==NULL)
        {
            wezel=new drzewo;
            wezel->dane=wartosc;
            wezel->lewy=NULL;
            wezel->prawy=NULL;
        }

    else if (wartosc<wezel->dane)
        DodajWezel(wezel->lewy, wartosc);
    else if (wartosc>wezel->dane)
        DodajWezel(wezel->prawy, wartosc);
}

void zczytaj_z_plik(drzewo *korzen,int a)
{
    std::string nazwa_pliku, znak;
                char przerwa;
                std::ifstream plik;

                pisz("Podaj nazwe pliku z ktorego chcesz wczytac");
                std::cin>>nazwa_pliku;

                nazwa_pliku=nazwa_pliku+".txt";
                plik.open(nazwa_pliku.c_str());

                if(a)
                    {

                    }

                else
                    {
                        while(!plik.eof())
                            {
                                getline(plik,znak);
                                bool spr=1;
                                for(int i=0; i<znak.length(); i++)
                                {
                                    if(isdigit(znak[i]))
                                        spr=0;
                                };
                                if(spr)
                                {
                                    pisz("Blad danych, znak nie jest liczba. Kontynuowac? (T/N)");

                                    do
                                        {
                                            std::cin>>przerwa;
                                            if(przerwa == 'T')
                                                {
                                                    getline(plik,znak);
                                                    DodajWezel(korzen, atoi(znak.c_str()));
                                                }
                                            else if(przerwa == 'N')
                                                goto aaa;                    //jak wyjsc 3 petle?
                                            else
                                                pisz("T lub N");

                                        }while(!(przerwa == 'T' || przerwa == 'N'));
                                }

                                else
                                {
                                    std::cout<<"Wczytano liczbe: "<<znak<<std::endl;
                                    DodajWezel(korzen, atoi(znak.c_str()));
                                }
                            }
                    }
                    aaa:
                plik.close();
}

void wyswietl(drzewo *&wezel)
    {
        if (wezel!=NULL)
            {
                wyswietl(wezel->lewy);
                std::cout<<wezel->dane<<" ";
                wyswietl(wezel->prawy);
            }
    }


void zapisz(drzewo *&wezel,std::ofstream *plik2)
    {
        if (wezel!=NULL)
            {
                zapisz(wezel->lewy,plik2);
                *plik2<<wezel->dane<<std::endl;
                zapisz(wezel->prawy,plik2);
            }
    }


void usun_element(drzewo *korzen, std::ofstream *plikdel, int usuwana)
    {
        zapisz(korzen, plikdel);
        zczytaj_z_plik(korzen, 1);
    }


bool wyszukaj(drzewo *&wezel, int szukana)
{
    if (wezel!=NULL)
        {
            wyszukaj(wezel->lewy,szukana);
            if(wezel->dane==szukana)
                return true;
            wyszukaj(wezel->prawy,szukana);
        }
}

void usun(drzewo *&korzen)
{
    delete korzen;
    korzen=NULL;
}
