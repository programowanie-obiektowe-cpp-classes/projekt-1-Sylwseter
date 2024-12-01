#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include "Inzynier.hpp"
#include "Magazynier.hpp"
#include "Marketer.hpp"
#include "Robotnik.hpp"
#include "Pracownik.hpp"
#include "gameFunction.hpp"

double przychody_po5 = 0;
double rata            = 0;
int    czas_splaty   = 0;
int    kwota_kredytu   = 0;

int main()
{
    int stan_konta = 10000;
    int tur_po_kredycie = 0;
    std::vector< Pracownik* > pracownicy; // Wektor do przechowywania pracowników
    wstep();
    std::string input;
    std::string   tf;
    constexpr int liczba_miesiecy              = 60;
    int         przychody[liczba_miesiecy]   = {0};
    int         stany_konta[liczba_miesiecy] = {0};
    int         dochody[liczba_miesiecy]     = {0};

    pracownicy.push_back(new Inzynier());
    pracownicy.push_back(new Magazynier());
    pracownicy.push_back(new Marketer());
    pracownicy.push_back(new Robotnik());
    int liczba_inz = 1;
    int liczba_mag = 1;
    int liczba_mkt = 1;
    int liczba_rob = 1;

    std::cout << "Oto Twoi poczatkowi pracownicy: " << std::endl;
    for (const auto& pracownik : pracownicy)
    {
        pracownik->wyswietlInfo(); // Wyœwietlamy ka¿dego pracownika
    }

    for (int i = 1; i <= liczba_miesiecy; i++)
    {
        wywolanie_gielda(i, przychody);
        std::cout << std::endl;
        std::cout << "Tura numer: " << i << std::endl;
        std::cout << "Twoj stan konta: " << stan_konta<< std::endl;

        bool zakoncz_ture = false; // Flaga do zakoñczenia tury

        while (!zakoncz_ture)
        {
            std::cout << "Wpisz komende: ";
            std::cin >> input;

            if (input == "zinz")
            {
                liczba_inz = liczba_inz + 1;
                zatrudnij_inz(pracownicy, liczba_inz);
                std::cout << std::endl;
            }
            else if (input == "zmag")
            {
                liczba_mag = liczba_mag + 1;
                zatrudnij_mag(pracownicy, liczba_mag);
                std::cout << std::endl;
            }
            else if (input == "zmkt")
            {
                liczba_mkt = liczba_mkt + 1;
                zatrudnij_mkt(pracownicy, liczba_mkt);
                std::cout << std::endl;
            }
            else if (input == "zrob")
            {
                liczba_rob = liczba_rob + 1;
                zatrudnij_rob(pracownicy, liczba_rob);
                std::cout << std::endl;
            }
            else if (input == "ls")
            {
                wyswietl_pracownikow(pracownicy);
                std::cout << std::endl;
            }
            else if (input == "kt")
            {
                stan_konta = dochod(liczba_inz, liczba_mag, liczba_mkt, liczba_rob, stan_konta, i, przychody, stany_konta, dochody, rata, kwota_kredytu);
                
                if (i > 5) {
                    if (i == 6) {
                        std::cout << "Odblokowales mozliwosc wziecia kredytu. Pamietaj, maksymalna kwota kredytu oraz "
                                     "czas splaty wynika z wartosci Twojej spolki."
                                  << std::endl;
                    }
                    bool flaga_kredyt = false;
                    std::cout << "Tur po kredycie" << tur_po_kredycie << std::endl;
                    if (/*!czy_kredyt && */tur_po_kredycie == 0)
                    {
                        std::cout << "Czy chcesz wziac kredyt? (t/f)";
                        std::cin >> tf;
                        while (!flaga_kredyt)
                        {
                            if (tf == "t")
                            {
                                wez_kredyt(przychody_po5, czas_splaty, kwota_kredytu, rata);
                                stan_konta += kwota_kredytu;
                                tur_po_kredycie = czas_splaty;
                                flaga_kredyt = true;
                            }
                            else if (tf == "f")
                            {
                                flaga_kredyt = true;
                            }
                            else
                            {
                                std::cout << "Nie rozumiem, wpisz jeszcze raz:";
                                std::cin >> tf;
                            }
                        } 
                    }
                    else if (tur_po_kredycie > 0)
                    {
                        std::cout << "Nie mozesz wziac kredytu przez kolejnych " << tur_po_kredycie << " tur."
                                  << std::endl;
                    }       
                }                   
                if (stan_konta <= 0)
                {
                    std::cout << "Koniec gry! Naucz sie co to Bitcoin." << std::endl;
                    return 0;
                }
                else if (stan_konta >= 1000000) {
                    std::cout << "Brawo! Jednak wiesz co to Bitcoin!" << std::endl;
                    return 0;
                }
                zakoncz_ture = true; // Wyjœcie z pêtli wewnêtrznej
            }
            else
            {
                std::cout << "Nieznana komenda, sprobuj ponownie." << std::endl;
            }    
        }
        if (tur_po_kredycie > 0)
        {
            tur_po_kredycie--;
        }
    }
    // Zwolnienie pamiêci
    for (auto& pracownik : pracownicy)
    {
        delete pracownik; // Usuwamy pracowników z pamiêci
    }
    return 0;
}