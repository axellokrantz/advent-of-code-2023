#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Travel Packing List and Selection
    vector<string> packing_list = {"clothes", "toothbrush", "passport", "camera"};
    string item_to_check = "passport";
    bool is_item_packed = false;
    int item_index = -1;

    // TODO: Check if the item_to_check is in the packing_list and find its index
    // TODO: If the item is not in the list, keep item_index as -1

    auto it = find(packing_list.begin(), packing_list.end(), item_to_check);
    if(it != packing_list.end()){
        item_index = it - packing_list.begin();
        is_item_packed = true;
    }

    // Print out the results
    cout << "Is the item packed? " << boolalpha << is_item_packed << endl;
    cout << "Item index: " << item_index << endl;

    return 0;
}