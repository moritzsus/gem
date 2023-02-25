#include <gem.h>

int main()
{
    gem::Vector2 v1(2, 4);
    gem::Vector3 v3(1, 2, 3);
    gem::Vector4 v4(4, 7, 24, 99);

    gem::Vector4 n = v4.Normalize();
    std::cout << n << std::endl;
    std::cout << n.Magnitude() << std::endl;
}