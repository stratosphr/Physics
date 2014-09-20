#include <iostream>
#include "gvector.h"

using namespace std;
using namespace gvector;

int main(void){

    GVector<float> v1, v2, v3;
    v1 << 5 << -2 << 0 << endvector;
    v2 << 7 << -6 << 0 << endvector;
    v1.display();
    v2.display();
    int v = v1 * v2;
    std::cout << v << std::endl;

    return 0;
}
