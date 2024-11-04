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
    
    while (std::getline(sstream, buffer, ' ')) {
        employee_info.push_back(buffer);
    }
    
    // Join the strings into a single string with newlines
    std::string cleaned_data;
    for (const std::string& info : employee_info) {
        cleaned_data += info + "\n";
    }
    
    std::cout << cleaned_data;
    
    return 0;
}