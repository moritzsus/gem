#include <gem.h>

int main()
{
    gem::Vector4 v1(4, -1, 3, 2);

    gem::Matrix4 m1(2, 3, 4, -4, 2, 0, 1, -2, 0, 1, 1, 4, -2, -1, 2, 0);
    gem::Matrix4 m2(-3, -6, 2, 0, 1, -6, 2, 1, 2, 0, 0, 1, -1, -2, 2, 4);

    //gem::Vector4 v3 = m1 * v1;
    gem::Matrix4 m3 = m1 * m2;

    std::cout << m3[0] << " --- " << m3[1] << " --- " << m3[2] << " --- " << m3[3] << std::endl;
    //std::cout << v3 << std::endl;
}