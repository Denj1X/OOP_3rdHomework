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
};
#endif //OOP_CONTCURENT_H
