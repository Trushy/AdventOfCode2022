#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int ac, char **av)
{
    std::string line;
    std::ifstream myfile(av[1]);

    int result = 0;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            const string firstElf = line.substr(0, line.find(','));
            const string secondElf = line.substr(line.find(',') + 1, line.length());
            const int firstElfFirstInt = stoi(firstElf.substr(0, firstElf.find('-')));
            const int firstElfSecondInt = stoi(firstElf.substr(firstElf.find('-') + 1, firstElf.length()));
            const int secondElfFirstInt = stoi(secondElf.substr(0, secondElf.find('-')));
            const int secondElfSecondInt = stoi(secondElf.substr(secondElf.find('-') + 1, secondElf.length()));

            if (firstElfFirstInt <= secondElfFirstInt && firstElfSecondInt >= secondElfSecondInt)
                result++;
            else if (secondElfFirstInt <= firstElfFirstInt && secondElfSecondInt >= firstElfSecondInt)
                result++;
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    cout << result << endl;

    return 0;
}