#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Modify this function to use a C++ standard method for joining strings.
std::string join(const std::vector<std::string>& vec, const std::string& delim) {
    // #TODO: Replace the following stream operations with string concatenation operations ensuring it works also for variable number of fields
    std::string result = "";
    for(int i = 0; i < vec.size(); i++){
        result += vec[i];
        if(i == vec.size() - 1){
            break;
        }
        result += delim;
    }
    return result;
    
}

int main() {
    std::string astronauts_data = "Buzz Aldrin,1930;Yuri Gagarin,1934;Valentina Tereshkova,1937";
    std::vector<std::string> astronauts_list = split(astronauts_data, ';');
    std::vector<std::string> cleaned_astronauts;

    for (auto& astronaut : astronauts_list) {
        std::vector<std::string> astronaut_info = split(astronaut, ',');
        for (auto& info : astronaut_info) {
            info.erase(info.find_last_not_of(" \n\r\t\f\v") + 1);
        }
        cleaned_astronauts.push_back(join(astronaut_info, " "));
    }

    for (auto& astronaut : cleaned_astronauts) {
        std::cout << astronaut << std::endl; // Should output: Buzz Aldrin 1930, Yuri Gagarin 1934, Valentina Tereshkova 1937
    }
    
    return 0;
}