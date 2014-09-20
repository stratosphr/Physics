#include <iostream>
#include "gvector.h"
#include "gbody.h"

using namespace std;
using namespace gvector;

int main(void){

    GVector<float> v1, v2, v3;
    v1 << 5 << -2 << 0 << endvector;
    v2 << 5 << -2 << 0 << endvector;
    bool v = (v1 == v2);
    std::cout << v << std::endl;
    std::cout << v1[1] << std::endl;

    GBody body;

    return 0;
}
