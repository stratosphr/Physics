#ifndef GDISPLAYMODE_H
#define GDISPLAYMODE_H

#include "GL/freeglut.h"

class GDisplayMode{

    public:

        GDisplayMode(int displayMode = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE | GLUT_ALPHA):
            m_displayMode(displayMode)
    {
    }

        int displayMode(){
            return m_displayMode;
        }

    private:

        int m_displayMode;

};

#endif
