#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(int ac, char **av)
{
    std::string line;
    std::ifstream myfile(av[1]);

    int index = 0;
    vector<int> maxCalories;
    int calculatedCalories = 0;
    int result = 0;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (line.size() <= 1) {
                maxCalories.push_back(calculatedCalories);
                calculatedCalories = 0;
            } else {
                calculatedCalories += stoi(line);
            }
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    sort(maxCalories.begin(), maxCalories.end(), greater<int>());

    for (auto i : maxCalories) {
        if (index < 3)
            result += i;
        index++;
    }
    std::cout << result << std::endl;

    return 0;
}