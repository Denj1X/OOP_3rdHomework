#ifndef OOP_CONT_ECONOMII_H
#define OOP_CONT_ECONOMII_H

#include <bits/stdc++.h>
#include "istoric.h"
#include "Cont.h"

class Cont_Economii:public Cont {
private:
    float rata_dob;
    float perioada_dob;
    std:: list<istoric> ist;
    float ssum;
public:
    Cont_Economii();

    ~Cont_Economii();

    Cont_Economii(const Cont_Economii &a);

    void operator =(Cont_Economii &a);

    friend void citire(Cont_Economii &a);

    friend std::istream& operator>>(std::istream &is, Cont &a);

    friend std::ostream& operator<<(std::ostream &os, const Cont &a);

    void react();

    void viz_ist();

    float get_ssum();

    void citire(Cont_Economii &a);

    void afisare();
};
#endif //OOP_CONT_ECONOMII_H
