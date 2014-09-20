#include <iostream>
#include <vector>

namespace gvector{

    void endvector(){
    }

    template<typename T>
        class GVector{

            public:

                GVector(){
                }

                ~GVector(){
                }

                T operator[](const unsigned int index) const{
                    return m_values[index];
                }

                GVector& operator<<(const T& value){
                    m_values.push_back(value);
                    return *this;
                }

                GVector& operator<<(void(&endvector)()){
                    endvector(); // Suppress "unused parameter" warning
                    return *this;
                }

                T operator*(const GVector& vector2) const{
                    T result = 0;
                    if(m_values.size() == vector2.size()){
                        for(unsigned int i=0; i<m_values.size(); i++){
                            result += m_values[i] * vector2[i];
                        }
                    }
                    return result;
                }

                template<typename T2> GVector operator*(const T2& coefficient) const{
                    GVector result;
                    for(unsigned int i=0; i<m_values.size(); i++){
                        result << m_values[i] * coefficient;
                    }
                    result << endvector;
                    return result;
                }

                template<typename T3, typename T4>
                    friend GVector<T4> operator*(const T3& coefficient, const GVector<T4>& vector){
                        return vector * coefficient;
                    }

                template<typename T2> GVector operator/(const T2& divider) const{
                    GVector result;
                    for(unsigned int i=0; i<m_values.size(); i++){
                        result << m_values[i] / divider;
                    }
                    result << endvector;
                    return result;
                }

                GVector operator^(const GVector& vector2){
                    GVector result;
                    if(m_values.size() == 3 && vector2.size() == 3){
                        result << (m_values[1] * vector2[2]) - (m_values[2] * vector2[1]);
                        result << (m_values[2] * vector2[0]) - (m_values[0] * vector2[2]);
                        result << (m_values[0] * vector2[1]) - (m_values[1] * vector2[0]);
                    }
                    return result;
                }

                GVector operator-(const GVector& vector2) const{
                    GVector result;
                    if(m_values.size() == vector2.size()){
                        for(unsigned int i=0; i<m_values.size(); i++){
                            result << m_values[i] - vector2[i];
                        }
                        result << endvector;
                    }
                    return result;
                }

                GVector operator+(const GVector& vector2) const{
                    GVector result;
                    if(m_values.size() == vector2.size()){
                        for(unsigned int i=0; i<m_values.size(); i++){
                            result << m_values[i] + vector2[i];
                        }
                        result << endvector;
                    }
                    return result;
                }

                void operator+=(const GVector& vector2){
                    if(m_values.size() == vector2.size()){
                        for(unsigned int i=0; i<m_values.size(); i++){
                            m_values[i] += vector2[i];
                        }
                    }
                }

                void operator-=(const GVector& vector2){
                    if(m_values.size() == vector2.size()){
                        for(unsigned int i=0; i<m_values.size(); i++){
                            m_values[i] -= vector2[i];
                        }
                    }
                }

                void display() const{
                    std::cout << "[";
                    for(unsigned int i=0; i<m_values.size() - 1; i++){
                        std::cout << m_values[i] << ", ";
                    }
                    std::cout << m_values[m_values.size() - 1] << "]";
                }

                unsigned int size() const{
                    return m_values.size();
                }

            private:
                std::vector<T> m_values;

        };

}
