#ifndef PRACOWNIK_HPP
#define PRACOWNIK_HPP

#include <iostream>
#include <string>

class Pracownik
{
public:
    virtual void wyswietlInfo() const = 0;       // Czysta wirtualna funkcja do wyœwietlania pracownika
    virtual ~Pracownik()              = default; // Wirtualny destruktor
};

#endif // PRACOWNIK_HPP