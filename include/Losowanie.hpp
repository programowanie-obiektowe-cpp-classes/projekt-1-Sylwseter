#ifndef LOSOWANIE_HPP
#define LOSOWANIE_HPP

#include <iostream>
#include <random>
#include <string>
#include <thread>

inline int losujZeroLubJeden()
{
    // Generator liczb losowych
    static std::mt19937 generator(std::random_device{}());

    // Dystrybucja losuj¹ca liczby w zakresie [0, 1]
    std::uniform_int_distribution< int > dystrybucja(0, 1);

    return dystrybucja(generator); // Losowanie i zwrócenie wyniku
}

inline int losujLiczbeFollowers()
{
    // Generator liczb losowych
    static std::mt19937 generator(std::random_device{}());

    // Dystrybucja losuj¹ca liczby w zakresie [0, 1]
    std::uniform_int_distribution< int > dystrybucja(1, 10000);

    return dystrybucja(generator); // Losowanie i zwrócenie wyniku
}

inline double losujNumerButa()
{
    // Generator liczb losowych
    static std::mt19937 generator(std::random_device{}());
    // Dystrybucja losuj¹ca liczby ca³kowite od 360 do 500
    std::uniform_int_distribution< int > dystrybucja(360, 500);

    double wynik;
    do
    {
        int liczba = dystrybucja(generator); // Losujemy liczbê ca³kowit¹
        if (liczba % 10 == 0 || liczba % 10 == 5)
        {                          // Sprawdzamy koñcówkê dziesiêtn¹
            wynik = liczba / 10.0; // Dzielimy przez 10, aby uzyskaæ liczbê dziesiêtn¹
            break;
        }
    } while (true);

    return wynik;
}

#endif