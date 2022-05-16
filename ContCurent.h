#ifndef OOP_CONTCURENT_H
#define OOP_CONTCURENT_H

#include <bits/stdc++.h>
#include "Cont.h"
class ContCurent: public Cont {
private:
    int nr_tranz;
    float dob_tranz;
    float sum;
public:
    ContCurent();

    ~ContCurent();

    ContCurent(const ContCurent &a);

    void operator= (ContCurent &a);

    friend std::istream& operator>>(std::istream &in, Cont &a);

    float get_sum();

    void retragere();

    void depunere();

    friend std::ostream& operator<<(std::ostream &out, Cont &a);

    void afisare();
};
#endif //OOP_CONTCURENT_H
