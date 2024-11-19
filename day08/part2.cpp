#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <numeric>

long long lcm(long long a, long long b) {
    return (a * b) / std::gcd(a, b);
}

int main() {
    std::ifstream input_text("input.txt");
    std::map<std::string, std::pair<std::string, std::string>> nodes;
    std::string instructions;
    std::string current_line;
    std::getline(input_text, instructions);
    std::getline(input_text, current_line);

    while (std::getline(input_text, current_line)) {
        if (current_line.empty()) continue;

        std::string node = current_line.substr(0, 3);
        std::string left = current_line.substr(7, 3);
        std::string right = current_line.substr(12, 3);

        nodes[node] = {left, right};
    }

    std::vector<std::string> positions;
    for (auto& node : nodes) {
        if (node.first.back() == 'A') {
            positions.push_back(node.first);
        }
    }

    std::vector<long long> steps;

    for (auto& position : positions) {
        long long step = 0;
        while (position.back() != 'Z') {
            char instruction = instructions[step % instructions.length()];
            if (instruction == 'L') {
                position = nodes[position].first;
            } else {
                position = nodes[position].second;
            }
            step++;
        }
        steps.push_back(step);
    }
    long long result = steps[0];
    for (int i = 1; i < steps.size(); i++)
    {
        result = lcm(result, steps[i]);
    }
    
    std::cout << "Total number of steps: " << result;
    return 0;
}