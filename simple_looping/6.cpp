#include <iostream>

int solution(int n) {

    int count = 0;
    while(n > 0){
        int first = n % 10;
        n /= 10;
        int second = n % 10;
        if(first == second){
            count++;
        }
    }
    return count;
}


int main() {
    int i = 11322488;
    std::cout << solution(i);
}