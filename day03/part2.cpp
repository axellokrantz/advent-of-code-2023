#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int getFullNumber(const std::string& line, int pos, int& start, int& end) {
    start = pos;
    end = pos;

    while (start >= 0 && isdigit(line[start])) {
        start--;
    }
    start++;

    while (end < line.length() && isdigit(line[end])) {
        end++;
    }

    return std::stoi(line.substr(start, end - start));
}

std::vector<int> findAdjacentNumbers(const std::string& prev,
                                     const std::string& curr,
                                     const std::string& next, int pos) {
    std::vector<int> numbers;
    std::set<std::pair<int, int>> seen;

    for (int y = -1; y <= 1; y++) {
        const std::string& line = (y == -1) ? prev : ((y == 0) ? curr : next);
        if (line.empty()) continue;

        for (int x = -1; x <= 1; x++) {
            int checkPos = pos + x;
            if (checkPos < 0 || checkPos >= line.length()) continue;

            if (isdigit(line[checkPos])) {
                int start, end;
                int number = getFullNumber(line, checkPos, start, end);

                std::pair<int, int> key = {y + 1, start};
                if (seen.insert(key).second) {
                    numbers.push_back(number);
                }
            }
        }
    }

    return numbers;
}

int processSchematic(const std::string& filename) {
    std::ifstream file(filename);
    std::string prev = "", curr = "", next = "";
    int total = 0;

    if (!std::getline(file, curr)) return 0;

    while (std::getline(file, next)) {
        for (int i = 0; i < curr.length(); i++) {
            if (curr[i] == '*') {
                auto adjacentNums = findAdjacentNumbers(prev, curr, next, i);
                if (adjacentNums.size() == 2) {
                    total += adjacentNums[0] * adjacentNums[1];
                }
            }
        }

        prev = curr;
        curr = next;
    }

    for (int i = 0; i < curr.length(); i++) {
        if (curr[i] == '*') {
            auto adjacentNums = findAdjacentNumbers(prev, curr, "", i);
            if (adjacentNums.size() == 2) {
                total += adjacentNums[0] * adjacentNums[1];
            }
        }
    }

    return total;
}

int main() {
    int result = processSchematic("input.txt");
    std::cout << "Sum of all gear ratios: " << result << std::endl;
    return 0;
}