#include <vector>
#include <iostream>

std::vector<int> unusual_traversal(const std::vector<int>& array) {
    if (array.empty()) return {};
    
    std::vector<int> result;
    size_t mid = array.size() / 2;
    // Change to size_t (which is unsigned) to match vector::size() type
    size_t left, right;

    if (array.size() % 2 != 0) {
        // Odd length array
        result.push_back(array[mid]);
        left = mid - 1;
        right = mid + 1;
    } else {
        // Even length array
        result.push_back(array[mid - 1]);
        result.push_back(array[mid]);
        left = mid - 2;
        right = mid + 1;
    }

    // Use comparison with SIZE_MAX instead of >= 0 for unsigned type
    while (left != SIZE_MAX && right < array.size()) {
        // Process left side
        if (left != SIZE_MAX) {
            if (left >= 1) {
                result.push_back(array[left - 1]);
                result.push_back(array[left]);
                left -= 2;
            } else {
                result.push_back(array[left]);
                left = SIZE_MAX;  // This replaces left -= 1 for unsigned
            }
        }

        // Process right side
        if (right < array.size()) {
            if (right < array.size() - 1) {
                result.push_back(array[right]);
                result.push_back(array[right + 1]);
                right += 2;
            } else {
                result.push_back(array[right]);
                right++;
            }
        }
    }

    return result;
}

int main() {
    std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    auto result = unusual_traversal(test);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}