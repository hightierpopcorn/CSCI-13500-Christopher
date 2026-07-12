#include <iostream>

void addFive(int number)
{
    number += 5;
    std::cout << "Inside addFive(): " << number << std::endl;
}

int main()
{
    int value = 10;

    addFive(value);

    std::cout << "In main(): " << value << std::endl;
}