#ifndef GWINDOW_H
#define GWINDOW_H

#include "GL/freeglut.h"
#include "gapplication.h"
#include "gdisplayMode.h"

class GWindow{

    public:

        GWindow(const char* title, GDisplayMode displayMode = GDisplayMode()){
            if(!GApplication::initialized()){
                GApplication::die("You must call GApplication::initialize(int* argc, char* argv[]) before creating a GWindow.");
            }
            GApplication::displayMode(displayMode);
            glutCreateWindow(title);
        }

        void show(){
            glutMainLoop();
        }

};

#endif
