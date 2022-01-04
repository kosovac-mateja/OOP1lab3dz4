#ifndef _igrac_h_
#define _igrac_h_

#include <iostream>

using namespace std;

class Igrac {
    string ime;

    int vrednost;
public:
    Igrac(string name = "", int val = 1000) : ime(name), vrednost(val) {}

    void promenaVrednosti(double procenat);

    friend bool operator==(const Igrac &i1, const Igrac &i2);

    friend bool operator!=(const Igrac &i1, const Igrac &i2);

    friend ostream &operator<<(ostream &os, const Igrac &i);

    int getVrednost() const;

    const string &getIme() const;

};


#endif
