#include "par.h"
#include "tim.h"

template
class Par<int>;

template
class Par<Tim>;

template<typename T>
T *Par<T>::getPtr1() const {
    return ptr1;
}

template<typename T>
void Par<T>::setPtr1(T *ptr1) {
    Par::ptr1 = ptr1;
}

template<typename T>
T *Par<T>::getPtr2() const {
    return ptr2;
}

template<typename T>
void Par<T>::setPtr2(T *ptr2) {
    Par::ptr2 = ptr2;
}


