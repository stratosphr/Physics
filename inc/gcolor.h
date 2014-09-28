#ifndef GCOLOR_H
#define GCOLOR_H

template<typename T>
class GColor{

    public:

        GColor(T red, T green, T blue):
            m_red(red),
            m_green(green),
            m_blue(blue)
    {
    }

        T red(){
            return m_red;
        }

        T green(){
            return m_green;
        }

        T blue(){
            return m_blue;
        }

    private:

        T m_red;
        T m_green;
        T m_blue;

};

#endif
