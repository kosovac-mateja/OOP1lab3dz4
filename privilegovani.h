#ifndef _privilegovani_h_
#define _privilegovani_h_

#include "tim.h"


class Privilegovani : public Tim {
    int minVrednost;

    void ispis(ostream &os) const override;

public:
    Privilegovani(string name, int cap, int min) : Tim(name, cap), minVrednost(min) {}

    Privilegovani(const Privilegovani &t);

    Privilegovani(Privilegovani &&t);

    void prikljuciIgraca(const Igrac &i, int pozicija) override;
};


#endif
