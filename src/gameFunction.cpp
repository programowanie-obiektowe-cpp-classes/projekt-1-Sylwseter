#include "gameFunction.hpp"
#include "Inzynier.hpp"
#include "Magazynier.hpp"
#include "Marketer.hpp"
#include "Robotnik.hpp"

#define CMag 120
#define CI 150
#define CMkt 100
#define CR 80
#define pensja_inz 6000
#define pensja_mag 1800
#define pensja_mkt 3500
#define pensja_rob 1500
#define N 5
#define M 3
#define X 10

extern double przychody_po5;

void wstep()
{
    std::cout << "Witaj w grze Co to ten Bitcoin?" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Gre rozpoczynasz majac 1 inzyniera, 1 magazyniera, 1 marketera, 1 robotnika oraz 1000$" <<
    std::endl; std::cout << "Gra konczy sie po osiagnieciu 1 000 000$. Inwestuj madrze, bo gdy stan Twojego konta wyniesie 0$, zbankrutujesz" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Instrukcja: " << std::endl;
    std::cout << "lp - wylistuj pracownikow (imiona i wynagrodzenia)" << std::endl;
    std::cout << "zinz - zatrudnij inz" << std::endl;
    std::cout << "zmag - zatrudnij mag" << std::endl;
    std::cout << "zmkt - zatrudnij mark" << std::endl;
    std::cout << "zrob - zatrudnij rob" << std::endl;
    std::cout << "kred - wez kredyt (w nastepnym kroku podaj kwote i czas splaty)" << std::endl;
    std::cout << "kt - zakoncz ture i wyswietl stan firmy na poczatku nastepnego miesiaca" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Zaczynamy? " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void zatrudnij_inz(std::vector< Pracownik* >& pracownicy, int a)
{
    std::cout << "Zatrudniasz inzyniera!" << std::endl;
    pracownicy.push_back(new Inzynier()); // Dodajemy nowego in¿yniera
    std::cout << "Obecnie liczba inzynierow wynosi: " << a << std::endl;
}

void zatrudnij_mag(std::vector< Pracownik* >& pracownicy, int a)
{
    std::cout << "Zatrudniasz magazyniera!" << std::endl;
    pracownicy.push_back(new Magazynier()); // Dodajemy nowego magazyniera
    std::cout << "Obecnie liczba magazynierow wynosi: " << a << std::endl;
}

void zatrudnij_mkt(std::vector< Pracownik* >& pracownicy, int a)
{
    std::cout << "Zatrudniasz marketera!" << std::endl;
    pracownicy.push_back(new Marketer()); // Dodajemy nowego marketera
    std::cout << "Obecnie liczba marketerow wynosi: " << a << std::endl;
}

void zatrudnij_rob(std::vector< Pracownik* >& pracownicy, int a)
{
    std::cout << "Zatrudniasz robotnika!" << std::endl;
    pracownicy.push_back(new Robotnik()); // Dodajemy nowego robotnika
    std::cout << "Obecnie liczba robotnikow wynosi: " << a << std::endl;
}

void wyswietl_pracownikow(const std::vector< Pracownik* >& pracownicy)
{
    std::cout << "Twoi pracownicy:" << std::endl;
    for (const auto& pracownik : pracownicy)
    {
        pracownik->wyswietlInfo();
    }
}

int dochod(int  liczba_inz,
           int  liczba_mag,
           int  liczba_mkt,
           int  liczba_rob,
           int& stan_konta,
           int  i,
           int  przychody[],
           int  stany_konta[],
           int  dochody[],
           int  rata,
           int  kwota_kredytu)
{
    int poj_mag = liczba_mag * CMag;
    int cena_p  = liczba_inz * CI;
    int popyt   = liczba_mkt * CMkt;
    int wyp_teo = liczba_rob * CR;
    int wyp_fakt;
    int l_sprzed;
    int przychod;

    if (wyp_teo > poj_mag)
    {
        wyp_fakt = poj_mag;
    }
    else
    {
        wyp_fakt = wyp_teo;
    }

    if (wyp_fakt > popyt)
    {
        l_sprzed = popyt;
    }
    else
    {
        l_sprzed = wyp_fakt;
    }
    przychod     = l_sprzed * CI;
    przychody[i] = przychod;
    std::cout << "Przychod w tym miesiacu to:" << przychod << std::endl;
    int pensja = liczba_inz * pensja_inz + liczba_mag * pensja_mag + liczba_mkt * pensja_mkt + liczba_rob * pensja_rob;
    std::cout << "Suma pensji to: " << pensja << std::endl;
    if (kwota_kredytu == 0)
    {     
        int dochod = przychod - pensja;
        std::cout << "Dochod w tym miesiacu to:" << dochod << std::endl;
        dochody[i] = dochod;
        stan_konta = stan_konta + dochod;
        std::cout << "Stan konta po tym miesiacu to: " << stan_konta << std::endl;
        stany_konta[i] = stan_konta;
    }
    else {
        int dochod = przychod - pensja - rata;
        std::cout << "Rata w tym miesiacu: " << rata << std::endl;
        dochody[i] = dochod;
        std::cout << "Dochod po kredycie w tym miesiacu to:" << dochod << std::endl;
        stan_konta = stan_konta + dochod;
        std::cout << "Stan konta po tym miesiacu to: " << stan_konta << std::endl;
        stany_konta[i] = stan_konta;
    }
    
    return stan_konta;
}

double gielda(int i, int przychody[])
{
    int koncowy_przychod = 0;
    for (int x = i - N; x < i; x++)
    {
        koncowy_przychod = koncowy_przychod + przychody[x];
    }
    double wartosc_spolki = koncowy_przychod / N;
    return wartosc_spolki;
}

double wywolanie_gielda(int i, int przychody[])
{
    if (i == N + 1)
    {
        przychody_po5 = gielda(i, przychody);
        std::cout << "Brawo, wchodzisz na gielde! Wartosc twojej spolki (srednia z ostatnich 5 miesiency): "
                  << przychody_po5 << std::endl;
    }
    if (i > N + 1)
    {
        przychody_po5 = gielda(i, przychody);
        std::cout << "Wartosc twojej spolki (srednia z ostatnich 5 miesiency): " << przychody_po5 << std::endl;
    }
    return przychody_po5;
}

double wez_kredyt(int przychody_po5, int& czas_splaty, int& kwota_kredytu, double& rata)
{
    std::cout << "W Twoim przypadku maksymalna kwota kredytu to: " << przychody_po5 * M
              << " Wynika ona z wartosci twojej spolki. Pamietaj, ze oprocentowanie kredytu wynosi 20%" << std::endl;
    std::cout << "Podaj kwote kredytu: (tylko liczba calkowita)";
    std::cin >> kwota_kredytu;
    bool flaga_kwoty_kredytu = false;
    while (!flaga_kwoty_kredytu)
    {
        if (kwota_kredytu > przychody_po5 * M)
        {
            std::cout << "Nie mozesz wziac tak duzego  kredytu" << std::endl;
            std::cout << "Podaj kwote kredytu: (tylko liczba calkowita)";
            std::cin >> kwota_kredytu;
        }
        else if (kwota_kredytu <= 0)
        {
            std::cout << "Ty sobie zartujesz?" << std::endl;
            std::cout << "Podaj kwote kredytu: (tylko liczba calkowita)";
            std::cin >> kwota_kredytu;
        }
        else if (kwota_kredytu == static_cast< int >(kwota_kredytu))
        {
            flaga_kwoty_kredytu = true;
        }
    }
    std::cout << "Maksymalny czas splaty kredytu to:" << X << std::endl;
    std::cout << "Podaj czas na jaki chcesz wziac kredyt: ";
    std::cin >> czas_splaty;
    bool flaga_czasu_kredytu = false;
    while (!flaga_czasu_kredytu)
    {
        if (czas_splaty > X)
        {
            std::cout << "Nie mozesz wziac kredytu na tak dlugi czas" << std::endl;
            std::cout << "Podaj czas na jaki chcesz wziac kredyt: ";
            std::cin >> czas_splaty;
        }
        else if (czas_splaty <= 0)
        {
            std::cout << "Ty sobie zartujesz?" << std::endl;
            std::cout << "Podaj czas na jaki chcesz wziac kredyt: ";
            std::cin >> czas_splaty;
        }
        else if (czas_splaty == static_cast< int >(czas_splaty))
        {
            flaga_czasu_kredytu = true;
        }
    }
    rata = (kwota_kredytu / czas_splaty) * 1.2;
    std::cout << "Podsumowujac, wziales kredyt na kwote: " << kwota_kredytu << ", na czas: " << czas_splaty
              << " Rata kredytu: " << rata << std::endl;
    return rata;
}