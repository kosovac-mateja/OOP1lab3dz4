#include "tim.h"

void Tim::brisi() {
    delete[] tim;

    tim = nullptr;
}

void Tim::kopiraj(const Tim &t) {
    naziv = t.naziv;

    tim = new Igrac[kap = t.kap];

    br = t.br;

    for (int i = 0; i < br; i++)
        tim[i] = t.tim[i];
}

void Tim::premesti(Tim &t) {
    naziv = t.naziv;

    br = t.br;

    tim = t.tim;

    t.tim = nullptr;
}

Tim::Tim(const Tim &t) {
    kopiraj(t);
}

Tim::Tim(Tim &&t) {
    premesti(t);
}

Tim::~Tim() {
    brisi();
}

Tim &Tim::operator=(const Tim &t) {
    if (this != &t) {
        brisi();
        kopiraj(t);
    }

    return *this;
}

Tim &Tim::operator=(Tim &&t) {
    if (this != &t) {
        brisi();
        premesti(t);
    }

    return *this;
}

void Tim::prikljuciIgraca(const Igrac &i, int pozicija) {
    tim[pozicija] = i;

    br++;
}

int Tim::getBrIgraca() const {
    return br;
}

Igrac Tim::operator[](int index) {
    return tim[index];
}

double Tim::vrednostTima() const {
    double sum = 0;

    for (int i = 0; i < br; i++)
        sum += tim[i].getVrednost();

    return sum / br;
}

bool operator==(Tim &t1, Tim &t2) {
    if (t1.naziv != t2.naziv || t1.kap != t2.kap || t1.br != t2.br) return false;

    for (int i = 0; i < t1.br; i++) {
        if (t1[i] != t2[i])
            return false;
    }

    return true;
}

void Tim::ispis(ostream &os) const {

}

ostream &operator<<(ostream &os, Tim &t) {
    os << t.naziv;

    t.ispis(os);

    os << "[";

    for (int i = 0; i < t.br; i++) {
        os << t[i];

        if (i != t.br - 1)
            os << ",";
    }

    os << "]";

    return os;
}
