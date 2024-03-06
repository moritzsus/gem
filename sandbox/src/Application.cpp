#include <gem.h>

int main()
{
    gem::Matrix4 m(2.f, 0.f, 3.f, -1.f, 1.f, 2.f, 1.f, 4.f, 4.f, -1.f, 0.f, -2.f, -2.f, 3.f, -3.f, 1.f);

    std::cout << m[0] << std::endl;
    std::cout << m[1] << std::endl;
    std::cout << m[2] << std::endl;
    std::cout << m[3] << std::endl;

    float det = m.Det();
    std::cout << det << std::endl;
    float det2 = gem::det(m);
    std::cout << det2 << std::endl;
}