#ifndef OOP_CONT_H
#define OOP_CONT_H

#include <bits/stdc++.h>
#include "istoric.h"
#include "tranzactie.h"

class cont {
protected:
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

    cont(double, std::string, int, std::string*, float, int, float*, float*, int, tranzactie*, int);
    cont(double, std::string, int);
    cont(int, int);
    cont(int);
    cont();
    cont(const cont&);
    ~cont();

    ///cativa setteri si getteri unde e nevoie
    double getSold() const;
    std::string getIBAN() const;
    int getId_cont() const;
    int getNr_tranzactii() const;
    std::string* getCarduri() const;
    int getId_titular() const;
    void setSold(double);
    void setIBAN(std::string);
    void setCarduri(std::string*, int);
    void setNr_carduri(int);
    void setId_titular(int);
    void setProcent_taxe(float);
    void setNr_tranzactii(int);
    void setIstoric(tranzactie*, int);

    ///functii pt cont
    void soldAdd(double);
    void soldTake(double);
    void modifyBalance(const tranzactie&);
    void checkAppendtranzactii(tranzactie*, int);
    void appendtranzactie(const tranzactie&);
    void checkIstoric();
    double nouTranzactie();
};


#endif //OOP_CONT_H
