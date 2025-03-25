/*
Nome, cognome e matricola: Cael Kyler Padilla | 307931
Esercitazione_1_IO Exercise2

Nota dello studente: sono consapevole del fatto che il codice è commentato passo per passo e potrebbe risultare troppo;
per scopi didattici, ed essendo i primi codici nel linguaggio cpp, preferisco spiegarmi ogni passaggio che faccio
anche per aiutarmi ad ottimizzare il codice in una forma più corto ed efficiente.
*/

#pragma once

#include <iostream>
#include <cmath>

template <typename T>
class complex_number {
    T real;
    T imaginary;

public:
    
    // Dato che devo avere un costruttore di default, imposto che parte reale e immaginaria siano di default nulli
    complex_number ()
        : real(0) , imaginary(0)
    {}

    // Inserisco un costruttore user-defined per l'inizializzazione di parte reale e immaginaria da parte dello user
    complex_number (T re, T im)
        : real(re) , imaginary(im)
    {}

    // Creo un metodo con che restituisce il coniugato di un complesso
    T con() const {
        return complex_number(re(), -im());
    }

    // Creo un metodo re che restituisce la parte reale del complesso
    T re() const{
        return real;
    }

    // Creo un metodo im che restituisce la parte immaginaria
    T im() const {
        return imaginary;
    }
}

// Per stampare un numero complesso, devo stare attento quando la parte immaginaria è negativa e non-nagativa:

template<typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& z) {
    os<< z.re();
    if (z.im()>=0) {
        os << "+" << z.im() zz "i";   // questo perchè la parte immaginaria sicuramente non ha il segno meno
    } 
    else {
        os << z.im() << "i";   // questo perchè la parte immaginaria ha già il segno meno davanti.
    }
    return os;
}

// Overload +=

