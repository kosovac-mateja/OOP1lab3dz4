#ifndef _greske_h_
#define _greske_h_

#include <exception>
#include <iostream>

using namespace std;

class GMinimalnaVrednost : public exception {
public:
    GMinimalnaVrednost() : exception() { cout << "Greska: Igrac nema dovoljnu vrednost da bi se prikljucio timu!"; }
};

class GNijeOdigrano : public exception {
public:
    GNijeOdigrano() : exception() { cout << "Greska: Mec jos nije odigran!"; }
};


#endif
