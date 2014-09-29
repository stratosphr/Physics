#ifndef GWINDOW_H
#define GWINDOW_H

#include <iostream>
#include "GL/freeglut.h"
#include "gapplication.h"
#include "gdisplayMode.h"
#include "gposition2d.h"
#include "gdimension2d.h"
#include "gcolor.h"
#include "gdrawable.h"

class GWindow{

    public:

        static GWindow* singleton(const char* title = "Title", GPosition2D<int> position = GPosition2D<int>(), GDimension2D<int> dimension = GDimension2D<int>(), GDisplayMode displayMode = GDisplayMode()){
            if(m_singleton == NULL){
                m_singleton = new GWindow(title, position, dimension, displayMode);
            }
            return m_singleton;
        }

        template<typename T> void clearColor(GColor<T> color) const{
            glClearColor(color.red(), color.green(), color.blue(), color.alpha());
        }

        void clear() const{
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glutSwapBuffers();
            glFlush();
        }

        static void staticDisplayFunction(){
            GWindow::m_displayFunction(m_singleton);
        }

        void displayFunction(void (*displayFunction)(GWindow*)) const{
            GWindow::m_displayFunction = displayFunction;
            glutDisplayFunc(GWindow::staticDisplayFunction);
        }

        void open() const{
            if(GWindow::m_displayFunction == NULL){
                GApplication::die("You must call GWindow::displayFunction(void (*displayFunction)(GWindow*)) and specify a display function before calling GWindow::open().");
            }else{
                glutMainLoop();
            }
        }

        static void staticCloseFunction(){
            GWindow::m_closeFunction(m_singleton);
            if(GWindow::m_singleton != NULL){
                delete GWindow::m_singleton;
                GWindow::m_singleton = NULL;
            }
        }

        void closeFunction(void (*closeFunction)(GWindow*)) const{
            GWindow::m_closeFunction = closeFunction;
            glutCloseFunc(GWindow::staticCloseFunction);
        }

        void close() const{
            GWindow::staticCloseFunction();
        }

        static void defaultReshapeFunction(GWindow* window, GDimension2D<int> dimensions){
            window->clear();
            if(dimensions.height() == 0){
                dimensions.height(1);
            }
            float ratio = 1.0 * dimensions.width() / dimensions.height();
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glViewport(0, 0, dimensions.width(), dimensions.height());
            gluPerspective(45, ratio, 0, 1000);
            glMatrixMode(GL_MODELVIEW);
        }

        static void staticReshapeFunction(int width, int height){
            GWindow::m_reshapeFunction(m_singleton, GDimension2D<int>(width, height));
        }

        void reshapeFunction(void (*reshapeFunction)(GWindow*, GDimension2D<int>)){
            GWindow::m_reshapeFunction = reshapeFunction;
            glutReshapeFunc(GWindow::staticReshapeFunction);
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
        static void (*m_closeFunction)(GWindow*);
        static void (*m_reshapeFunction)(GWindow*, GDimension2D<int>);

};

#endif

GWindow* GWindow::m_singleton = NULL;
void (*GWindow::m_displayFunction)(GWindow*) = NULL;
void (*GWindow::m_closeFunction)(GWindow*) = NULL;
void (*GWindow::m_reshapeFunction)(GWindow*, GDimension2D<int>) = NULL;
