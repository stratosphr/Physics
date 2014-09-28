#include <iostream>
#include "gvector.h"
#include "gwindow.h"

using namespace std;
using namespace gvector;

void render(GWindow* w){
    w->clear();
}

int main(int argc, char* argv[]){

    GApplication::initialize(&argc, argv);
    GWindow* w = GWindow::singleton("Hello World");

    w->clearColor(GColor<float>(0, 0, 0));
    w->displayFunction(render);

    w->show();

    return 0;
}
