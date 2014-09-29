#ifndef GPOSITION2D_H
#define GPOSITION2D_H

template<typename T>
class GPosition2D{

    public:

        GPosition2D(T x = -1, T y = -1):
            m_x(x),
            m_y(y)
    {
    }

        T x(){
            return m_x;
        }

        T y(){
            return m_y;
        }

        void x(T x){
            m_x = x;
        }

        void y(T y){
            m_y = y;
        }

    private:

        T m_x;
        T m_y;

};

#endif
