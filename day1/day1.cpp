#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

int sumDifferences(std::vector<int> leftCol, std::vector<int> rightCol) {
    if (leftCol.size() != rightCol.size()) {
        std::cerr << "Error: Column sizes are different!" << std::endl;
        return -1;
    }
    
    int sum = 0;

    for (int i = 0; i < leftCol.size(); i++) {
        sum += abs(leftCol[i] - rightCol[i]);        
    }

    return sum;
}

int main() {
    
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }
    
    std::vector<int> leftCol;
    std::vector<int> rightCol;

    std::string line;
    while (std::getline(input, line)) {
        std::istringstream stream(line);
        int left;
        int right;
        
        if (stream >> left >> right) {
            leftCol.push_back(left);
            rightCol.push_back(right);
        } else {
            std::cerr << "Error: Line format is incorrect -> " << line << std::endl;
            return 1;
        }
    }
    input.close();

    sort(leftCol.begin(), leftCol.end());
    sort(rightCol.begin(), rightCol.end());
    int res = sumDifferences(leftCol, rightCol);

    std::cout << "Sum of differences = " << res << std::endl;

    return 0;
}
