#include <gem.h>

int main()
{
    Vector2 v2(2, 4);
    Vector3 v3(1, 2, 3);
    Vector4 v4(4, 7, 24, 99);

    Vector4 n = v4.Normalize();
    std::cout << n << std::endl;
    std::cout << n.Magnitude() << std::endl;
}