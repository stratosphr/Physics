#include <iostream>
#include "gvector.h"
#include "gwindow.h"

using namespace std;
using namespace gvector;

int main(int argc, char* argv[]){

    GApplication::initialize(&argc, argv);
    GWindow w("Hello World");

    w.show();

    return 0;
}
