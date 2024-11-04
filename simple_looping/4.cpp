#include <iostream>

int solution(int n) {
    int product = 1;
    bool oddNumber = false;

    while(n > 0){
        int number = n % 10;
        if(number % 2 != 0){
            oddNumber = true;
            product *= number;
        }
        n /= 10;
    }
    
    if(oddNumber) {
        return product;
    }

    return 0;
}

int main() {
    int i = 43172;
    std::cout << solution(i);
}