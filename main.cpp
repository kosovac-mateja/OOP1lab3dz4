#include <iostream>
#include "igrac.h"
#include "tim.h"
#include "privilegovani.h"
#include "par.h"
#include "mec.h"

int main() {
    try {
        Igrac lbj("LeBron", 1200);
        Igrac wb("Westbrook", 100);
        Igrac ad("Davis", 800);
        Igrac melo("Carmelo", 400);
        Igrac monk("Monk", 302);

        Privilegovani lal("Lakers", 6, 90);

        lal.prikljuciIgraca(lbj, 2);
        lal.prikljuciIgraca(wb, 0);
        lal.prikljuciIgraca(ad, 4);
        lal.prikljuciIgraca(melo, 3);
        lal.prikljuciIgraca(monk, 1);

        Privilegovani lac(lal);

        lal.prikljuciIgraca(wb, 5);

        Par<Tim> par;
        par.setPtr1(&lal);
        par.setPtr2(&lac);

        Mec m(par);
        m.odigraj();

        cout << m;
    }

    catch (exception e) {}
}
