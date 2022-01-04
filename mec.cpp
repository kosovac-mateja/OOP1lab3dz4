#include "mec.h"
#include "greske.h"

const Par<Tim> &Mec::getPar() const {
    return par;
}

void Mec::odigraj() {
    if (par.getPtr1()->vrednostTima() > par.getPtr2()->vrednostTima()) {
        ishod = POBEDA_DOMACIN;

        for (int i = 0; i < par.getPtr1()->getBrIgraca(); i++)
            par.getPtr1()->operator[](i).promenaVrednosti(10);

        for (int i = 0; i < par.getPtr2()->getBrIgraca(); i++)
            par.getPtr2()->operator[](i).promenaVrednosti(-10);
    } else if (par.getPtr1()->vrednostTima() < par.getPtr2()->vrednostTima()) {
        ishod = POBEDA_GOST;

        for (int i = 0; i < par.getPtr1()->getBrIgraca(); i++)
            par.getPtr1()->operator[](i).promenaVrednosti(-10);

        /*for (int i = 0; i < par.getPtr2()->getBrIgraca(); i++)
            par.getPtr2()->operator[](i).promenaVrednosti(10);*/
    } else
        ishod = NERESENO;

    odigrano = 1;
}

bool Mec::getOdigrano() const {
    return odigrano;
}

Par<int> Mec::getPoeni() const {
    if (!getOdigrano()) throw GNijeOdigrano();

    int d = 1, g = 1;

    if (ishod == POBEDA_DOMACIN)
        d = 3, g = 0;
    else if (ishod == POBEDA_GOST)
        d = 0, g = 3;

    Par<int> p;

    p.setPtr1(&d);

    p.setPtr2(&g);

    return p;
}

ostream &operator<<(ostream &os, const Mec &m) {
    os << m.par << endl;

    if (m.getOdigrano()) {
        switch (m.ishod) {
            case 0:
                os << "Pobeda domacina";
                break;
            case 1:
                os << "Nereseno";
                break;
            case 2:
                os << "Pobeda gostiju";
                break;
        }

    }

    return os;
}


