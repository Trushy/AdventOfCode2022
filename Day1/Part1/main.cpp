#include <fstream>
#include <iostream>
using namespace std;

int main(int ac, char **av)
{
    std::string line;
    std::ifstream myfile(av[1]);

    int index = 1;
    int maxCalories = 0;

    int calculatedCalories = 0;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (line.size() <= 1) {
                if (calculatedCalories > maxCalories) {
                    maxCalories = calculatedCalories;
                }
                calculatedCalories = 0;
            } else {
                calculatedCalories += stoi(line);
            }
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    std::cout << "Max calories: " << maxCalories << std::endl;

    return 0;
}