#include <iostream>
#include <stdexcept>

// Структура для вычисления объемов геометрических тел
struct VolumeFormulas
{
    static constexpr double PI = 3.14159265358979323846;

    // Объем куба: V = a^3
    static double cubeVolume(double side)
    {
        if (side <= 0)
            throw std::invalid_argument("Длина ребра должна быть больше нуля");
        return side * side * side;
    }

    // Объем шара: V = 4/3 * pi * r^3
    static double sphereVolume(double radius)
    {
        if (radius <= 0)
            throw std::invalid_argument("Радиус должен быть больше нуля");
        return 4.0 / 3.0 * PI * radius * radius * radius;
    }

    // Объем цилиндра: V = pi * r^2 * h
    static double cylinderVolume(double radius, double height)
    {
        if (radius <= 0 || height <= 0)
            throw std::invalid_argument("Радиус и высота должны быть больше нуля");
        return PI * radius * radius * height;
    }

    // Объем конуса: V = 1/3 * pi * r^2 * h
    static double coneVolume(double radius, double height)
    {
        if (radius <= 0 || height <= 0)
            throw std::invalid_argument("Радиус и высота должны быть больше нуля");
        return PI * radius * radius * height / 3.0;
    }
};

#ifndef UNIT_TESTING   // при подключении в проект тестов main не нужен
int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        std::cout << "Объем куба (a = 3): " << VolumeFormulas::cubeVolume(3) << std::endl;
        std::cout << "Объем шара (r = 3): " << VolumeFormulas::sphereVolume(3) << std::endl;
        std::cout << "Объем цилиндра (r = 2, h = 5): " << VolumeFormulas::cylinderVolume(2, 5) << std::endl;
        std::cout << "Объем конуса (r = 3, h = 4): " << VolumeFormulas::coneVolume(3, 4) << std::endl;
        std::cout << "Объем куба (a = -1): " << VolumeFormulas::cubeVolume(-1) << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
#endif
