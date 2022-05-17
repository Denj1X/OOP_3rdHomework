#ifndef OOP_ISTORIC_H
#define OOP_ISTORIC_H

#include <bits/stdc++.h>

class istoric {
private:
    int zi;
    int luna;
    int an;

public:
    ///functii friend si supraincarcari
    friend std::ostream& operator<<(std::ostream&, const istoric&);
    friend std::istream& operator>>(std::istream&, istoric&);
    friend int nrzileLuna(int luna, int an);
    istoric& operator=(istoric& c) {
        if (this != &c) {
            this->an = c.getAn();
            this->luna = c.getLuna();
            this->zi = c.getZi();
        }
        return *this;
    }

    istoric& operator=(const istoric& c) {
        this->an = c.an;
        this->luna = c.luna;
        this->zi = c.zi;
        return *this;
    }

    istoric operator+=(int);

    int operator[](int) const;

    explicit operator int*() const;
    ///gettere si settere
    int getAn() const;
    void setAn(int);

    int getLuna() const;
    void setLuna(int);

    int getZi() const;
    void setZi(int);

    ///constructori si destructori
    istoric();
    istoric(int, int, int);
    istoric(int, int);
    istoric(int);

    virtual ~istoric() = default;

    istoric(const istoric&);
};
#endif //OOP_ISTORIC_H
