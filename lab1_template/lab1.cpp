// #include <iostream>
// using namespace std;
// int main()
// {
//     int width, height; // Define 2 variables that will hold the width and height respectively

//     cout << "Please input the width of the rectangle: ";
//     cin >> width;
//     cout << "Please input the height of the rectangle: ";
//     cin >> height;

//     // TODO: complete your program here

//     return 0;
// }

#include <iostream>

int main()
{
    int width, height;

    std::cout << "Please input the width of the rectangle: ";
    std::cin >> width;
    std::cout << "Please input the height of the rectangle: ";
    std::cin >> height;

    if (height <= 0 || width <= 0)
    {
        std::cout << "Error: the width and height must be positive!" << std::endl;
    }
    else
    {
        std::cout << "The perimeter of the rectangle is " << (width + height) * 2 << std::endl;
    }

    return 0;
}