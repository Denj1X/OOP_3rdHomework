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

std::ostream& operator<<(std::ostream& out, const istoric& d) {
    out << d.zi << "-" << d.luna << "-" << d.an << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, istoric& d) {
    bool ok = 0;
    int rez = 1;
    while(!ok && rez == 1) {
        std::cout<<"\nIntroduceti ziua: ";
        int z, l, a;
        std::string oper;
        in>>z;
        std::cout<<"Introduceti luna: ";
        in>>l;
        std::cout<<"Introduceti anul: ";
        in>>a;
        if (z > 31 || l > 12 || a > 2021 || a < 1800
            || z < 1 || l < 1)
                std::cout<<"Ati introdus o data incorecta.\n";
        else {
            bool ok1 = true;
            switch(l) {
                case 2: {
                    if((a % 4 != 0 && z > 28)|| (a % 4 == 0 && z > 29)) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
                }
                case 4:
                    if (z > 30) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
                case 6:
                    if (z > 30) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
                case 9:
                    if (z > 30) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
                case 11:
                    if (z > 30) {
                        ok1 = false;
                        std::cout<<"Ati introdus o data incorecta, incercati din nou\n";
                        break;
                    }
                    break;
            }
            if (ok1 == true) {
                ok = 1;
                d.setAn(a);
                d.setLuna(l);
                d.setZi(z);
            }
        }
        if (ok == 0) {
            std::cout<<"Apasati 1 pentru a incerca din nou. Daca iesiti se va inititializa data curenta.\n";
            in>>rez;
        }
    }
    if (!ok && rez != 1) {
        istoric aux;
        d = aux;
    }
    return in;
}

int nrzileLuna(int luna, int an) {
    int d_aux;
    if (luna == 4 || luna == 6 || luna == 9
        || luna == 11)
        d_aux = 30;
    else if (luna == 2) {
        if (an % 4 == 0 && an % 100 != 0)
            d_aux = 29;
        else if (an % 400 == 0)
            d_aux = 29;
        else d_aux = 28;
    }
    else d_aux = 31;
    return d_aux;
}

int istoric::getAn() const {
    return an;
}

void istoric::setAn(int _an) {
    istoric::an = _an;
}

int istoric::getLuna() const {
    return luna;
}

void istoric::setLuna(int luna_) {
    istoric::luna = luna_;
}

int istoric::getZi() const {
    return zi;
}

void istoric::setZi(int zi_) {
    istoric::zi = zi_;
}

istoric::istoric() {
    time_t now = time(0);
    tm *t = localtime(&now);
    this->zi = t->tm_mday;
    this->luna = 1 + t->tm_mon;
    this->an = 1900 + t->tm_year;
}

istoric::istoric(int z, int l, int a) {
    this->zi = z;
    this->luna = l;
    this->an = a;
}

istoric::istoric(int z, int l) {
    this->zi = z;
    this->luna = l;
    time_t now = time(0);
    tm *t = localtime(&now);
    this->an = 1900 + t->tm_year;
}

istoric::istoric(int z) {
    this->zi = z;
    time_t now = time(0);
    tm *t = localtime(&now);
    this->luna = 1 + t->tm_mon;
    this->an = 1900 + t->tm_year;
}

istoric::istoric(const istoric &d) {
    this->zi = d.zi;
    this->luna = d.luna;
    this->an = d.an;
}

istoric istoric::operator+=(int i) {
    int k = i;
    int cont_zi = 0;
    int aux_luna = this->luna;
    int cont_luna = 0;
    int aux_an = this->an;
    int cont_an = 0;
    cont_zi = this -> zi;
    while(k) {
        if (cont_zi + k < nrzileLuna(aux_luna, aux_an)) {
            cont_zi += k;
            k = 0;
        }
        else {
            k = k - nrzileLuna(aux_luna, aux_an);
            cont_luna += 1;
            if (aux_luna + 1 >= 13 && cont_luna != 0) {
                aux_an += 1;
                cont_an ++;
            }
            aux_luna = (aux_luna + 1)/13 + (aux_luna + 1)%13;
        }
    }
    istoric l(cont_zi, aux_luna, aux_an);
    *this = l;
    return *this;
}

int istoric::operator[](int idx) const {
    if(idx < 0 || idx > 2) {
        std::cout<<"\nIndex introdus gresit.\n";
        return -1;
    }
    else {
        switch (idx) {
            case 0:
                return this->zi;
                break;
            case 1:
                return this->luna;
                break;
            case 2:
                return this->an;
                break;
        }
    }
    return -1;
}

istoric::operator int *() const {
    int* aux = new int[3];
    aux[0] = this->zi;
    aux[1] = this->luna;
    aux[2] = this->an;
    return aux;
}

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

    tranzactie();
    tranzactie(const istoric, std::string, std::string, double);
    tranzactie(const istoric, std::string, double, int);
    virtual ~tranzactie() = default;
    tranzactie(const tranzactie&);

    ///setteri si getteri de siguranta
    const istoric &getDate() const;

    void setDate(const istoric &date);
};

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


int main() {
}
