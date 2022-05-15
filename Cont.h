#ifndef OOP_CONT_H
#define OOP_CONT_H

#include <bits/stdc++.h>
#include "istoric.h"

class Cont: public istoric {
private:
    std::string CNP;
    std::string detinator;
    float sold;

public:
    Cont(int zi, int luna, int an, const std::string &tip, float suma,
         const std::string &cnp, const std::string &detin, const float &sold_);

    virtual ~Cont() = default;

    const std::string &getCnp() const;

    void setCnp(const std::string &cnp);

    const std::string &getDetinator() const;

    void setDetinator(const std::string &detinator);

    float getSold() const;

    void setSold(float sold);

    void operator = (const Cont &a);

    friend std::istream &operator>>(std::istream &is, Cont &cont);

    friend std::ostream &operator<<(std::ostream &os, const Cont &cont);

    virtual void afisare();
};


#endif //OOP_CONT_H
