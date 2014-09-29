#include <iostream>
#include "gvector.h"
#include "gwindow.h"

using namespace std;
using namespace gvector;

void displayFunction(GWindow* w){
    w->clear();
    cout << "Display" << endl;
}

void closeFunction(GWindow* w){
    cout << "Close" << endl;
}

void reshapeFunction(GWindow* w, GDimension2D<int> dimension){
    cout << "Reshape" << endl;
}

int main(int argc, char* argv[]){

    GApplication::initialize(&argc, argv);
    GWindow* w = GWindow::singleton("Hello World");

    w->clearColor(GColor<float>(0, 0, 0, 0));
    w->displayFunction(displayFunction);
    w->closeFunction(closeFunction);
    w->reshapeFunction(reshapeFunction);

    w->open();

    return 0;
}
