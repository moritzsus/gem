#include <gem.h>

int main()
{
    gem::Matrix4 m1(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f);
    gem::Matrix4 m2(1.f, 2.f, -1.f, 2.f, -3.0f, 0.5f, 2.f, 1.f, 1.f, 3.f, 5.f, 24.f, 7.f, -2.f, 0.f, -1.f);
    gem::Matrix4 m3(1.f, 2.f, 1.f, 0.f, -3.0f, 0.f, 2.f, 0.f, 1.f, -4.f, 9.f, 0.f, 6.f, 6.f, 6.f, 0.f);

    std::cout << "M1:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << m1[i] << std::endl;
    }
    std::cout << "M2:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << m2[i] << std::endl;
    }
    std::cout << "M3:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << m3[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    gem::Matrix4 mi1 = m1.Transpose();
    gem::Matrix4 mi2 = m2.Transpose();
    gem::Matrix4 mi3 = m3.Transpose();

    std::cout << "MI1:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << mi1[i] << std::endl;
    }
    std::cout << "MI2:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << mi2[i] << std::endl;
    }
    std::cout << "MI3:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << mi3[i] << std::endl;
    }
}