#include <bits/stdc++.h>
#include "Cont.h"

cont& cont::operator=(const cont& c) {
    if (this != &c) {
        this->sold = c.sold;
        this->IBAN = c.IBAN;
        this->nr_carduri = c.nr_carduri;
        if (this->carduri != NULL)
            delete []this->carduri;
        this->carduri = new std::string[c.nr_carduri];
        for(int i = 0; i < c.nr_carduri; ++i)
            this->carduri[i] = c.carduri[i];
        this->procent_taxe = c.procent_taxe;
        if (c.bilant_negativ_lunar != NULL) {
            if (this->bilant_negativ_lunar != NULL)
                delete []this->bilant_negativ_lunar;
            for(int i = 0; i < 12; ++i)
                this->bilant_negativ_lunar[i] = c.bilant_negativ_lunar[i];
        }
        else {
            if (this->bilant_negativ_lunar != NULL)
                delete []this->bilant_negativ_lunar;
        }
        if (c.bilant_pozitiv_lunar != NULL) {
            if (this->bilant_pozitiv_lunar != NULL)
                delete []this->bilant_pozitiv_lunar;
            for(int i = 0; i < 12; ++i)
                this->bilant_pozitiv_lunar[i] = c.bilant_pozitiv_lunar[i];
        }
        else {
            if (this->bilant_pozitiv_lunar != NULL)
                delete []this->bilant_pozitiv_lunar;
        }
        this->nr_tranzactii = c.nr_tranzactii;
        if (this->istoric != NULL)
            delete[] this->istoric;
        if (c.istoric != NULL) {
            this->istoric = new tranzactie[c.nr_tranzactii];
            for(int i = 0; i < c.nr_tranzactii; ++i)
                this->istoric[i] = c.istoric[i];
        }
        this->id_titular = c.id_titular;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const cont& c) {
    out<<"\n"<<char(254)<<"    Detalii cont    "<<char(254)<<"\n";
    if (c.id_titular != 0)
        out<<"Titular: "<<c.id_titular<<"\n";
    out<<"Sold: "<<c.sold<<" lei\n"
       <<"IBAN: "<<c.IBAN<<"\n"
       <<"Numar carduri asociate: "<<c.nr_carduri<<"\n"
       <<"Procent taxe: "<<c.procent_taxe<<"%\n"
       <<"Numar tranzactii: "<<c.nr_tranzactii<<"\n";
    if(c.nr_tranzactii > 0) {
        out<<"Apasati 1 pentru a vedea istoricul tranzactiilor\n"
           <<"Apasati 0 pentru iesire\n";
        int rez;
        std::cin >> rez;
        if(rez == 1)
            for(int i = 0; i < c.nr_tranzactii; ++i)
                out<<c.istoric[i];
    }
    out<<"\n";
    return out;
}

std::istream& operator>>(std::istream& in, cont& c) {
    std::cout<<"\nIntroduceti IBAN: ";
    std::string iban_aux;
    in>>iban_aux;
    c.setIBAN(iban_aux);
    std::cout<<"\nIntroduceti numarul de carduri asociate: ";
    int nr_card_aux;
    in>>nr_card_aux;
    c.setNr_carduri(nr_card_aux);
    if (nr_card_aux > 0) {
        std::cout<<"\nIntroduceti pe rand numarul fiecarui card.";
        std::string* carduri_aux = new std::string[nr_card_aux];
        for (int i = 1; i <= nr_card_aux; ++i) {
            std::cout<<"\n"<<i<<". ";
            in>>carduri_aux[i];
        }
        // dau delete si aloc iar memorie in setter
        c.setCarduri(carduri_aux, nr_card_aux);
    }
    else
        delete[] c.carduri;
    std::cout<<"Introduceti procent taxe: ";
    float procent_taxe_aux;
    in>>procent_taxe_aux;
    c.setProcent_taxe(procent_taxe_aux);
    std::cout<<"Introduceti numarul de tranzactii asociate: ";
    int nr_tranzactii_aux;
    in>>nr_tranzactii_aux;
    c.setNr_tranzactii(nr_tranzactii_aux);
    if (nr_tranzactii_aux > 0) {
        tranzactie* istoric_aux = new tranzactie[nr_tranzactii_aux];
        for (int i = 0; i < nr_tranzactii_aux; ++i)
            in>>istoric_aux[i];
        // Dezalocarea memoriei se face in setter!
        c.setIstoric(istoric_aux, nr_tranzactii_aux);
    }
    return in;
}

cont& cont::operator+=(const tranzactie& t) {
    tranzactie* aux = new tranzactie[this->nr_tranzactii + 1];
    for(int i = 0; i < this->nr_tranzactii; ++i)
        aux[i] = this->istoric[i];
    tranzactie a_t(t);
    aux[this->nr_tranzactii] = a_t;
    if (this->istoric)
        delete[] this->istoric;
    this->istoric = new tranzactie[this->nr_tranzactii + 1];
    for(int i = 0; i <= this->nr_tranzactii; ++i)
        aux[i] = this->istoric[i];
    this->nr_tranzactii += 1;
    return *this;
}

cont::cont(int id, int id_tit):id_cont(id), id_titular(id_tit) {
    this->sold = 0;
    this->IBAN = "";
    this->nr_carduri = 0;
    this->carduri = NULL;
    this->procent_taxe = 0;
    this->bilant_negativ_lunar = NULL;
    this->bilant_pozitiv_lunar = NULL;
    this->nr_tranzactii = 0;
    this->istoric = NULL;
}

cont::cont(int id_tit):id_cont(contor_id_cont++), id_titular(id_tit) {
    this->sold = 0;
    this->IBAN = "";
    this->nr_carduri = 0;
    this->carduri = NULL;
    this->procent_taxe = 0;
    this->bilant_negativ_lunar = NULL;
    this->bilant_pozitiv_lunar = NULL;
    this->nr_tranzactii = 0;
    this->istoric = NULL;
}

cont::cont(const cont& c):id_cont(c.id_cont), id_titular(c.id_titular) {
    this->sold = c.sold;
    this->IBAN = c.IBAN;
    this->nr_carduri = c.nr_carduri;
    if (this->carduri)
        delete []this->carduri;
    this->carduri = new std::string[c.nr_carduri];
    for (int i = 0; i < c.nr_carduri; ++i)
        this->carduri[i] = c.carduri[i];
    this->procent_taxe = c.procent_taxe;
    if (this->bilant_negativ_lunar)
        delete []this->bilant_negativ_lunar;
    this->bilant_negativ_lunar = new float[12];
    for (int i = 0; i < 12; ++i)
        this->bilant_negativ_lunar[i] = c.bilant_negativ_lunar[i];
    if (this->bilant_pozitiv_lunar)
        delete []this->bilant_pozitiv_lunar;
    this->bilant_pozitiv_lunar = new float[12];
    for (int i = 0; i < 12; ++i)
        this->bilant_pozitiv_lunar[i] = c.bilant_pozitiv_lunar[i];
    this->nr_tranzactii = c.nr_tranzactii;
    if (this->istoric)
        delete []this->istoric;
    this->istoric = new tranzactie[c.nr_tranzactii];
    for (int i = 0; i < c.nr_tranzactii; ++i)
        this->istoric[i] = c.istoric[i];
}

cont::cont(double a_sold, std::string a_IBAN, int a_nr_carduri, std::string* a_carduri, float a_procent_dobanda,
           int a_nr_luni, float* a_bilant_negativ_lunar, float* a_bilant_pozitiv_lunar,
           int a_tranz, tranzactie* t, int tit):id_cont(contor_id_cont++), id_titular(tit) {
    this->sold = a_sold;
    this->IBAN = a_IBAN;
    this->nr_carduri = a_nr_carduri;
    if (this->nr_carduri == 0)
        this->carduri = NULL;
    else {
        this->carduri = new std::string [nr_carduri];
        for(int i = 0; i < nr_carduri; ++i)
            this->carduri[i] = a_carduri[i];
    }
    this->procent_taxe = a_procent_dobanda;
    if(a_nr_luni == 0) {
        this->bilant_negativ_lunar = NULL;
        this->bilant_pozitiv_lunar = NULL;
    }
    else {
        this->bilant_pozitiv_lunar = new float[a_nr_luni];
        this->bilant_negativ_lunar = new float[a_nr_luni];
        for(int i = 0; i < a_nr_luni; ++i) {
            this->bilant_negativ_lunar[i] = a_bilant_negativ_lunar[i];
            this->bilant_pozitiv_lunar[i] = a_bilant_pozitiv_lunar[i];
        }
    }
    this->nr_tranzactii = a_tranz;
    if (this->nr_tranzactii == 0)
        this->istoric = NULL;
    else {
        this->istoric = new tranzactie[this->nr_tranzactii];
        for(int i = 0; i < this->nr_tranzactii; ++i)
            this->istoric[i] = t[i];
    }
}

cont::cont(double m, std::string ban, int tit):id_cont(contor_id_cont++), id_titular(tit) {
    this->sold = m;
    this->IBAN = ban;
    this->nr_carduri = 0;
    this->carduri = NULL;
    this->procent_taxe = 0;
    this->bilant_negativ_lunar = NULL;
    this->bilant_pozitiv_lunar = NULL;
    this->nr_tranzactii = 0;
    this->istoric = NULL;
}

cont::cont():id_cont(contor_id_cont++) {
    this->id_titular = 0;
    this->sold = 0;
    this->IBAN = "-";
    this->nr_carduri = 0;
    this->carduri = NULL;
    this->procent_taxe = 0;
    this->bilant_negativ_lunar = NULL;
    this->bilant_pozitiv_lunar = NULL;
    this->nr_tranzactii = 0;
    this->istoric = NULL;
}

cont::~cont() {
    if (this->bilant_negativ_lunar != NULL)
        delete []bilant_negativ_lunar;
    if (this->bilant_pozitiv_lunar != NULL)
        delete []bilant_pozitiv_lunar;
    if (this->carduri != NULL)
        delete []carduri;
    if (this->istoric != NULL)
        delete []istoric;
}

double cont::getSold() const {
    return this->sold;
}

std::string cont::getIBAN() const {
    return this->IBAN;
}

int cont::getId_titular() const {
    return this->id_titular;
}

int cont::getId_cont() const {
    return this->id_cont;
}

int cont::getNr_tranzactii() const {
    return this->nr_tranzactii;
}

std::string* cont::getCarduri() const {
    return this->carduri;
}

void cont::setSold(double s) {
    this->sold = s;
}

void cont::setIBAN(std::string i) {
    this->IBAN = i;
}

void cont::setNr_carduri(int n) {
    this->nr_carduri = n;
}

void cont::setCarduri(std::string* s, int n) {
    /// Dezalocarea memoriei care este necesara la operator>>
    if (this->carduri)
        delete[] this->carduri;
    this->carduri = new std::string[n]; /// alocare noua
    this->setNr_carduri(n);
    for (int i = 0; i < n; ++i)
        this->carduri[i] = s[i];
}

void cont::setProcent_taxe(float t) {
    this->procent_taxe = t;
}

void cont::setNr_tranzactii(int n) {
    this->nr_tranzactii = n;
}

void cont::setIstoric(tranzactie* t, int n) {
    // Dezalocarea memoriei care este necesara la operator>>
    if (this->istoric)
        delete[] this->istoric;
    this->istoric = new tranzactie[n]; // Alocare noua
    this->setNr_tranzactii(n);
    for (int i = 0; i < n; ++i)
        istoric[i] = t[i];
}

void cont::setId_titular(int id) {
    this->id_titular = id;
}

void cont::soldAdd(double s) {
    this->sold += s - s * this->procent_taxe;
}
void cont::soldTake(double s) {
    this->sold -= s;
    this->sold -= s * this->procent_taxe;
}

void cont::modifyBalance(const tranzactie& t) {
    if(t.isCredit() || t.isDepunere())
        this->soldAdd(t.getSuma());
    if (t.isRetragere())
        this->soldTake(t.getSuma());
}

void cont::checkAppendtranzactii(tranzactie* t, int nr) {
    for(int i = 0; i < nr; ++i) {
        if(t[i].getTrimite() == this->IBAN || t[i].getPrimeste() == this->IBAN) {
            this->appendtranzactie(t[i]);
            this->modifyBalance(t[i]);
        }
    }
}

void cont::appendtranzactie(const tranzactie& t) {
    tranzactie* aux = new tranzactie[this->nr_tranzactii + 1];
    for(int i = 0; i < nr_tranzactii; ++i)
        aux[i] = this->istoric[i];
    tranzactie a_t(t);
    aux[this->nr_tranzactii] = a_t;
    if (this->istoric)
        delete[] this->istoric;
    this->istoric = new tranzactie[this->nr_tranzactii + 1];
    for (int i = 0; i <= nr_tranzactii; ++i)
        this->istoric[i] = aux[i];
    this->nr_tranzactii += 1;
    this->modifyBalance(a_t);
}

void cont::checkIstoric() {
    for (int i = 0; i < this->nr_tranzactii; ++i)
        this->modifyBalance(this->istoric[i]);
}

double cont::nouTranzactie() {
    tranzactie t;
    std::cin>>t;
    this->appendtranzactie(t);
    if (t.isRetragere())
        return -t.getSuma();
    if (t.isCredit() || t.isDepunere())
        return t.getSuma();
    return 0;
}