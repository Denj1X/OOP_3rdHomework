#include <bits/stdc++.h>
#include <ostream>
#include "istoric.h"
#include "tranzactie.h"
#include "Cont.h"

class IdGenerator {
    static int nr;

public:
    static int generateId();
    IdGenerator() = delete;
};

int IdGenerator::nr = 0;

int IdGenerator::generateId() {
    return nr++;
}

class client {
    const int id_client;
    std::string nume;
    std::string prenume;
    long CNP;
    istoric start_date;
    int nr_initiale;
    char *initiale;
    char initiala_tatalui;
    int nr_cetatenii;
    std::string *cetatenie;
    double venit_anual;
    float *venit_lunar;
    int nr_conturi;
    cont *conturi; // HAS A
    double total_cash;
    static int counter_id_client;
public:
    friend std::ostream& operator<<(std::ostream&, const client&);

    friend std::istream& operator>>(std::istream&, client&);

    client& operator=(const client&);

    client& operator+=(const cont&);

    const cont& operator[](int) const;

    void setNume(std::string);
    void setPrenume(std::string);
    void setVenit_anual(double);
    void setTotal_cash(double);
    void setStart_date(const istoric&);
    void setInitiala_tata(char);
    void setCetatenii(std::string*, int);
    void setVenit_lunar(float*);
    void setConturi(int, const cont*);

    int getId_client() const;
    std::string getNume() const;
    std::string getPrenume() const;
    int getCNP() const;
    double getTotal_cash() const;
    int getNr_conturi() const;
    cont& getCont(int) const;

    ///functii pt client
    std::string ibanGen();
    void addCont();
    void addCont(const cont&);
    std::string intToString3(const int);
    void afisareZileMembru();
    void removeCont(int);
    void realizareTranzactie();

    ///constructori etc
    client(const client&);
    client(long);
    client(long, std::string, std::string, istoric, char, int, std::string*, double, float*, int, cont*);
    client(long, std::string, std::string, istoric, char, int, std::string*, double, float*);
    client(int, long);
    client();
    ~client();
};

std::istream& operator>>(std::istream& in, client& c) {
    std::cout<<"\n"<<char(254)<<"    Citire client    "<<char(254)<<"\n";
    std::cout<<"Introduceti nume: ";
    std::string n, p;
    in>>n;
    c.setNume(n);
    std::cout<<"Introduceti prenume: ";
    in>>p;
    c.setPrenume(p);
    istoric d;
    std::cout<<"Introduceti data: ";
    in>>d;
    c.setStart_date(d);
    std::cout<<"Introduceti initiala tatalui: ";
    char t;
    in>>t;
    c.setInitiala_tata(t);
    int nc;
    std::cout<<"Introduceti numarul de cetatenii: ";
    in>>nc;
    std::cout<<"Introduceti cetateniile pe rand.\n";
    std::string* aux = new std::string[nc];
    for (int i = 0; i < nc; ++i) {
        std::cout<<i+1<<". ";
        in>>aux[i];
    }
    c.setCetatenii(aux, nc); // dau delete si aloc iar memorie in setter
    double v;
    std::cout<<"Introduceti venitul anual: ";
    in>>v;
    c.setVenit_anual(v);
    std::cout<<"Introduceti pe rand venitul lunar.\n";
    float* ac = new float[12];
    for(int i = 0; i < 12; ++i) {
        std::cout<<"Luna "<<i+1<<" : ";
        in>>ac[i];
    }
    c.setVenit_lunar(ac);
    std::cout << "Introduceti nr. de conturi deschise: ";
    int nr;
    in >> nr;
    cont *auxc = new cont[nr];
    for (int i = 0; i < nr; ++i)
        in >> auxc[i];
    c.setConturi(nr, auxc);
    return in;
}

