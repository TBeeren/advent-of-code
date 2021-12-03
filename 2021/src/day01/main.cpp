#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

std::vector<int32_t> parseInput()
{
    std::vector<int32_t> depths;
    int32_t depth;
    while (std::cin >> depth)
    {
        depths.push_back(depth);
    }
    return depths;
}

int32_t countIncreasing(std::vector<int32_t> &depths, uint32_t c)
{
    int32_t n = 0;
    for (int32_t i = c; i < depths.size(); ++i)
    {
        n += depths[i] > depths[i - c];
    }
    return n;
}

int main(int argc, char const *argv[])
{
    std::vector<int32_t> input = parseInput();

    int32_t part1 = countIncreasing(input, 1);
    std::cout << "Result 1: " << part1 << std::endl;

    int32_t part2 = countIncreasing(input, 3);
    std::cout << "Result 2: " << part2 << std::endl;

    return 0;
}