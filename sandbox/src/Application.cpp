#include <gem.h>

int main()
{
    gem::Vector4 v1(1, 2, 3, 4);
    gem::Vector4 v2(5, 6, 7, 8);
    gem::Vector4 v3(9, 10, 11, 12);
    gem::Vector4 v4(13, 14, 15, 16);

    gem::Matrix4 m(v1, v2, v3, v4);

    std::cout << m[0] << " --- " << m[1] << " --- " << m[2] << " --- " << m[3] << std::endl;
}