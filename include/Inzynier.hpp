#ifndef INZYNIER_HPP
#define INZYNIER_HPP

#include "RandomNameGenerator.hpp"
#include <iostream>
#include <string>
#include "Losowanie.hpp"
#include "Pracownik.hpp"

class Inzynier : public Pracownik
{

private:
    std::string nazwa_w = "MEiL";
    std::string imie;

public:
    Inzynier() { imie = getRandomName(); }

    void wyswietlInfo() const
    {
        std::cout << "Imie inzyniera: " << imie << std::endl;
        std::cout << "Wydzial inzyniera: " << nazwa_w << std::endl;
    }
};

#endif