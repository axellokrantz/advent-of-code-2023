#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string employee_data = "Alice,Developer,30|Bob,Manager,45|Charlie,Designer,25";
    std::vector<std::string> employee_list;
    std::istringstream data_stream(employee_data);
    std::string record;

    // Tokenizing the employee data by '|' to separate each employee's info
    while (std::getline(data_stream, record, '|')) {
        employee_list.push_back(record);
    }

    // Iterating over the list of employees
    for (auto& employee : employee_list) {
        std::istringstream record_stream(employee);
        std::string name, role, age_str;
        int age;
        char delimiter = ',';

        // TODO: Extract the information and append eligibility note if under 40

        std::getline(record_stream, name, delimiter);
        std::getline(record_stream, role, delimiter);
        std::getline(record_stream, age_str);
        age = std::stoi(age_str);

        std::string eligibility = ""; // TODO: Determine eligibility for a junior position
        if(age < 40){
            eligibility = " - Eligible for junior position";
        }

        std::cout << "Name: " << name << " - Role: " << role << " - Age: " << age << eligibility << std::endl;
        // Example output: Name: Alice - Role: Developer - Age: 30 - Eligible for junior position
    }

    return 0;
}