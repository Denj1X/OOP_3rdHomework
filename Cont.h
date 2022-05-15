#ifndef OOP_CONT_H
#define OOP_CONT_H

#include <bits/stdc++.h>
#include <ostream>
#include "istoric.h"

class Cont: public istoric {
protected:
    std::string CNP;
    std::string detinator;
    float sold;
    Cont(int zi, int luna, int an, const std::string &tip, float suma,
         const std::string &cnp, const std::string &detin, const float &sold_);

public:
    virtual ~Cont() = default;

    const std::string &getCnp() const;

    void setCnp(const std::string &cnp);

    const std::string &getDetinator() const;

    void setDetinator(const std::string &detinator);

    float getSold() const;

    void setSold(float sold);

    void operator = (const Cont &a);

    friend std::ostream &operator>>(std::ostream &is, Cont &cont);

    friend std::ostream &operator<<(std::ostream &os, const Cont &cont);

    friend void citire(Cont &a);
};


#endif //OOP_CONT_H
