#include <fstream>
#include <iostream>
#include <map>
#include <string>

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

    std::string current = "AAA";
    int step = 0;
    while(current != "ZZZ"){
        char instruction = instructions[step % instructions.length()];
        if(instruction == 'L'){
            current = nodes[current].first;
        }
        else{
            current = nodes[current].second;
        }
        step++;
    }
    
    std::cout << "Number of steps: " << step;
}