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
    complex_number<T> con() const {
        return complex_number<T>(real, -imaginary);
    }

    // Creo un metodo re che restituisce la parte reale del complesso
    T re() const{
        return real;
    }

    // Creo un metodo im che restituisce la parte immaginaria
    T im() const {
        return imaginary;
    }
    /* 
    Per stampare un numero complesso nel formato che voglio, sovracarico l'operatore <<. 
    Devo stare attento quando la parte immaginaria è negativa e non-nagativa 
    */


    complex_number<T>& operator<<(const complex_number<T>& z) {
        if (z.imaginary>=0) {
            z.real << "+" << z.imaginary << "i";   // questo perchè la parte immaginaria sicuramente non ha il segno meno
        } 
        else {
            z.real << z.imaginary << "i";   // questo perchè la parte immaginaria ha già il segno meno davanti.
        }
        return z.real;
    }

    // Overload +=

    complex_number<T>& operator+=(const complex_number<T>& w) {   // w è il secoondo numero complesso
        real += w.real;
        imaginary += w.imaginary;
        return *this;
    }

    // Overload +

    complex_number<T>& operator+(const complex_number<T>& w) const {
        T r = real + w.real;
        T i = imaginary + w.imaginary;   
        return complex_number<T>(r,i);
    }

    // Overload *=

    complex_number<T>& operator*=(const complex_number<T>& w) {   
        real = real* w.real - imaginary* w.imaginary;
        imaginary = real*w.imaginary + imaginary*w.real;
        return *this;
    }

    // Overload *

    complex_number<T>& operator*(const complex_number<T>& w) const{   
        T r = real* w.real - imaginary* w.imaginary;
        T i = real*w.imaginary + imaginary*w.real;
        return complex_number<T>(r, i);
    }
};




// Verifico il mio codice con un esempio

/*int main() {

    //Creo due numeri complessi e li visualizzo
    complex_number<double> z(3.0, -5.0);   
    complex_number<double> w(2.0, 6.0);

    // std::cout << "z : " << z << std::endl;   // sto utilizzando l'overload su <<
    // std::cout << "w : " << w << std::endl;

    // Visualizzo il coniugato di z e w
    complex_number<double> z_coniugato = z.con();
    // std::cout << "Coniugato di z : " << z_coniugato << std::endl;
    complex_number<double> w_coniugato = w.con();
    // std::cout << "Coniugato di w : " << w_coniugato << std::endl;

    // Visualizzo parte reale e immaginaria di z e w
    complex_number<double> re_z = z.re();
    complex_number<double> im_z = z.im();
    std::cout << "Re(z) : " << re_z << std::endl
    std::cout << "Im(z) : " << im_z << std::endl

    complex_number<double> re_w = w.re();
    complex_number<double> im_w = w.im();
    std::cout << "Re(w) : " << re_w << std::endl
    std::cout << "Im(w) : " << im_w << std::endl


    // Faccio la somma e visualizzo

    complex_number<double> s;
    s = z+w;
    std::cout << "Somma : " << s << std::endl;

    // Faccio la somma += e visualizzo
    z += w;
    std::cout << "z con += : " << z << std::endl;

    // Faccio il prodotto e visualizzo

    complex_number<double> p = z * w;
    std::cout << "Prodotto : " << p << std::endl;

    // Faccio il prodotto *= e visualizzo
    z *= w;   // Attenzione che qui prende la z dopo l'operazione +=
    std::cout << "z con *= : " << z << std::endl

    return 0;
}
    */
