#include <gem.h>

int main()
{
    gem::Vector4 x(1, 2, -1, 1);
    gem::Vector4 v(2, -2, 1, 0);

    std::cout << gem::reject(x, v) << std::endl;
}