#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <algorithm>

struct RaceStats {
    int time;
    int distance;
};

int main() {
    std::vector<RaceStats> race_stats;
    std::ifstream input_file("input.txt");
    std::string time_line, distance_line;

    std::getline(input_file, time_line);
    std::getline(input_file, distance_line);

    time_line = time_line.substr(time_line.find(":") + 1);
    distance_line = distance_line.substr(distance_line.find(":") + 1);

    time_line.erase(remove(time_line.begin(), time_line.end(), ' '), time_line.end());
    distance_line.erase(remove(distance_line.begin(), distance_line.end(), ' '), distance_line.end());

    long long time = std::stoll(time_line);
    long long distance = std::stoll(distance_line);



    long long ways_to_win = 0;
    for (int i = 0; i <= time; i++)
    {
        long long curr_distance = i * (time - i);
        if(curr_distance > distance){
            ways_to_win++;
        }
    }
    
    std::cout << "Number of ways to win: " << ways_to_win;
    return 0;
}