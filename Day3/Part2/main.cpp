#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int calculateTotal(vector<char> badges) {
    int total = 0;

    for (char badge : badges)
    {
        if (badge >= 'a' && badge <= 'z')
            total += badge - 'a' + 1;
        else if (badge >= 'A' && badge <= 'Z')
            total += badge - 'A' + 27;
    }

    return total;
}

char getBadge(vector<string> lines)
{
    vector<char> commonChars;

    for (char character : lines[0])
        if (lines[1].find(character) != string::npos) {
            commonChars.push_back(character);
        }
    for (char character : commonChars)
        if (lines[2].find(character) != string::npos) {
            return character;
        }
    return ' ';
}

int main(int ac, char **av)
{
    std::string line;
    std::ifstream myfile(av[1]);

    vector<char> badges;
    vector<string> lines;
    int index = 0;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (index >= 3)
            {
                badges.push_back(getBadge(lines));
                lines.clear();
                index = 0;
            }
            lines.push_back(line);
            index++;
        }
        badges.push_back(getBadge(lines));
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    std::cout << calculateTotal(badges) << std::endl;
    return 0;
}