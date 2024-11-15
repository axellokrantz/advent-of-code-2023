#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

struct Mapping {
    long long destination_range_start;
    long long source_range_start;
    long long range_length;
};

struct SeedMapping {
    long long seed;
    long long soil;
    long long fertilizer;
    long long water;
    long long light;
    long long temperature;
    long long humidity;
    long long location;
};

Mapping parse_mapping(const std::string& line){
    Mapping mapping;
    std::stringstream ss(line);
    ss >> mapping.destination_range_start >> mapping.source_range_start >> mapping.range_length;
    return mapping;
}

long long do_mapping(long long source_value, const std::vector<Mapping>& mappings){
    long long result = source_value;
    for(const auto& mapping : mappings){
        long long source_range = mapping.source_range_start + mapping.range_length - 1;
        if(source_value <= source_range && source_value >= mapping.source_range_start){
            long long offset = source_value - mapping.source_range_start;
            result = mapping.destination_range_start + offset;
            break;
        }
    }
    return result;
}

int main() {
    std::ifstream input_file("input.txt");
    std::string line;
    std::getline(input_file, line);
    std::vector<long long> seeds;

    std::vector<Mapping> seed_to_soil;
    std::vector<Mapping> soil_to_fertilizer;
    std::vector<Mapping> fertilizer_to_water;
    std::vector<Mapping> water_to_light;
    std::vector<Mapping> light_to_temperature;
    std::vector<Mapping> temperature_to_humidity;
    std::vector<Mapping> humidity_to_location;
    std::vector<SeedMapping> seed_mapping;

    size_t colon_pos = line.find(":");
    std::string seed_str = line.substr(colon_pos + 1);
    std::stringstream ss(seed_str);
    
    long long seed;
    while (ss >> seed) {
        SeedMapping map;
        map.seed = seed;
        seed_mapping.push_back(map);
    }

    std::string current_section;

    while (std::getline(input_file, line)) {
        
        if (line.empty()) {
            continue;
        }

        if (line.find("seed-to-soil") != std::string::npos) {
            current_section = "seed-to-soil";
        } else if (line.find("soil-to-fertilizer") != std::string::npos) {
            current_section = "soil-to-fertilizer";
        } else if (line.find("fertilizer-to-water") != std::string::npos) {
            current_section = "fertilizer-to-water";
        } else if (line.find("water-to-light") != std::string::npos) {
            current_section = "water-to-light";
        } else if (line.find("light-to-temperature") != std::string::npos) {
            current_section = "light-to-temperature";
        } else if (line.find("temperature-to-humidity") != std::string::npos) {
            current_section = "temperature-to-humidity";
        } else if (line.find("humidity-to-location") != std::string::npos) {
            current_section = "humidity-to-location";
        } else {
            if (current_section == "seed-to-soil") { 
                seed_to_soil.push_back(parse_mapping(line));
            } else if (current_section == "soil-to-fertilizer") {
                soil_to_fertilizer.push_back(parse_mapping(line));
            } else if (current_section == "fertilizer-to-water") {
                fertilizer_to_water.push_back(parse_mapping(line));
            } else if (current_section == "water-to-light") {
                water_to_light.push_back(parse_mapping(line));
            } else if (current_section == "light-to-temperature") {
                light_to_temperature.push_back(parse_mapping(line));
            } else if (current_section == "temperature-to-humidity") {
                temperature_to_humidity.push_back(parse_mapping(line));
            } else if (current_section == "humidity-to-location") {
                humidity_to_location.push_back(parse_mapping(line));
            }
        }
    }

    long long lowest_location_number = LONG_LONG_MAX;

    for(auto& mapping : seed_mapping){
        mapping.soil = do_mapping(mapping.seed, seed_to_soil);
        mapping.fertilizer = do_mapping(mapping.soil, soil_to_fertilizer);
        mapping.water = do_mapping(mapping.fertilizer, fertilizer_to_water);
        mapping.light = do_mapping(mapping.water, water_to_light);
        mapping.temperature = do_mapping(mapping.light, light_to_temperature);
        mapping.humidity = do_mapping(mapping.temperature, temperature_to_humidity);
        mapping.location = do_mapping(mapping.humidity, humidity_to_location);

        if(mapping.location < lowest_location_number){
            lowest_location_number = mapping.location;
        }
    }

    std::cout << "The lowest location number is: " << lowest_location_number;
}