#ifndef MARKETER_HPP
#define MARKETER_HPP

#include "RandomNameGenerator.hpp"
#include <iostream>
#include <string>
#include "Pracownik.hpp"
//#include "Losowanie.hpp"

class Marketer : public Pracownik
{
private:
    int         followers;
    std::string imie;

public:
    Marketer()
    {
        imie      = getRandomName();
        followers = losujLiczbeFollowers();
    }
    void wyswietlInfo() const
    {
        std::cout << "Imie marketera: " << imie << std::endl;
        std::cout << "Liczba obserwujacych marketera: " << followers << std::endl;
    }
};

#endif