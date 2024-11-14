#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

int main(){
    std::ifstream input_file("input.txt");
    std::string line;
    std::getline(input_file, line);
    std::vector<long long> seeds;
    
    size_t colon_pos = line.find(":");
    std::string seed_str = line.substr(colon_pos + 1);
    std::cout << seed_str << std::endl;
    std::stringstream ss(seed_str);

    long long seed;
    while(ss >> seed){
        seeds.push_back(seed);
    }
    
    while(std::getline(input_file, line)){
        
        // To calculate the corresponding soil number for a seed:

        // Find the seed range the seed falls into
        // Calculate offset from seed range start
        // Add that offset to soil range start

        // E.g. for seed 2189748072 and range "1738919961 2189748071 56658550":

        // 2189748072 is in range 2189748071 to 2189748071+56658550-1
        // Offset from start (2189748071) is 1
        // Adding 1 to soil range start (1738919961) gives 1738919962

        // So seed 2189748072 maps to soil 1738919962.

    }
}