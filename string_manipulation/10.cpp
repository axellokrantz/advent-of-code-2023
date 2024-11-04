#include <iostream>
#include <vector>
#include <sstream>

struct CrewMember {
    std::string first_name;
    std::string last_name;
    std::string mission;
    std::string role;
};


int main() {
    // Space exploration crew members' data, containing their names, missions, and roles
    std::string crew_data = "Neil,Armstrong,Apollo 11,C;Buzz,Aldrin,Apollo 11,P;Michael,Collins,Apollo 11,CM";
    std::istringstream sstream(crew_data);
    std::string detail;
    std::vector<CrewMember> crew;

    while(getline(sstream, detail, ';')){
        char delimiter = ',';
        CrewMember crew;
        

        std::istringstream detailStream(detail);
        std::getline(detailStream, crew.first_name, delimiter);
        std::getline(detailStream, crew.last_name, delimiter);
        std::getline(detailStream, crew.mission, delimiter);
        std::getline(detailStream, crew.role);

        std::cout << crew.first_name << " " << crew.last_name << " " << crew.mission << " " << crew.role << "\n";
    }
    // TODO: Split the crew_data string into a list of individual crew member information using the appropriate delimiter
    
    // TODO: Iterate over the list of crew member data
    
        // TODO: For each member, split their data string using commas as delimiters
        
        // TODO: Print the crew member's details in a formatted string
    
    // Expected output:
    // Neil Armstrong Apollo 11 C
    // Buzz Aldrin Apollo 11 P
    // Michael Collins Apollo 11 CM

    return 0;
}