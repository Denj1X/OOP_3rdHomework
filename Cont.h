#ifndef OOP_CONT_H
#define OOP_CONT_H

#include <bits/stdc++.h>
#include "istoric.h"
#include "tranzactie.h"

class cont {
private:
    const int id_cont;
    double sold;
    std::string IBAN;
    int nr_carduri;
    std::string *carduri;
    float procent_taxe;
    int id_titular;
    float* bilant_pozitiv_lunar;
    float* bilant_negativ_lunar;
    int nr_tranzactii;
    tranzactie* istoric;

public:
    static int contor_id_cont;

    cont& operator=(const cont&);
    friend std::ostream& operator<<(std::ostream&, const cont&);
    friend std::istream& operator>>(std::istream&, cont&);
    cont& operator+=(const tranzactie&);
    tranzactie operator[](int) const;


};


#endif //OOP_CONT_H
