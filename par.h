#ifndef _par_h_
#define _par_h_

#include <iostream>

using namespace std;

template<typename T>
class Par {
    T *ptr1;
    T *ptr2;
public:
    Par() { ptr1 = ptr2 = nullptr; }

    T *getPtr1() const;

    void setPtr1(T *ptr1);

    T *getPtr2() const;

    void setPtr2(T *ptr2);

    friend ostream &operator<<(ostream &os, const Par &p) {
        return os << "[" << *(p.getPtr1()) << " - " << *(p.getPtr2()) << "]" << endl;
    }
};


#endif
