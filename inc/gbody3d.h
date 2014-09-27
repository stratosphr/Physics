#ifndef GBODY3D_H
#define GBODY3D_H

#include "gvertex3d.h"
#include "gshape3d.h"

template<typename T>
class GBody3D{

    public:
        
        GBody3D(GShape3D<T> shape): m_shape(shape){
        }

    private:
        GShape3D<T> m_shape;

};

#endif
