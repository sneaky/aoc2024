#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

bool isIncreasing(const std::vector<int>& tokens) {
    int bad_level_count = 0;
    //bool flag = true;
    for (size_t i = 1; i < tokens.size(); ++i) {
        if (tokens[i] <= tokens[i - 1] || abs(tokens[i] - tokens[i - 1]) > 3) {
            // check if we removing a single element will fix the issue
            bad_level_count++;
            //flag = false;
        }
    }
    return bad_level_count == 1 || bad_level_count == 0;
}

bool isDecreasing(const std::vector<int>& tokens) {
    int bad_level_count = 0;
    for (size_t i = 1; i < tokens.size(); ++i) {
        if (tokens[i] >= tokens[i - 1] || abs(tokens[i] - tokens[i - 1]) > 3) {
            bad_level_count++;
        }
    }
    return bad_level_count == 1 || bad_level_count == 0;
}

int main() {
    
    std::ifstream input("../inputs/day2-input.txt");
    if (!input.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    int safeCount = 0;

    std::string line;
    while (std::getline(input, line)) {
        std::istringstream stream(line);
        std::vector<int> tokens;
        std::string token;

        while (stream >> token) {
            tokens.push_back(stoi(token));
        }

        if (tokens.empty()) continue;
        bool increasing = isIncreasing(tokens);
        bool decreasing = isDecreasing(tokens);

        if (increasing || decreasing) safeCount++; 
    }
    input.close();

    std::cout << "Safety Score = " << safeCount << std::endl;
    return 0;
}
