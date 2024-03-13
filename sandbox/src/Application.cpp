#include <gem.h>

int main()
{
    const float pi = 3.14159265358f;

    gem::Vector3 ax(1.f, -1.5f, 3.3f);
    ax = ax.Normalize();
    std::cout << ax.Magnitude() << std::endl;

    gem::Vector3 rot(2.f, 3.f, 5.f);

    gem::Matrix3 mRotDeg = gem::makeRotationDeg(90.f, ax);
    gem::Matrix3 mRotRad = gem::makeRotationRad(90.f * (pi / 180.f), ax);

    std::cout << "MatrixDeg:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << mRotDeg[i] << std::endl;
    }
    std::cout << "MatrixRod:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << mRotRad[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << rot << std::endl;

    rot = mRotDeg * rot;
    std::cout << rot << std::endl;

    rot = mRotRad * rot;
    std::cout << rot << std::endl;

    rot = mRotDeg * rot;
    std::cout << rot << std::endl;

    rot = mRotRad * rot;
    std::cout << rot << std::endl;
}