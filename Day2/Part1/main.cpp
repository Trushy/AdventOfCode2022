#include <fstream>
#include <iostream>
#include <map>
using namespace std;

int main(int ac, char **av)
{
    string line;
    ifstream myfile(av[1]);

    int total = 0;
    map<char, int> shapes = {
        {'A', 1},
        {'B', 2},
        {'C', 3},
        {'X', 1},
        {'Y', 2},
        {'Z', 3}
    };

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            const int myScore = shapes[line[2]];
            const int enemyScore = shapes[line[0]];

            if ((myScore == 1 && enemyScore == 3) || (myScore == 2 && enemyScore == 1) || (myScore == 3 && enemyScore == 2))
                total += myScore + 6;
            else if (myScore == enemyScore)
                total += myScore + 3;
            else
                total += myScore;
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    std::cout << total << std::endl;
}