std::ostream& operator<<(std::ostream& out, const client& c) {
    out<<"\n"<<char(254)<<"    Detalii client    "<<char(254)<<"\n";
    out<<"Nume: "<<c.nume
       <<"\nPrenume: "<<c.prenume
       <<"\nCNP: "<<c.CNP
       <<"\nInitiala tatalui: "<<c.initiala_tatalui;
    if (c.nr_cetatenii > 0) {
        out<<"\nCetatenii: ";
        for (int i = 0; i < c.nr_cetatenii - 1; ++i)
            out<<c.cetatenie[i]<<", ";
        out<<c.cetatenie[c.nr_cetatenii - 1]<<"\n";
    }
    else out<<"\nNu au fost introduse cetateniile.\n";
    out<<"Venit anual: "<<c.venit_anual<<" lei\n"
       <<"Nr. conturi deschise: "<<c.nr_conturi<<"\n";
    if (c.nr_conturi != 0) {
        out<<"Valoare totala conturi: "<<c.total_cash<<" lei\n";
    }
    return out;
}

client& client::operator=(const client& c) {
    if (this != &c) {
        this->nume = c.nume;
        this->prenume = c.prenume;
        this->nr_initiale = c.nr_initiale;
        if (this->initiale != NULL)
            delete []this->initiale;
        this->initiale = new char[this->nr_initiale];
        for (int i = 0; i < this->nr_initiale; ++i)
            this->initiale[i] = c.initiale[i];
        this->initiala_tatalui = c.initiala_tatalui;
        this->nr_cetatenii = c.nr_cetatenii;
        if (this->cetatenie)
            delete []this->cetatenie;
        this->cetatenie = new std::string[this->nr_cetatenii];
        for (int i = 0; i < this->nr_cetatenii; ++i)
            this->cetatenie[i] = c.cetatenie[i];
        this->venit_anual = c.venit_anual;
        if (this->venit_lunar)
            delete []this->venit_lunar;
        this->venit_lunar = new float[12];
        for(int i = 0; i < 12; ++i)
            this->venit_lunar[i] = c.venit_lunar[i];
        this->nr_conturi = c.nr_conturi;
        if (this->conturi)
            delete []this->conturi;
        this->conturi = new cont[this->nr_conturi];
        for (int i = 0; i < this->nr_conturi; ++i)
            this->conturi[i] = c.conturi[i];
    }
    return *this;
}

client& client::operator+=(const cont& c) {
    if (this->conturi) {
        cont* aux = this->conturi;
        delete[] this->conturi;
        this->conturi = new cont[this->nr_conturi + 1];
        for (int i = 0; i < this->nr_conturi; ++i)
            this->conturi[i] = aux[i];
        this->conturi[this->nr_conturi] = c;
        this->nr_conturi++;
    }
    else {
        this->conturi = new cont[this->nr_conturi + 1];
        this->conturi[this->nr_conturi] = c;
        this->nr_conturi++;
    }
    this->total_cash += this->conturi[this->nr_conturi - 1].getSold();
    return *this;
}

const cont& client::operator[](int idx) const {
    if (this->nr_conturi != 0 && idx >= 0 && idx < this->nr_conturi)
        return this->conturi[idx];
    if (this->nr_conturi == 0)
        std::cout<<"Nu exista niciun cont asociat.\n";
    else
    if (idx < 0 || idx >= this->nr_conturi)
        std::cout<<"Index invalid.\n";
    return this->conturi[idx];
}

void client::setNume(std::string n) {
    this->nume = n;
}

void client::setPrenume(std::string p) {
    this->prenume = p;
    if (this->initiale)
        delete[] this->initiale;
    this->nr_initiale = 1;
    this->initiale = new char[10];
    this->initiale[0] = this->prenume[0];
    int poz = this->prenume.find("-");
    while(poz != -1) {
        this->nr_initiale += 1;
        this->initiale[nr_initiale - 1] = this->prenume[poz + 1];
        poz = prenume.find("-", poz + 1);
    }
}

void client::setVenit_anual(double v) {
    this->venit_anual = v;
}

void client::setTotal_cash(double s) {
    this->total_cash += s;
}

void client::setStart_date(const istoric& d) {
    this->start_date = d;
}

void client::setCetatenii(std::string* s, int n) {
    if (this->cetatenie) // Dezalocare
        delete[] this->cetatenie;
    if (n != 0) {
        this->cetatenie = new std::string[n]; // Alocare noua
        for(int i = 0; i < n; ++i)
            this->cetatenie[i] = s[i];
    }
    this->nr_cetatenii = n;
}

void client::setInitiala_tata(char t) {
    this->initiala_tatalui = t;
}

