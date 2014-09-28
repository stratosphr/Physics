#ifndef GWINDOW_H
#define GWINDOW_H

#include "GL/freeglut.h"
#include "gapplication.h"
#include "gdisplayMode.h"
#include "gposition2d.h"
#include "gdimension2d.h"

class GWindow{

    public:

        GWindow(const char* title, GPosition2D<int> position = GPosition2D<int>(), GDimension2D<int> dimensions = GDimension2D<int>(), GDisplayMode displayMode = GDisplayMode()){
            if(!GApplication::initialized()){
                GApplication::die("You must call GApplication::initialize(int* argc, char* argv[]) before creating a GWindow.");
            }
            glutInitWindowPosition(position.x(), position.y());
            glutInitWindowSize(dimensions.width(), dimensions.height());
            GApplication::displayMode(displayMode);
            glutCreateWindow(title);
        }

        void show(){
            glutMainLoop();
        }

};

#endif
