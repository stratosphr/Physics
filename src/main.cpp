#include <iostream>
#include "gvector.h"
#include "gwindow.h"

using namespace std;
using namespace gvector;

void displayFunction(GWindow* w){
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
    GWindow* w = GWindow::singleton("Hello World", GPosition2D<int>(), GDimension2D<int>(500, 500));

    w->clearColor(GColor<float>(0, 0, 0, 0));
    w->displayFunction(displayFunction);
    w->closeFunction(closeFunction);
    w->reshapeFunction(GWindow::defaultReshapeFunction);

    w->open();

    return 0;
}
