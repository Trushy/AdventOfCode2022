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
    };
    map<int, int> winCondition = {
        {1, 2},
        {2, 3},
        {3, 1}
    };
    map<int, int> loseCondition = {
        {1, 3},
        {2, 1},
        {3, 2}
    };

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            const int enemyScore = shapes[line[0]];

            if (line[2] == 'X') {
                total += loseCondition[enemyScore];
            } else if (line[2] == 'Y') {
                total += enemyScore + 3;
            } else if (line[2] == 'Z') {
                total += winCondition[enemyScore] + 6;
            }
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    std::cout << total << std::endl;
}