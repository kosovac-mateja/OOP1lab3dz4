#include "privilegovani.h"
#include "greske.h"

void Privilegovani::ispis(ostream &os) const {
    os << "(" << minVrednost << ")";
}

void Privilegovani::prikljuciIgraca(const Igrac &i, int pozicija) {
    if (i.getVrednost() < minVrednost) throw GMinimalnaVrednost();
    Tim::prikljuciIgraca(i, pozicija);
}

Privilegovani::Privilegovani(const Privilegovani &t) : Tim(t), minVrednost(t.minVrednost) {}

Privilegovani::Privilegovani(Privilegovani &&t) : Tim(t), minVrednost(t.minVrednost) {}


