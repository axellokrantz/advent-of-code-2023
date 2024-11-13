#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

void updateMinimum(const std::string& color, int count, size_t& min_red, size_t& min_blue, size_t& min_green){

    if(color == "red" && count > min_red){
        min_red = count;
    }
    else if(color == "blue" && count > min_blue){
        min_blue = count;
    }
    else if(color == "green" && count > min_green){
        min_green = count;
    }
}

int minimumPower(std::vector<std::string> rounds)
{   
    int min_power_sum = 0;
    for (std::string round : rounds)
    {
        size_t min_red = 0;
        size_t min_blue = 0;
        size_t min_green = 0;
        
        round.erase(0, round.find_first_not_of(" "));
        size_t space_pos = round.find(" ");
        size_t comma_pos = round.find(",");

        while (comma_pos != std::string::npos)
        {
            int count = std::stoi(round.substr(0, space_pos));
            std::string color = round.substr(space_pos + 1, comma_pos - (space_pos + 1));
            round = round.substr(comma_pos + 2);
            space_pos = round.find(" ");
            comma_pos = round.find(",");
            updateMinimum(color, count, min_red, min_blue, min_green);
        }

        int count = std::stoi(round.substr(0, space_pos));
        std::string color = round.substr(space_pos + 1);
        updateMinimum(color, count, min_red, min_blue, min_green);
        min_power_sum += min_red * min_blue * min_green;
    }
    return min_power_sum;
}

int main()
{
    std::ifstream input_file("input.txt");
    std::string current_line;
    int sum = 0;

    while (std::getline(input_file, current_line))
    {
        size_t game_pos = current_line.find("Game ");
        if (game_pos != std::string::npos)
        {
            size_t colon_pos = current_line.find(":");
            int game_id = std::stoi(current_line.substr(game_pos + 5, colon_pos - (game_pos + 5)));

            std::vector<std::string> rounds;
            
            std::string remaining = current_line.substr(colon_pos + 1);
            std::replace(remaining.begin(), remaining.end(), ';', ',');
            
            rounds.push_back(remaining);
            sum += minimumPower(rounds);
        }
    }

    std::cout << "Sum of the power of minimum sets: " << sum << std::endl;
    return 0;
}