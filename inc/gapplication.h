#ifndef GAPPLICATION_H
#define GAPPLICATION_H

#include <iostream>
#include "GL/freeglut.h"
#include "gdisplayMode.h"

class GApplication{

    public:

        GApplication(){
        }

        static void initialize(int* argc, char* argv[]){
            glutInit(argc, argv);
            m_initialized = true;
        }

        static void displayMode(GDisplayMode displayMode){
            glutInitDisplayMode(displayMode.displayMode());
        }

        static bool initialized(){
            return m_initialized;
        }

        static void die(const char* error){
            std::cerr << "GError : " << error << std::endl;
            exit(1);
        }

    private:

        static bool m_initialized;

};

bool GApplication::m_initialized = false;

#endif
