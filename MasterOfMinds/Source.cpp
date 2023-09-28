#include <random>
#include <iostream>
#include <string>
#include <ctime>

int getRandomNumber_0_5()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 5); // distribution in range [1, 6]
    dist6(rng);

    srand(time(0));
    return (rand() % 5 + 0);
}

void OutputOpeningMenu()
{
    std::cout << "The computer has choosen six colors with the corresponding numbers:\n";
    std::cout << "(0) red\n(1) blue\n(2) green\n(3) yellow\n(4) orange\n(5) black\n";
    std::cout << "----------------------------------------------------------------------\n";
    std::cout << "in six different elements of the following array\n";
    std::cout << "[***element 1***]\n[***element 2***]\n[***element 3***]\n[***element 4***]\n[***element 5***]\n[***element 6***]\n";
    std::cout << "----------------------------------------------------------------------\n";
    std::cout << "You must figure out which colors are in which elements\n";
    std::cout << "----------------------------------------------------------------------\n";
}

void OutputComputersColors(bool playerGuesses[], std::string ColorsComputer[], int ComputerColorsSize)
{
    std::cout << "----------Computer's Array-------------\n";
    for (int i = 0; i < ComputerColorsSize; i++)
    {
        if (playerGuesses[i])
        {
            std::cout << "[***" << ColorsComputer[i] << "***]\n";
        }
        else
        {
            std::cout << "[***element " << i << "***]\n";

        }
        if (i == ComputerColorsSize - 1)
            std::cout << "\n";
    }
}

int main()
{
    //------------------------Variables--------------------------
    bool playGame = false;
    int playerGuessElement = 0;
    int playerGuessColor = 0;

    //-----------------------Initialize Arrays-------------------
    const int ComputerColorsSize = 6;
    std::string Colors[] = { "red", "blue", "green", "yellow", "orange", "black" };
    std::string ColorsComputer[ComputerColorsSize];
    int ColorsComputerIndeces[ComputerColorsSize];
    int sumOfColorsIndeces = 0;
    bool playerGuesses[ComputerColorsSize] = {false, false, false, false, false, false};

    for (int i = 0; i < ComputerColorsSize; i++)
    {
        int randomColorIndex = getRandomNumber_0_5();
        ColorsComputerIndeces[i] = randomColorIndex;
        ColorsComputer[i] = Colors[randomColorIndex];
    }

    //----------------------Main Menu    std::cout << "************************************************************************\n"
    std::cout << "************************************************************************\n";
    std::cout << "-------------------Welcome to Master of Minds---------------------------\n";
    std::cout << "************************************************************************\n";
    OutputOpeningMenu();
    std::cout << "Are you ready to play? (1 for yes, 0 for no) ";
    std::cin >> playGame;

    //----------------------Start Game---------------------------
    while (playGame)
    {
        std::cout << "----------------------------------------------------------------------\n";
        std::cout << "First element hint (-1 point): ";
        std::cout << "10 - element #1 = " << 10 - ColorsComputerIndeces[0] << std::endl;
        std::cout << "----------------------------------------------------------------------\n";
        std::cout << "Enter your guess: ";
        std::cin >> playerGuessColor;

        if (playerGuessColor == ColorsComputerIndeces[0])
        {
            std::cout << "\n**********\nCorrect!\n**********\n\n";
            playerGuesses[0] = true;
            OutputComputersColors(playerGuesses, ColorsComputer, ComputerColorsSize);
        }
        else
        {
            std::cout << "\n**********\nIncorrect, try again\n**********\n\n";
        }
    }

}