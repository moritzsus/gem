#include <gem.h>

int main()
{
    gem::Vector4 v4(24, 7, 19, 99);
    gem::Vector3 v3(24, 7, 19);
    gem::Vector3 res;

    res = v3 + static_cast<gem::Vector3>(v4);

    std::cout << res << std::endl;
}