void client::setVenit_lunar(float* t) {
    // nu dealoc memoria pt ca oricum tot 12 o sa fie dimensiunea
    if (!(this->venit_lunar))
        this->venit_lunar = new float[12];
    for (int i = 0; i < 12; ++i)
        this->venit_lunar[i] = t[i];
}

void client::setConturi(int nr, const cont* c) {
    if (this->conturi) // Dezalocare
        delete[] this->conturi;
    if (nr != 0) {
        this->conturi = new cont[nr]; // Alocare noua
        for(int i = 0; i < nr; ++i)
            this->conturi[i] = c[i];
    }
    this->nr_conturi = nr;
}

cont& client::getCont(int index) const {
    return this->conturi[index];
}

int client::getId_client() const {
    return this->id_client;
}

int client::getNr_conturi() const {
    return this->nr_conturi;
}

std::string client::getNume() const {
    return this->nume;
}

std::string client::getPrenume() const {
    return this->prenume;
}

int client::getCNP() const {
    return this->CNP;
}

double client::getTotal_cash() const {
    return this->total_cash;
}

client:: client(int i, long c):id_client(i), CNP(c), counter_id_client(IdGenerator::generateId()) {
    this->nume = "";
    this->prenume = "";
    this->initiale = NULL;
    this->initiala_tatalui = ' ';
    this->nr_cetatenii = 0;
    this->cetatenie = NULL;
    this->venit_anual = 0;
    this->venit_lunar = NULL;
    this->nr_conturi = 0;
    this->conturi = NULL;
    this->total_cash = 0;
}

client::client(const client& c):id_client(c.id_client), CNP(c.CNP), counter_id_client(c.counter_id_client) {
    this->nume = c.nume;
    this->prenume = c.prenume;
    this->nr_initiale = c.nr_initiale;
    this->initiale = c.initiale;
    this->initiala_tatalui = c.initiala_tatalui;
    this->nr_cetatenii = c.nr_cetatenii;
    this->cetatenie = c.cetatenie;
    this->venit_anual = c.venit_anual;
    this->nr_conturi = c.nr_conturi;
    this->conturi = c.conturi;
    this->total_cash = c.total_cash;
}

client::client(): id_client(++counter_id_client), CNP(0) {
    this->nume = "";
    this->prenume = "";
    this->initiale = NULL;
    this->initiala_tatalui = ' ';
    this->nr_cetatenii = 0;
    this->cetatenie = NULL;
    this->venit_anual = 0;
    this->venit_lunar = NULL;
    this->nr_conturi = 0;
    this->conturi = NULL;
    this->total_cash = 0;
}

class Cont_Curent: public cont {
public:
    Cont_Curent(double d, const std::string &string, int i, std::string *string1, float d1, int i1, float *pDouble,
                float *pDouble1, int i2, tranzactie *tranzactie, int i3) : cont(d, string, i, string1, d1, i1, pDouble,
                                                                                pDouble1, i2, tranzactie, i3) {}

    Cont_Curent(const cont &cont_) : cont(cont_) {}

    virtual ~Cont_Curent() = default;

    friend std::ostream &operator<<(std::ostream &os, const Cont_Curent &curent) {
        os << static_cast<const cont &>(curent);
        return os;
    }
};

class Cont_Economie: public cont {
protected:
    int zi;
    int luna;
    int an;
public:
    Cont_Economie(double d, const std::string &string, int i, std::string *string1, float d1, int i1, float *pDouble,
                  float *pDouble1, int i2, tranzactie *tranzactie, int i3, int zi_, int luna_, int an_) :
                  cont(d, string, i, string1, d1, i1, pDouble, pDouble1, i2, tranzactie, i3), zi(zi_), luna(luna_), an(an_) {}

    int getAn() const {
        return an;
    }

    int getZi() const {
        return zi;
    }

    int getLuna() const {
        return luna;
    }

    void functia_dobanda(Cont_Economie &kek) {
        int an_ = kek.getAn();
        int luna_ = kek.getLuna();
        int zi_ = kek.getZi();

        ///iau datele din ziua de azi
        ///si verific daca au trecut 365 de zile
        ///pentru dobanda respectiva
    }
};

int main() {
    ///RIP meniu
}
