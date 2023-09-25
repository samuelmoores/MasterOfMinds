#include <random>
#include <iostream>
#include <string>

int getRandomNumber_1_6()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 6); // distribution in range [1, 6]

    return dist6(rng);
}

int main()
{
    const int size = 6;
    std::string Colors[] = {"red", "blue", "green", "yellow", "orange", "black"};

    int randomColorIndex = getRandomNumber_1_6();

    //output random color with random number
    std::cout << Colors[randomColorIndex] << std::endl;


}