#ifndef GSHAPE3D_H
#define GSHAPE3D_H

#include <vector>

template<typename T>
class GShape3D{

    public:

        GShape3D(std::vector< GVertex3D<T> > vertices): m_vertices(vertices){
            std::cout << "hello" << std::endl;
        }

    private:
        std::vector< GVertex3D<T> > m_vertices;

};

#endif
