#include <gem.h>

int main()
{
    gem::Vector4 v1(1, 2, 1, 2);
    gem::Vector4 v2(3, 4, 3, 4);
    gem::Vector4 v3(5, 6, 5, 6);
    gem::Vector4 v4(7, 8, 7, 8);

    gem::Matrix4 m1(v1, v2, v3, v4);
    gem::Matrix4 m2(10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);

    m2 *= 2;

    std::cout << m2[0] << " --- " << m2[1] << " --- " << m2[2] << " --- " << m2[3] << std::endl;
}