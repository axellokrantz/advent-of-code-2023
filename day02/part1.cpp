#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace CubeCounts {
   const int MAX_RED_COUNT = 12;
   const int MAX_GREEN_COUNT = 13;
   const int MAX_BLUE_COUNT = 14;
}

bool compareCount(const std::string& color, const int& count){
    
   if(color == "red" && count > CubeCounts::MAX_RED_COUNT){
       return false;
   }
   else if(color == "green" && count > CubeCounts::MAX_GREEN_COUNT){
       return false;
   }
   else if(color == "blue" && count > CubeCounts::MAX_BLUE_COUNT){
       return false;
   }
   return true;

}

bool isGamePossible(std::vector<std::string> rounds){

   for(std::string round : rounds){
       round.erase(0, round.find_first_not_of(" "));
       
       size_t space_pos = round.find(" ");
       size_t comma_pos = round.find(",");

       while(comma_pos != std::string::npos){
           int count = std::stoi(round.substr(0, space_pos));
           std::string color = round.substr(space_pos + 1, comma_pos - (space_pos + 1));
           round = round.substr(comma_pos + 2);
           round.erase(0, round.find_first_not_of(" "));
           space_pos = round.find(" ");
           comma_pos = round.find(",");
           if(!compareCount(color, count)){
               return false;
           }
       }

       int count = std::stoi(round.substr(0, space_pos));
       std::string color = round.substr(space_pos + 1);

       if(!compareCount(color, count)){
               return false;
       }
   }
   return true;
}


int main() {

   std::ifstream input_file("input.txt");
   std::string current_line;
   int sum = 0;

   while (std::getline(input_file, current_line)) {
       size_t game_pos = current_line.find("Game ");
       if (game_pos != std::string::npos) {
           size_t colon_pos = current_line.find(":");
           int game_id = std::stoi(current_line.substr(game_pos + 5, colon_pos - (game_pos + 5)));

           std::vector<std::string> rounds;
           std::string remaining = current_line.substr(colon_pos + 1);
           
           size_t semicolon_pos = remaining.find(";");
           while (semicolon_pos != std::string::npos) {
               rounds.push_back(remaining.substr(0, semicolon_pos));
               remaining = remaining.substr(semicolon_pos + 1);
               semicolon_pos = remaining.find(";");
           }
           rounds.push_back(remaining);

           if (isGamePossible(rounds)) {
               sum += game_id;
           }
       }
   }

   std::cout << "Sum of possible game IDs: " << sum << std::endl;
   return 0;
}   