#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

int getSimilarityScore(std::vector<int> left, std::vector<int> right) {
    std::unordered_map<int, int> freqMap;

    for (int val : right) {
        freqMap[val]++;
    }

    int similarityScore = 0;

    for (int val : left) {
        if (freqMap.count(val) > 0) {
            similarityScore += val * freqMap[val];
        } 
    }

    return similarityScore;
    
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

    int res = getSimilarityScore(leftCol, rightCol);

    std::cout << "Similarity Score = " << res << std::endl;
    return 0;
}
