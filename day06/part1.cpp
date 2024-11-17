#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

struct RaceStats{
    int time;
    int distance;
};

int main(){
    std::vector<RaceStats> race_stats;
    std::ifstream input_file("input.txt");
    std::string time_line, distance_line;

    std::getline(input_file, time_line);
    std::getline(input_file,distance_line);

    std::stringstream time_ss(time_line.substr(time_line.find(":") + 1));
    std::stringstream distance_ss(distance_line.substr(distance_line.find(":") + 1));
    int time, distance;

    while(time_ss >> time && distance_ss >> distance){
        race_stats.push_back({time, distance});
    }
    return 0;
}