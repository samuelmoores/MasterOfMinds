#include <random>
#include <iostream>

int getRandomNumber_1_6()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 6); // distribution in range [1, 6]

    return dist6(rng);
}

int main()
{
    std::cout << getRandomNumber_1_6() << std::endl;

}