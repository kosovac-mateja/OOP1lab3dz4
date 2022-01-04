#ifndef _mec_h_
#define _mec_h_

#include "par.h"
#include "tim.h"


class Mec {
public:
    const Par<Tim> &getPar() const;

private:
    enum Ishod {
        POBEDA_DOMACIN, NERESENO, POBEDA_GOST
    };

    Par<Tim> par;

    Ishod ishod;

    int odigrano;
public:
    Mec(const Par<Tim> &p) : par(p), odigrano(0) {}

    void odigraj();

    bool getOdigrano() const;

    Par<int> getPoeni() const;

    friend ostream &operator<<(ostream &os, const Mec &m);
};


#endif
