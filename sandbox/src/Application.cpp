#include <gem.h>

int main()
{
    gem::Vector3 v1(1, 2, 0);
    gem::Vector3 v2(3, -1, 0);

    gem::Vector3 r = v1.Cross(v2);

    std::cout << r << std::endl;
}