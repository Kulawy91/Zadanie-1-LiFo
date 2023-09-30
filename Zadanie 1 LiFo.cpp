#include <iostream>

#include <iostream>
#include <locale.h> //włączenie lokalnych znaków diakrytycznych
#include <list>


int main() {
    setlocale(LC_CTYPE, "Polish");//ustawienie lokalizacji znaków diakrytycznych na polskie

    std::list<int> lista; //użycie listy zamiast array

    // dodawanie liczb całkowitych od 1 do 100 do listy
    for (int i = 1; i <= 100; i++) {
        lista.push_back(i);
    }

    lista.push_back(5);

    // wyświetlanie stosu 
    std::cout << "Stos nie odwrócony: ";
    for (const auto& item : lista) { //zmienna będąca referencją do wartości
        std::cout << item << " ";
    }

    std::cout << std::endl << std::endl;

    // Odwracanie stosu LiFo
    std::cout << "Stos odwrócony: ";
    for (auto it = lista.rbegin(); it != lista.rend(); ++it) { //zwraca iterator odwrotny zamiast od 1 do 100 od 100 do 1
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    return 0;
}


