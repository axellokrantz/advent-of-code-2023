// Employee Information Management System

#include <iostream>
#include <sstream>
#include <vector>

int main() {
    // A string of employee data
    std::string employee_data = "Name: John Doe, Age: 30, Role: Engineer";
    
    std::vector<std::string> employee_info;
    std::istringstream sstream(employee_data);
    std::string buffer;
    
    while (std::getline(sstream, buffer, ',')) {
        if(!buffer.empty() && buffer[0] == ' '){
            buffer.erase(0, 1);
        }
        employee_info.push_back(buffer);
    }

    // Join the strings into a single string with newlines
    std::string cleaned_data;
    for (int i = 0; i < employee_info.size(); i++) {
        if(i == employee_info.size() - 1){
            cleaned_data += employee_info[i];
            break;
        }
        cleaned_data += employee_info[i];
        cleaned_data += "\n";
    }
    
    std::cout << cleaned_data;
    
    return 0;
}