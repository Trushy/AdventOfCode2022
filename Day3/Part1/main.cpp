#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int calculateTotal(vector<char> items) {
    int total = 0;

    for (char item : items)
    {
        if (item >= 'a' && item <= 'z')
            total += item - 'a' + 1;
        else if (item >= 'A' && item <= 'Z')
            total += item - 'A' + 27;
    }

    return total;
}

int main(int ac, char **av)
{
    std::string line;
    std::ifstream myfile(av[1]);

    vector<char> items;
    int total = 0;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            const string firstHalf = line.substr(0, line.length() / 2);
            const string secondHalf = line.substr(line.length() / 2, line.length());

            for (char character : firstHalf)
            {
                if (secondHalf.find(character) != string::npos) {
                    items.push_back(character);
                    break;
                }
            }
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";
    
    std::cout << calculateTotal(items) << std::endl;
    return 0;
}