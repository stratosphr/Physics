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

                GVector& operator<<(const T& value){
                    m_values.push_back(value);
                    return *this;
                }

                GVector& operator<<(void(&endvector)()){
                    return *this;
                }

                template<typename T2> GVector operator*(const T2 coefficient) const{
                    GVector result;
                    for(int i=0; i<m_values.size(); i++){
                        result << m_values[i] * coefficient;
                    }
                    result << endvector;
                    return result;
                }

                template<typename T3, typename T4>
                    friend GVector<T4> operator*(T3 coefficient, const GVector<T4>& vector){
                        return vector * coefficient;
                    }

                template<typename T2> GVector operator/(const T2 divider) const{
                    GVector result;
                    for(int i=0; i<m_values.size(); i++){
                        result << m_values[i] / divider;
                    }
                    result << endvector;
                    return result;
                }

                T operator[](const int index) const{
                    return m_values[index];
                }

                GVector operator-(const GVector& vector2) const{
                    GVector result;
                    if(m_values.size() == vector2.size()){
                        for(int i=0; i<m_values.size(); i++){
                            result << m_values[i] - vector2[i];
                        }
                        result << endvector;
                    }
                    return result;
                }

                GVector operator+(const GVector& vector2) const{
                    GVector result;
                    if(m_values.size() == vector2.size()){
                        for(int i=0; i<m_values.size(); i++){
                            result << m_values[i] + vector2[i];
                        }
                        result << endvector;
                    }
                    return result;
                }

                void operator+=(const GVector& vector2){
                    if(m_values.size() == vector2.size()){
                        for(int i=0; i<m_values.size(); i++){
                            m_values[i] += vector2[i];
                        }
                    }
                }

                void operator-=(const GVector& vector2){
                    if(m_values.size() == vector2.size()){
                        for(int i=0; i<m_values.size(); i++){
                            m_values[i] -= vector2[i];
                        }
                    }
                }

                void display() const{
                    std::cout << "[";
                    for(int i=0; i<m_values.size() - 1; i++){
                        std::cout << m_values[i] << ", ";
                    }
                    std::cout << m_values[m_values.size() - 1] << "]";
                }

                int size() const{
                    return m_values.size();
                }

            private:
                std::vector<T> m_values;

        };

}
