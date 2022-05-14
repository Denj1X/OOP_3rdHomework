#include <bits/stdc++.h>
#include "istoric.h"


istoric::istoric(int zi_, int luna_, int an_, std::string tip_, float suma_) : zi(zi_),
    luna(luna_), an(an_), tip(tip_), suma(suma_){}

istoric::istoric(const istoric& rhs) {
    zi = rhs.zi;
    luna = rhs.luna;
    an = rhs.an;
    tip = rhs.tip;
    suma = rhs.suma;
}

istoric::~istoric() = default;

int istoric::getZi() const {
    return zi;
}

void istoric::setZi(int zi_) {
    istoric::zi = zi_;
}

int istoric::getLuna() const {
    return luna;
}

void istoric::setLuna(int luna_) {
    istoric::luna = luna_;
}

int istoric::getAn() const {
    return an;
}

void istoric::setAn(int an_) {
    istoric::an = an_;
}

const std::string &istoric::getTip() const {
    return tip;
}

void istoric::setTip(const std::string &tip_) {
    istoric::tip = tip_;
}

float istoric::getSuma() const {
    return suma;
}

void istoric::setSuma(float suma_) {
    istoric::suma = suma_;
}

bool istoric::operator==(const istoric &rhs) const {
    return zi == rhs.zi &&
           luna == rhs.luna &&
           an == rhs.an &&
           tip == rhs.tip &&
           suma == rhs.suma;
}

bool istoric::operator!=(const istoric &rhs) const {
    return !(rhs == *this);
}

void istoric::operator=(istoric &rhs) {
    this->zi = rhs.zi;
    this->luna = rhs.luna;
    this->an = rhs.an;
    this->tip = rhs.tip;
    this->suma = rhs.suma;
}

std::ostream &operator<<(std::ostream &os, const istoric &istoric) {
    os << "zi: " << istoric.zi << " luna: " << istoric.luna << " an: " << istoric.an << " tip: " << istoric.tip
       << " suma: " << istoric.suma << '\n';
    return os;
}

