#include <bits/stdc++.h>
#include "ContCurent.h"
#include "Cont.h"

ContCurent::ContCurent() {}

ContCurent::ContCurent(const ContCurent &a) {
    nr_tranz = a.nr_tranz;
    dob_tranz = a.dob_tranz;
    sum = a.sum;
}

void ContCurent::operator=(ContCurent &a) {
    this->nr_tranz = a.nr_tranz;
    this->dob_tranz = a.dob_tranz;
    this->sum = a.sum;
}