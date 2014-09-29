#ifndef GCOLOR_H
#define GCOLOR_H

template<typename T>
class GColor{

    public:

        GColor(T red, T green, T blue, T alpha):
            m_red(red),
            m_green(green),
            m_blue(blue),
            m_alpha(alpha)
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

        T alpha(){
            return m_alpha;
        }

    private:

        T m_red;
        T m_green;
        T m_blue;
        T m_alpha;

};

#endif
