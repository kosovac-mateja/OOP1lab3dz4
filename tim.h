#ifndef _tim_h_
#define _tim_h_

#include "igrac.h"


class Tim {
protected:
    string naziv;

    int kap;

    Igrac *tim;

    int br;

    virtual void ispis(ostream &os) const;

    void brisi();

    void kopiraj(const Tim &t);

    void premesti(Tim &t);

public:
    Tim(string name, int cap) : naziv(name), kap(cap), br(0), tim(new Igrac[cap]) {}

    Tim(const Tim &t);

    Tim(Tim &&t);

    virtual ~Tim();

    Tim &operator=(const Tim &t);

    Tim &operator=(Tim &&t);

    virtual void prikljuciIgraca(const Igrac &i, int pozicija);

    int getBrIgraca() const;

    Igrac operator[](int index);

    double vrednostTima() const;

    friend bool operator==(Tim &t1, Tim &t2);

    friend ostream &operator<<(ostream &os, Tim &t);
};


#endif
