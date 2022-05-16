#include <bits/stdc++.h>
#include "Cont.h"

Cont::Cont(int zi, int luna, int an, const std::string &tip, float suma,
           const std::string &cnp, const std::string &detin, const float &sold_) :
           istoric(zi,luna,an,tip, suma), CNP(cnp), detinator(detin), sold(sold_) {}

const std::string &Cont::getCnp() const {
    return CNP;
}

void Cont::setCnp(const std::string &cnp) {
    CNP = cnp;
}

const std::string &Cont::getDetinator() const {
    return detinator;
}

void Cont::setDetinator(const std::string &detinator_) {
    Cont::detinator = detinator_;
}

float Cont::getSold() const {
    return sold;
}

void Cont::setSold(float sold_) {
    Cont::sold = sold_;
}

void Cont::operator=(const Cont &a) {
    this->detinator = a.detinator;
    this->CNP = a.CNP;
    this->sold = a.sold;
}

std::istream &operator>>(std::istream &is, Cont &cont) {
    is >> cont.CNP >> cont.detinator >> cont.sold;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Cont &cont) {
    os << static_cast<const istoric &>(cont) << " CNP: " << cont.CNP << " detinator: " << cont.detinator << " sold: "
       << cont.sold << '\n';
    return os;
}

void Cont::afisare () {
    std::cout<<"Nume si prenume: "<<this->detinator<<'\n';
    std::cout<<"CNP: "<<this->CNP<<'\n';
    std::cout<<"Sold: "<<this->sold<<'\n';
}

void citire(std::istream &is, Cont &a) {
    is >> a;
}
