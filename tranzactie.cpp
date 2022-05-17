#include<bits/stdc++.h>
#include "tranzactie.h"

std::ostream& operator<<(std::ostream& out, const tranzactie& t) {
    out<<"\n---------------Tranzactie---------------\n";
    out<<"Data: "<<t.date<<"\n"
       <<"Cod: "<<t.id_tranz<<"\n";
    if (t.credit) {
        out<<"-----Credit bancar\n"
           <<"Beneficiar: "<<t.primeste<<"\n";
    }
    else if (t.depunere) {
        out<<"-----Depunere\n"
           <<"Beneficiar: "<<t.primeste<<"\n";
    }
    else if (t.retragere) {
        out<<"-----Retragere\n"
           <<"Din: "<<t.trimite<<"\n";
    }
    else {
        out<<"-----Transfer\n"
           <<"Beneficiar: "<<t.primeste<<"\n"
           <<"Din: "<<t.trimite<<"\n";
    }
    out<<t.suma<<" lei\n";
    return out;
}

std::istream& operator>>(std::istream& in, tranzactie& t) {
    istoric aux;
    std::cout<<"\n"<<char(254)<<"    Citire tranzactie    "<<char(254)<<"\n";
    in>>aux;
    std::cout<<"Ce tip de tranzactie este: \n"
             <<"1. Credit bancar \n2. Retragere suma\n3. Depunere suma\n4. Transfer\n";
    int option;
    in>>option;
    switch(option)
    {
        case 1:
            t.credit = 1;
            t.retragere = 0;
            t.depunere = 0;
            std::cout<<"\nIntroduceti iban-ul contului: ";
            in>>t.primeste;
            std::cout<<"\nIntroduceti suma: ";
            in>>t.suma;
            break;
        case 2:
            t.retragere = 1;
            t.credit = 0;
            t.depunere = 0;
            std::cout<<"\nIntroduceti iban-ul contului: ";
            in>>t.trimite;
            std::cout<<"\nIntroduceti suma: ";
            in>>t.suma;
            break;
        case 3:
            t.depunere = 1;
            t.credit = 0;
            t.retragere = 0;
            std::cout<<"\nIntroduceti iban-ul contului: ";
            in>>t.primeste;
            std::cout<<"\nIntroduceti suma: ";
            in>>t.suma;
            break;
        case 4:
            t.credit = 0;
            t.depunere = 0;
            t.retragere = 0;
            std::cout<<"\nIntroduceti iban-ul contului din care se transfera suma: ";
            in>>t.trimite;
            std::cout<<"\nIntroduceti iban-ul contului care primeste suma: ";
            in>>t.primeste;
            std::cout<<"\nIntroduceti suma: ";
            in>>t.suma;
            break;
        default:
            std::cout<<"Optiune invalida\n";
    }
    return in;
}

tranzactie& tranzactie::operator=(tranzactie &t) {
    if (this != &t) {
        this->date = t.date;
        this->trimite = t.trimite;
        this->primeste = t.primeste;
        this->suma = t.suma;
        this->credit = t.credit;
        this->depunere = t.depunere;
        this->retragere = t.retragere;
    }
    return *this;
}

tranzactie& tranzactie::operator+=(double val) {
    this->suma += val;
    return *this;
}

std::string tranzactie::operator[](int idx) const {
    if (idx == 0)
        return this->trimite;
    if (idx == 1)
        return this->primeste;
    std::cout<<"\nIndex invalid.\n";
    return "Index invalid";
}

int tranzactie::contor_id_tranz = 0;

tranzactie::tranzactie(): id_tranz(contor_id_tranz++),  trimite(""),
                          primeste(""), suma(0), credit(0), retragere(0), depunere(0){
    istoric aux;
    this->date = aux;
}

tranzactie::tranzactie(const istoric date_, std::string iban1, std::string iban2, double suma_):
        id_tranz(contor_id_tranz++), date(date_), trimite(iban1), primeste(iban2), suma(suma_) {
    this->retragere = 0;
    this->depunere = 0;
    this->credit = 0;
}

tranzactie::tranzactie(const istoric date_, std::string iban1, double suma_, int type):
        id_tranz(contor_id_tranz++), date(date_), suma(suma_) {
    switch(type) {
        case 1:
            this->credit = 1;
            this->depunere = 0;
            this->retragere = 0;
            this->primeste = iban1;
            break;
        case 2:
            this->depunere = 1;
            this->primeste = iban1;
            this->credit = 0;
            this->retragere = 0;
            break;
        case 3:
            this->retragere = 1;
            this->trimite = iban1;
            this->credit = 0;
            this->depunere = 0;
            break;
    }
}

tranzactie::tranzactie(const tranzactie& t): id_tranz(t.id_tranz) {
    this->date = t.date;
    this->trimite = t.trimite;
    this->primeste = t.primeste;
    this->suma = t.suma;
    this->credit = t.credit;
    this->retragere = t.retragere;
    this->depunere = t.depunere;
}

const istoric &tranzactie::getDate() const {
    return date;
}

void tranzactie::setDate(const istoric &date_) {
    tranzactie::date = date_;
}

int tranzactie::getIdTranz() const {
    return id_tranz;
}

bool tranzactie::isCredit() const {
    return credit;
}

void tranzactie::setCredit(bool credit_) {
    tranzactie::credit = credit_;
}

double tranzactie::getSuma() const {
    return suma;
}

void tranzactie::setSuma(double suma_) {
    tranzactie::suma = suma_;
}

bool tranzactie::isDepunere() const {
    return depunere;
}

void tranzactie::setDepunere(bool depunere_) {
    tranzactie::depunere = depunere_;
}

bool tranzactie::isRetragere() const {
    return retragere;
}

void tranzactie::setRetragere(bool retragere_) {
    tranzactie::retragere = retragere_;
}

const std::string &tranzactie::getPrimeste() const {
    return primeste;
}

void tranzactie::setPrimeste(const std::string &primeste_) {
    tranzactie::primeste = primeste_;
}

const std::string &tranzactie::getTrimite() const {
    return trimite;
}

void tranzactie::setTrimite(const std::string &trimite_) {
    tranzactie::trimite = trimite_;
}

