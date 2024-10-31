#include <iostream>
#include <string>

int main() {
    // Given mission name
    std::string mission_name = "Sort";

    // TODO: Print the original first and last character of the mission name
    char first = mission_name[0];
    char last = mission_name[mission_name.size() - 1];
    std::cout << first << " " << last << "\n";
    
    // TODO: The mission needs a minor update. Change its first letter to 'P' and the last letter to 'k' directly.
    mission_name[0] = 'P';
    mission_name[mission_name.size() - 1] = 'k';

    // TODO: Print the updated mission name
    std::cout << mission_name[0] << " " << mission_name[mission_name.size() - 1];

    return 0;
}