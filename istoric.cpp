#include <bits/stdc++.h>
#include "istoric.h"

std::ostream& operator<<(std::ostream& out, const istoric& d) {
    out << d.zi << "-" << d.luna << "-" << d.an << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, istoric& d) {
    bool ok = 0;
    int rez = 1;
    while(!ok && rez == 1) {
        std::cout<<"\nIntroduceti ziua: ";
        int z, l, a;
        std::string oper;
        in>>z;
        std::cout<<"Introduceti luna: ";
        in>>l;
        std::cout<<"Introduceti anul: ";
        in>>a;
        if (z > 31 || l > 12 || a > 2021 || a < 1800
            || z < 1 || l < 1)
            std::cout<<"Ati introdus o data incorecta.\n";
        else {
            bool ok1 = true;
            switch(l) {
                case 2: {
                    if((a % 4 != 0 && z > 28)|| (a % 4 == 0 && z > 29)) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
                }
                case 4:
                    if (z > 30) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
                case 6:
                    if (z > 30) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
                case 9:
                    if (z > 30) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
                case 11:
                    if (z > 30) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
            }
            if (ok1 == true) {
                ok = 1;
                d.setAn(a);
                d.setLuna(l);
                d.setZi(z);
            }
        }
        if (ok == 0) {
            std::cout<<"Apasati 1 pentru a incerca din nou. Daca iesiti se va inititializa data curenta.\n";
            in>>rez;
        }
    }
    if (!ok && rez != 1) {
        istoric aux;
        d = aux;
    }
    return in;
}

int nrzileLuna(int luna, int an) {
    int d_aux;
    if (luna == 4 || luna == 6 || luna == 9
        || luna == 11)
        d_aux = 30;
    else if (luna == 2) {
        if (an % 4 == 0 && an % 100 != 0)
            d_aux = 29;
        else if (an % 400 == 0)
            d_aux = 29;
        else d_aux = 28;
    }
    else d_aux = 31;
    return d_aux;
}

int istoric::getAn() const {
    return an;
}

void istoric::setAn(int _an) {
    istoric::an = _an;
}

int istoric::getLuna() const {
    return luna;
}

void istoric::setLuna(int luna_) {
    istoric::luna = luna_;
}

int istoric::getZi() const {
    return zi;
}

void istoric::setZi(int zi_) {
    istoric::zi = zi_;
}

istoric::istoric() {
    time_t now = time(0);
    tm *t = localtime(&now);
    this->zi = t->tm_mday;
    this->luna = 1 + t->tm_mon;
    this->an = 1900 + t->tm_year;
}

istoric::istoric(int z, int l, int a) {
    this->zi = z;
    this->luna = l;
    this->an = a;
}

istoric::istoric(int z, int l) {
    this->zi = z;
    this->luna = l;
    time_t now = time(0);
    tm *t = localtime(&now);
    this->an = 1900 + t->tm_year;
}

istoric::istoric(int z) {
    this->zi = z;
    time_t now = time(0);
    tm *t = localtime(&now);
    this->luna = 1 + t->tm_mon;
    this->an = 1900 + t->tm_year;
}

istoric::istoric(const istoric &d) {
    this->zi = d.zi;
    this->luna = d.luna;
    this->an = d.an;
}

istoric istoric::operator+=(int i) {
    int k = i;
    int cont_zi = 0;
    int aux_luna = this->luna;
    int cont_luna = 0;
    int aux_an = this->an;
    int cont_an = 0;
    cont_zi = this -> zi;
    while(k) {
        if (cont_zi + k < nrzileLuna(aux_luna, aux_an)) {
            cont_zi += k;
            k = 0;
        }
        else {
            k = k - nrzileLuna(aux_luna, aux_an);
            cont_luna += 1;
            if (aux_luna + 1 >= 13 && cont_luna != 0) {
                aux_an += 1;
                cont_an ++;
            }
            aux_luna = (aux_luna + 1)/13 + (aux_luna + 1)%13;
        }
    }
    istoric l(cont_zi, aux_luna, aux_an);
    *this = l;
    return *this;
}

int istoric::operator[](int idx) const {
    if(idx < 0 || idx > 2) {
        std::cout<<"\nIndex introdus gresit.\n";
        return -1;
    }
    else {
        switch (idx) {
            case 0:
                return this->zi;
                break;
            case 1:
                return this->luna;
                break;
            case 2:
                return this->an;
                break;
        }
    }
    return -1;
}

istoric::operator int *() const {
    int* aux = new int[3];
    aux[0] = this->zi;
    aux[1] = this->luna;
    aux[2] = this->an;
    return aux;
}
