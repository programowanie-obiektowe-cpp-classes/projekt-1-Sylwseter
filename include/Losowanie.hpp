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

    // Dystrybucja losuj�ca liczby w zakresie [0, 1]
    std::uniform_int_distribution< int > dystrybucja(0, 1);

    return dystrybucja(generator); // Losowanie i zwr�cenie wyniku
}

inline int losujLiczbeFollowers()
{
    // Generator liczb losowych
    static std::mt19937 generator(std::random_device{}());

    // Dystrybucja losuj�ca liczby w zakresie [0, 1]
    std::uniform_int_distribution< int > dystrybucja(1, 10000);

    return dystrybucja(generator); // Losowanie i zwr�cenie wyniku
}

inline double losujNumerButa()
{
    // Generator liczb losowych
    static std::mt19937 generator(std::random_device{}());
    // Dystrybucja losuj�ca liczby ca�kowite od 360 do 500
    std::uniform_int_distribution< int > dystrybucja(360, 500);

    double wynik;
    do
    {
        int liczba = dystrybucja(generator); // Losujemy liczb� ca�kowit�
        if (liczba % 10 == 0 || liczba % 10 == 5)
        {                          // Sprawdzamy ko�c�wk� dziesi�tn�
            wynik = liczba / 10.0; // Dzielimy przez 10, aby uzyska� liczb� dziesi�tn�
            break;
        }
    } while (true);

    return wynik;
}

#endif