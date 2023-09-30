// Zadanie 1 LiFo.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include <iostream>
#include <locale.h> //włączenie lokalnych znaków diakrytycznych

class Stack {
private:
    int* data;
    int size;
    int top;

public:
    //inicjalizacja pustego stosu
    Stack(int stack_size) {
        size = stack_size;
        data = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] data;
    }
    // operator logiczny sprawdzający czy stos jest pusty
    bool is_empty() {
        return top == -1;
    }
    //operator logiczny sprawdzający czy stos jest pełny
    bool is_full() {
        return top == size - 1;
    }
    // dodanie elementu do stosu
    void push(int item) {
        if (!is_full()) {
            data[++top] = item;
        }
    }
    // zdjęcie wierzchołka stosu
    int pop() {
        if (!is_empty()) {
            return data[top--];
        }
        else {
            return -1; // Stos jest pusty
        }
    }
    //zwraca pierwszy element stosu nie modyfikując samego stosu
    int peek() {
        if (!is_empty()) {
            return data[top];
        }
        else {
            return -1; // Stos jest pusty
        }
    }
    // sprawdzenie wielkości stosu
    int get_size() {
        return top + 1;
    }
};

int main() {
    setlocale(LC_CTYPE, "Polish");//ustawienie lokalizacji znaków diakrytycznych na polskie

    Stack stack(100);//deklaracja wielkości stosu

    // dodawanie liczb całkowitych od 1 do 100 na stos
    for (int i = 1; i <= 100; i++) {
        stack.push(i);
    }
    // wyświetlanie stosu pierwotnego
    std::cout << "Stos nie odwrócony: ";
    //odwracanie stosu
    Stack reversed_stack(100);
    while (!stack.is_empty()) {
        int item = stack.pop();
        std::cout << item << " ";
        reversed_stack.push(item);
    }
   
        std::cout << std::endl;
        std::cout << std::endl;
        // wyświetlenie stosu odwróconego
    std::cout << "Stos odwrócony: ";
    while (!reversed_stack.is_empty()) {
        std::cout << reversed_stack.pop() << " ";
    }

    std::cout << std::endl;

    return 0;
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
