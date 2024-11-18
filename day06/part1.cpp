#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

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

    std::stringstream time_ss(time_line.substr(time_line.find(":") + 1));
    std::stringstream distance_ss(
        distance_line.substr(distance_line.find(":") + 1));
    int time, distance;

    while (time_ss >> time && distance_ss >> distance) {
        race_stats.push_back({time, distance});
    }

    std::vector<int> margin_of_error;
    for (int i = 0; i < race_stats.size(); i++) {
        int ways_to_win = 0;
        for (int j = 0; j <= race_stats[i].time; j++) {
            int time = race_stats[i].time - j;
            int distance = j * time;
            if (distance > race_stats[i].distance) {
                ways_to_win++;
            }
        }
        margin_of_error.push_back(ways_to_win);
    }

    std::cout << "Product of the number of ways to win: "
              << std::accumulate(margin_of_error.begin(), margin_of_error.end(),
                                 1, std::multiplies<int>());
    return 0;
}