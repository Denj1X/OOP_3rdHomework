#ifndef OOP_ISTORIC_H
#define OOP_ISTORIC_H

#include <bits/stdc++.h>
#include <ostream>

class istoric {
private:
    int zi;
    int luna;
    int an;
    std::string tip;
    float suma;
public:
    istoric(int zi_, int luna_, int an_, std::string tip_, float suma_);

    istoric(const istoric& rhs);

    virtual ~istoric();

    int getZi() const;

    void setZi(int zi_);

    int getLuna() const;

    void setLuna(int luna_);

    int getAn() const;

    void setAn(int an_);

    const std::string &getTip() const;

    void setTip(const std::string &tip_);

    float getSuma() const;

    void setSuma(float suma_);

    bool operator==(const istoric &rhs) const;

    bool operator!=(const istoric &rhs) const;

    void operator=(const istoric &rhs);

    friend std::ostream &operator<<(std::ostream &os, const istoric &istoric);
};
///intentionez sa folosesc Object Pool drept un desing pattern
///trebuie sa vad unde mai exact
#endif //OOP_ISTORIC_H

