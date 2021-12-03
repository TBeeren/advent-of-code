#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <cstring>
#include <bitset>
#include <bit>

using namespace std;

namespace
{
    constexpr int BINARY_LENGTH = 12;
}

typedef std::string binary;

vector<binary> parseInput()
{
    ifstream file("input");
    vector<binary> input;

    binary binary;
    string line, tmp;
    int iter;

    while (getline(file, line))
    {
        input.push_back(line);
    }

    return input;
}

// 1 or 0
char mostCommon(const vector<binary> &input, int iter)
{
    char retVal;
    int n = 0;
    for (binary i : input)
    {
        int x = (int)i[iter] - '0';
        x ? n++ : n;
    }

    n >= input.size() / 2 ? retVal = '1' : retVal = '0';

    return retVal;
}

void part1(const vector<binary> &input)
{
    binary gamma;
    binary epsilon;

    for (int j = 0; j < BINARY_LENGTH; j++)
    {
        if (mostCommon(input, j) == '1')
        {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
        else
        {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
    }

    unsigned long long g = std::bitset<64>(gamma).to_ullong();
    unsigned long long e = std::bitset<64>(epsilon).to_ullong();
    std::cout << "Result 1: " << g << " * " << e << " = " << g * e << std::endl;
}

void part2(vector<binary> input)
{
    vector<binary> o2 = input;
    vector<binary> co2 = input;

    for (int j = 0; j < BINARY_LENGTH; j++)
    {
        char x = mostCommon(o2, j);
        for (int i = 0; i < o2.size(); i++)
        {
            if (o2[i][j] != x)
            {
                o2.erase(o2.begin() + i);
            };
        }

        char y = mostCommon(co2, j);
        for (int k = 0; k < co2.size(); k++)
        {
            if (co2.size() == 2) // ugly hack woops.
            {
                y = 1;
            }
            if (co2[k][j] == y)
            {
                co2.erase(co2.begin() + k);
            };
        }
    }

    unsigned long long o = std::bitset<64>(o2.at(0)).to_ullong();
    unsigned long long c = std::bitset<64>(co2.at(1)).to_ullong();

    std::cout << "Result 2: " << o << " * " << c << " = " << o * c << std::endl;
}

int main()
{
    vector<binary> input = parseInput();
    part1(input);
    part2(input);

    return 0;
}