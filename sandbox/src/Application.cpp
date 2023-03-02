#include <gem.h>

int main()
{
    gem::Vector2 v2(1, 2);
    gem::Vector3 v3(v2, 9);
    gem::Vector4 v4(v3, 24);

    std::cout << v3 << std::endl;
    std::cout << v4 << std::endl;
}