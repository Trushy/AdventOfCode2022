#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(int ac, char **av)
{
    std::string line;
    std::ifstream myfile(av[1]);

    unordered_map<char, int> characters;
    bool duplicate = false;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            for (int i = 0; line[i]; i++)
            {
                if (line[i + 4]) {
                    for (int j = 1; j <= 4; j++) {
                        characters[line[i + j]]++;
                    }

                    for (auto& it : characters) {
                        if (it.second > 1) {
                            duplicate = true;
                            continue;
                        }
                    }
                    if (!duplicate) {
                        cout << i + 5 << endl;
                        return 0;
                    }

                    duplicate = false;
                    characters.clear();
                }
            }
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    return 0;
}