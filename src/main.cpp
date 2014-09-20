#include <iostream>
#include "gvector.h"

using namespace std;
using namespace gvector;

int main(void){

    GVector<float> v1, v2, v3;
    v1 << 1 << 2 << 3 << endvector;
    v2 << 3 << 2 << 1 << endvector;
    v1.display();
    v2.display();
    v3 = 3.4 * v1;
    v3.display();

    return 0;
}
