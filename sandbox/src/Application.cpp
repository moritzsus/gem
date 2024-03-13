#include <gem.h>

int main()
{
    gem::Matrix4 v1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);
    gem::Matrix4 v2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);
    gem::Matrix4 v3(1.f, -2.f, -4.f, 2.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);
    gem::Matrix4 v4(-1.f, -2.f, -3.f, -4.f, -5.f, -6.f, -7.f, -8.f, -9.f, -10.f, -11.f, -12.f, -13.f, -14.f, -15.f, -16.f);
    
    std::cout << std::boolalpha;
    std::cout << (v1 == v2) << std::endl;
    std::cout << (v2 == v1) << std::endl;
    std::cout << (v1 == v3) << std::endl;
    std::cout << (v2 == v3) << std::endl;
    std::cout << (v2 == -v4) << std::endl;
}