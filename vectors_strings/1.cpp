#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    // Start by creating a vector representing suitcase items
    std::vector<std::string> suitcase = {"shirt", "shorts", "toothbrush", "shoes"};

    // Let's add "sunglasses" at the end of our suitcase
    suitcase.push_back("sunglasses");

    // Oops! We forgot socks. Let's insert socks at index 2
    suitcase.insert(suitcase.begin() + 2, "socks");
    std::cout << "Updated suitcase: ";
    for(const auto& item : suitcase) std::cout << item << " ";
    std::cout << std::endl;

    // Now, let's get the first and the last item from the suitcase
    std::string first_item = suitcase[0]; // 'shirt'
    std::string last_item = suitcase[suitcase.size() - 1]; // 'sunglasses'
    std::cout << first_item << " " << last_item << std::endl;

    // Finally, let's remove "toothbrush" as we prefer to buy a new one at our destination
    suitcase.erase(std::remove(suitcase.begin(), suitcase.end(), "toothbrush"), suitcase.end());
    std::cout << "Final suitcase contents: ";
    for(const auto& item : suitcase) std::cout << item << " ";
    std::cout << std::endl;

    return 0;
}