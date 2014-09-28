#ifndef GDIMENSION2D_H
#define GDIMENSION2D_H

template<typename T>
class GDimension2D{

    public:

        GDimension2D(double width = -1, double height = -1):
            m_width(width),
            m_height(height)
    {
    }

        T width(){
            return m_width;
        }

        T height(){
            return m_height;
        }

    private:

        T m_width;
        T m_height;

};

#endif
