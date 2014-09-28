#ifndef GWINDOW_H
#define GWINDOW_H

#include "GL/freeglut.h"
#include "gapplication.h"
#include "gdisplayMode.h"
#include "gposition2d.h"
#include "gdimension2d.h"
#include "gcolor.h"
#include "gdrawable.h"

class GWindow{

    public:

        static GWindow* singleton(const char* title, GPosition2D<int> position = GPosition2D<int>(), GDimension2D<int> dimension = GDimension2D<int>(), GDisplayMode displayMode = GDisplayMode()){
            if(m_singleton == NULL){
                m_singleton = new GWindow(title, position, dimension, displayMode);
            }
            return m_singleton;
        }

        template<typename T> void clearColor(GColor<T> color){
            glClearColor(color.red(), color.green(), color.blue(), 1);
        }

        void clear() const{
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glutSwapBuffers();
            glFlush();
        }

        static void staticDisplayFunction(){
            GWindow::m_displayFunction(m_singleton);
        }

        void displayFunction(void (*displayFunction)(GWindow*)){
            GWindow::m_displayFunction = displayFunction;
            glutDisplayFunc(GWindow::staticDisplayFunction);
        }

        void show() const{
            glutMainLoop();
        }

    private:

        GWindow(const char* title, GPosition2D<int> position = GPosition2D<int>(), GDimension2D<int> dimensions = GDimension2D<int>(), GDisplayMode displayMode = GDisplayMode()){
            if(!GApplication::initialized()){
                GApplication::die("You must call GApplication::initialize(int* argc, char* argv[]) before creating a GWindow.");
            }
            glutInitWindowPosition(position.x(), position.y());
            glutInitWindowSize(dimensions.width(), dimensions.height());
            GApplication::displayMode(displayMode);
            glutCreateWindow(title);
        }

        static GWindow* m_singleton;
        static void (*m_displayFunction)(GWindow*);

};

#endif

void (*GWindow::m_displayFunction)(GWindow*) = NULL;
GWindow* GWindow::m_singleton = NULL;
