#include <random>
#include <iostream>
#include <string>

int getRandomNumber_0_5()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 5); // distribution in range [1, 6]

    return dist6(rng);
}

int main()
{
    //------------------------Variables--------------------------
    bool playGame = false;

    //-----------------------Initialize Arrays-------------------
    const int ComputerColorsSize = 6;
    std::string Colors[] = { "red", "blue", "green", "yellow", "orange", "black" };
    std::string ColorsComputer[ComputerColorsSize];

    for (int i = 0; i < ComputerColorsSize; i++)
    {
        int randomColorIndex = getRandomNumber_0_5();
        ColorsComputer[i] = Colors[randomColorIndex];
    }

    std::cout << "Are you ready to play? (0 for yes, 1 for no) ";
    std::cin >> playGame;

    //----------------------Start Game---------------------------
    while (playGame)
    {
        std::cout << "Welcome to Master of Minds\n";
        std::cout << "Enter your guess for the first element of the Computer's Array\n";
    }

}