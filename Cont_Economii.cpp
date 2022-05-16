#include <bits/stdc++.h>
#include "Cont_Economii.h"

Cont_Economii::Cont_Economii() {

}

Cont_Economii::~Cont_Economii() {

}

Cont_Economii::Cont_Economii(const Cont_Economii &a) {

}

void Cont_Economii::operator=(Cont_Economii &a) {

}

void Cont_Economii::react() {
    istoric x(0, 0, 0, "", 0);
    float val;
    int zi_, luna_, an_;
    std::string t="reactualizare";
    std::cout << "Data curenta: ";
    std::cin >> zi_ >> luna_ >> an_;
    x.setZi(zi_);
    x.setLuna(luna_);
    x.setAn(an_);
    x.setTip(t);
    val = this->getSold() * this->rata_dob * (12 / this->perioada_dob);
    x.setSuma(val);
    this->getSuma() = val;
    this->getSold() += x.getSuma();
    this->ist.push_back(x);
}

void Cont_Economii::viz_ist() {
    std::list<istoric>::iterator p;
    for(p = this->ist.begin(); p != this->ist.end(); p++)
        std::cout << *p << '\n';
}

float Cont_Economii::get_ssum() {
    return this->ssum;
}