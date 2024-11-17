#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

struct Seed {
    long long value;
};

struct Mapping {
    long long destination_range_start;
    long long source_range_start;
    long long range_length;
};

long long apply_single_mapping(long long value, const std::vector<Mapping>& mappings) {
    for (const auto& mapping : mappings) {
        long long source_range_end = mapping.source_range_start + mapping.range_length;
        if (value >= mapping.source_range_start && value < source_range_end) {
            long long offset = value - mapping.source_range_start;
            return mapping.destination_range_start + offset;
        }
    }
    return value;
}

std::vector<long long> process_through_mappings(const std::vector<long long>& values, 
                                              const std::vector<std::vector<Mapping>>& all_mappings) {
    std::vector<long long> current_values = values;
    
    for (const auto& mappings : all_mappings) {
        std::vector<long long> next_values;
        for (const auto& value : current_values) {
            next_values.push_back(apply_single_mapping(value, mappings));
        }
        current_values = next_values;
    }
    
    return current_values;
}

int main() {
    std::ifstream input_file("input.txt");
    std::string line;
    std::vector<long long> seeds;
    std::vector<std::vector<Mapping>> all_mappings(7);
    std::getline(input_file, line);

    
    std::stringstream ss(line.substr(line.find(":") + 1));
    long long seed_value;
    while (ss >> seed_value) {
        seeds.push_back(seed_value);
    }

    int current_map = -1;
    while (std::getline(input_file, line)) {
        if (line.empty()) {
            continue;
        }

        if (line.find("map") != std::string::npos) {
            current_map++;
            continue;
        }

        if (current_map >= 0) {
            std::stringstream ss(line);
            long long dest, src, len;
            if (ss >> dest >> src >> len) {
                all_mappings[current_map].push_back({dest, src, len});
            }
        }
    }

    std::vector<long long> final_locations = process_through_mappings(seeds, all_mappings);

    long long lowest_location = std::numeric_limits<long long>::max();
    for (const auto& location : final_locations) {
        lowest_location = std::min(lowest_location, location);
    }

    std::cout << "The lowest location number is: " << lowest_location;
    return 0;
}