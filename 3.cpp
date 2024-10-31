#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Travel Packing List and Selection
    std::vector<std::string> packing_list = {"clothes", "toothbrush", "passport", "camera"};
    std::string item_to_check = "passport";
    bool is_item_packed = false;
    int item_index = -1;

    // TODO: Check if the item_to_check is in the packing_list and find its index
    // TODO: If the item is not in the list, keep item_index as -1

    // Print out the results
    std::cout << "Is the item packed? " << std::boolalpha << is_item_packed << std::endl;
    std::cout << "Item index: " << item_index << std::endl;

    return 0;
}