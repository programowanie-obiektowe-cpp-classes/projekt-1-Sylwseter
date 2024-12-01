#ifndef ROBOTNIK_HPP
#define ROBOTNIK_HPP

#include "RandomNameGenerator.hpp"
#include <iostream>
#include <string>
#include "Pracownik.hpp"
//#include "Losowanie.hpp"

class Robotnik : public Pracownik
{
private:
    double      nr_buta;
    std::string imie;

public:
    Robotnik()
    {
        imie    = getRandomName();
        nr_buta = losujNumerButa();
    }
    void wyswietlInfo() const
    {
        std::cout << "Imie magazyniera: " << imie << std::endl;
        std::cout << "Numer buta robotnika: " << nr_buta << std::endl;
    }
};

#endif