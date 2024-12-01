#ifndef MAGAZYNIER_HPP
#define MAGAZYNIER_HPP

#include "Pracownik.hpp"
#include "RandomNameGenerator.hpp"
#include <iostream>
#include <string>
//#include "Losowanie.hpp"

class Magazynier : public Pracownik
{
private:

    bool        wozek_w;
    std::string imie;

public:
    Magazynier()
    {
        imie    = getRandomName();
        wozek_w = losujZeroLubJeden();
    }
    void wyswietlInfo() const
    {
        std::string a;

        if (wozek_w == 1)
            a = "tak";
        else
            a = "nie";

        std::cout << "Imie magazyniera: " << imie << std::endl;
        std::cout << "Czy magazynier ma uprawnienia wozka widlowego?: " << a << std::endl;
    }
};

#endif