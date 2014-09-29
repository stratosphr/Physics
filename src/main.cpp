#include <iostream>
#include "gvector.h"
#include "gwindow.h"

using namespace std;
using namespace gvector;

void displayFunction(GWindow* w){
    w->clear();
}

void closeFunction(GWindow* w){
    w->clearColor(GColor<float>(0.5, 0, 0, 0));
    w->clear();
}

int main(int argc, char* argv[]){

    GApplication::initialize(&argc, argv);
    GWindow* w = GWindow::singleton("Hello World");

    w->clearColor(GColor<float>(0, 0, 0, 0));
    w->displayFunction(displayFunction);
    w->closeFunction(closeFunction);

    w->open();

    return 0;
}
