#include "igrac.h"

const string &Igrac::getIme() const {
    return ime;
}

int Igrac::getVrednost() const {
    return vrednost;
}

void Igrac::promenaVrednosti(double procenat) {
    vrednost += (int) (procenat / 100 * vrednost);
}

bool operator==(const Igrac &i1, const Igrac &i2) {
    if (i1.vrednost == i2.vrednost && i1.ime == i2.ime) return true;

    return false;
}

bool operator!=(const Igrac &i1, const Igrac &i2) {
    return !(i1 == i2);
}

ostream &operator<<(ostream &os, const Igrac &i) {
    if (i.ime != "")
        os << i.ime << "#" << i.vrednost;
    return os;
}
