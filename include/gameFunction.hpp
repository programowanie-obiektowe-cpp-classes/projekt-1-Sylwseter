// game_functions.hpp

#ifndef GAME_FUNCTIONS_HPP
#define GAME_FUNCTIONS_HPP

#include "Pracownik.hpp" // Potrzebne do obs³ugi pracowników
#include <string>
#include <vector>

void wstep();
void zatrudnij_inz(std::vector< Pracownik* >& pracownicy, int a);
void zatrudnij_mag(std::vector< Pracownik* >& pracownicy, int a);
void zatrudnij_mkt(std::vector< Pracownik* >& pracownicy, int a);
void zatrudnij_rob(std::vector< Pracownik* >& pracownicy, int a);
void wyswietl_pracownikow(const std::vector< Pracownik* >& pracownicy);
int  dochod(int  liczba_inz,
            int  liczba_mag,
            int  liczba_mkt,
            int  liczba_rob,
            int& stan_konta,
            int  i,
            int  przychody[],
            int  stany_konta[],
            int  dochody[],
            int  rata,
            int  kwota_kredytu);
double gielda(int i, int przychody[]);
double wywolanie_gielda(int i, int przychody[]);
double wez_kredyt(int przychody_po5, int& czas_splaty, int& kwota_kredytu, double& rata);
#endif // GAME_FUNCTIONS_HPP
