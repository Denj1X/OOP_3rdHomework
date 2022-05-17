#ifndef OOP_TRANZACTIE_H
#define OOP_TRANZACTIE_H

#include <bits/stdc++.h>
#include "istoric.h"

class tranzactie {
private:
    const int id_tranz;
    istoric date;
    std::string trimite;
    std::string primeste;
    double suma;
    bool credit;
    bool retragere;
    bool depunere;
public:
    static int contor_id_tranz;

    friend std::ostream& operator<<(std::ostream&, const tranzactie&);
    friend std::istream& operator>>(std::istream&, tranzactie&);
    tranzactie& operator=(tranzactie &);
    tranzactie& operator+=(double);
    std::string operator[](int) const;

    tranzactie();
    tranzactie(const istoric, std::string, std::string, double);
    tranzactie(const istoric, std::string, double, int);
    virtual ~tranzactie() = default;
    tranzactie(const tranzactie&);

    ///setteri si getteri de siguranta
    const istoric &getDate() const;
    void setDate(const istoric &date);

    int getIdTranz() const;

    bool isCredit() const;
    void setCredit(bool credit_);

    double getSuma() const;
    void setSuma(double suma_);

    bool isDepunere() const;
    void setDepunere(bool depunere_);

    bool isRetragere() const;
    void setRetragere(bool retragere_);

    const std::string &getPrimeste() const;
    void setPrimeste(const std::string &primeste_);

    const std::string &getTrimite() const;
    void setTrimite(const std::string &trimite_);
};
#endif //OOP_TRANZACTIE_H
