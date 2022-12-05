#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

int main(int ac, char **av)
{
    std::string line;
    std::ifstream myfile(av[1]);

    bool isStack = true;
    vector<list<char>> stacks;
    string result = "";
    list<char> tmpStack;

    for (int i = 0; i < 9; i++) {
        list<char> stack;
        stacks.push_back(stack);
    }

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cmatch match;
            regex regex("move ([0-9]+) from ([0-9]+) to ([0-9]+)");
            regex_search(line.c_str(), match, regex);

            if (line[1] == '1') {
                isStack = false;
            }
            if (isStack) {
                for (int i = 0; i < 9; i++) {
                    if (line[i * 4 + 1] != ' ')
                        stacks[i].push_front(line[i * 4 + 1]);
                }
            } else if (match.size() == 4) {
                const int move = stoi(match[1]);
                const int from = stoi(match[2]) - 1;
                const int to = stoi(match[3]) - 1;
                
                for (int i = 0; i < move; i++) {
                    if (stacks[from].size() > 0) {
                        tmpStack.push_back(stacks[from].back());
                        stacks[from].pop_back();
                    }
                }
                while (tmpStack.size() > 0) {
                    stacks[to].push_back(tmpStack.back());
                    tmpStack.pop_back();
                }
            }
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    for (int i = 0; i < 9; i++) {
        result.push_back(stacks[i].back());
    }

    cout << result << endl;
    return 0;
}