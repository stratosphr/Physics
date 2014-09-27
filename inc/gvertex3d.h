#ifndef GVERTEX3D_H
#define GVERTEX3D_H

template<typename T>
class GVertex3D{

    public:

        GVertex3D(T x, T y, T z): m_x(x), m_y(y), m_z(z){
        }

    private:
        T m_x;
        T m_y;
        T m_z;

};

#endif
