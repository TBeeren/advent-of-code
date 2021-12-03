#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

int depth = 0;
int horizontal = 0;
int aim = 0;

struct instruction
{
    string command;
    int value;
};

vector<instruction> parseInput()
{
    ifstream is("input");
    vector<instruction> input;
    instruction instruction;
    string line, tmp;
    int iter;
    while (getline(is, line))
    {
        tmp = "";
        for (iter = 0; line[iter] != ' '; iter++){
            tmp += line[iter];
        }
        instruction.command = tmp;
        instruction.value = stoi(line.substr(iter));
        input.push_back(instruction);
    }
    return input;
}

void part1(const vector<instruction> &input)
{
    for (instruction i : input)
    {
        if (i.command == "down")
            depth += i.value;
        if (i.command == "up")
            depth -= i.value;
        if (i.command == "forward")
            horizontal += i.value;
    }
    cout << "First star:" << horizontal * depth << endl;
}

void part2(const vector<instruction> &input)
{
    horizontal = 0;
    depth = 0;
    for (instruction i : input)
    {
        if (i.command == "down")
            aim += i.value;
        if (i.command == "up")
            aim -= i.value;
        if (i.command == "forward")
        {
            horizontal += i.value;
            depth += aim * i.value;
        }
    }
    cout << "Second star:" << horizontal * depth << endl;
}

int main()
{
    vector<instruction> input = parseInput();
    part1(input);
    part2(input);

    return 0;
}