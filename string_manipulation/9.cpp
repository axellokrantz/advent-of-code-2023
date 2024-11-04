#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> 

std::string& removeSpaces(std::string& s){
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    return s;
}

void processAstronautData(const std::string& data) {
    std::istringstream sstream(data);
    std::string detail;
    
    while (std::getline(sstream, detail, ';')) {
        
        // TODO: Extract the astronaut name and explored planet from the detail,
        //       and strip away the whitespace.

        std::string name, planet;
        removeSpaces(detail);
        std::istringstream detailStream(detail);

        std::getline(detailStream, name, '-');
        std::getline(detailStream, planet);

        // TODO: Print the statement in the format "Astronaut [name] is exploring [planet]."
        std::cout << "Astronaut " << name << " is exploring " << planet << '.' << "\n";
    }
}

int main() {
    std::string astronautData = "    Neil-Mars; Buzz-Jupiter; Sally-Venus    ";
    processAstronautData(astronautData);
    
    return 0;
}