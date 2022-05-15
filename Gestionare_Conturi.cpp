#include <bits/stdc++.h>

template <class T> class Gestionare_Conturi {
private:
    std:: string nume_banca;
    int id_cont;
    T cont;
public:
    void operator+=(int &a);
    void operator-=(int &a);
    void operator=(const Gestionare_Conturi &a);
};

template <class T>
void Gestionare_Conturi<T>::operator+=(int &a) {
    this->nume_banca = "BCR";
    this->id_cont = a;
    a++;
}

template <class T>
void Gestionare_Conturi<T>::operator-=(int &a) {
    a--;
}

template <class T>
void Gestionare_Conturi<T>::operator= (const Gestionare_Conturi &a) {
    this->nume_banca = a.nume_banca;
    this->id_cont = a.id_cont;
    this->cont = a.cont;
}

