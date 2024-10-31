#include <iostream>
#include <vector>

int main() {
    std::vector<int> temperatures = {25, 30, 18, 22, 30, 35};

    // TODO: break the loop when encountering a temperature under 20
    for (int temp : temperatures) {
        if (temp > 32) {
            std::cout << "It is very hot." << std::endl;
            break;
        } else if (temp > 25) {
            std::cout << "It is warm outside." << std::endl;
            continue;
        }
        else if (temp < 20){
            break;
        }
        std::cout << "Might be chilly, dress appropriately." << std::endl;
    }
    return 0;
}