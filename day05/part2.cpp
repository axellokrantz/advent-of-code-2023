#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

struct Range {
    long long start;
    long long length;
};

struct Mapping {
    long long destination_range_start;
    long long source_range_start;
    long long range_length;
};

std::vector<Range> apply_mapping(std::vector<Range>& input_ranges, const std::vector<Mapping>& mappings) {
    std::vector<Range> result;
    for(const Range& range : input_ranges){
        std::vector<Range> unmapped = {range};
        std::vector<Range> next_unmapped;

        for(const Mapping& map : mappings){
            for(const Range& range : unmapped) {
                long long range_end = range.start + range.length;
                long long map_end = map.source_range_start + map.range_length;

                if(range_end < map.source_range_start || range.start > map_end){
                    next_unmapped.push_back(range);
                    continue;
                }

                if(range.start < map.source_range_start){
                    next_unmapped.push_back({range.start, map.source_range_start - range.start});
                }

                if(range_end > map_end){
                    next_unmapped.push_back({map_end, range_end - map_end});
                }

                long long overlap_start = std::max(range.start, map.source_range_start);
                long long overlap_end = std::min(range_end, map_end);
                long long offset = map.destination_range_start - map.source_range_start;
                result.push_back({overlap_start + offset, overlap_end - overlap_start});
            }
            unmapped = next_unmapped;
            next_unmapped.clear();
        }
        if (!unmapped.empty()) {
            result.insert(result.end(), unmapped.begin(), unmapped.end());
        }
    }
    return result;
}
int main() {
    std::ifstream input_file("input.txt");
    std::string line;
    std::vector<Range> ranges;
    std::vector<std::vector<Mapping>> all_mappings(7);
    
    std::getline(input_file, line);
    std::stringstream ss(line.substr(line.find(":") + 1));
    long long start, length;
    while (ss >> start >> length) {
        ranges.push_back({start, length});
    }

    int current_map = -1;
    while (std::getline(input_file, line)) {
        if (line.empty()) {
            continue;
        }

        if(line.find("map") != std::string::npos){
            current_map++;
            continue;
        }

        if (current_map >=0){
            std::stringstream ss(line);
            long long dest, src, len;
            if(ss >> dest >> src >> len) {
                all_mappings[current_map].push_back({dest, src, len});
            }
        }
    }

    for(auto& mappings : all_mappings){
        ranges = apply_mapping(ranges, mappings);
    }

    long long min_location = std::numeric_limits<long long>::max();
    for (const auto& range : ranges){
        if(min_location > range.start){
            min_location = range.start;
        }
    }

    std::cout << "The lowest location number is: " << min_location; 
}