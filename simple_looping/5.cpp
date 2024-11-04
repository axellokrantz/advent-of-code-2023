#include <iostream>

int solution(int n) {
    
    int reversedNumber = 0;

    while(n > 0){

        while(n % 10 == 0){
            n /= 10;
        }
        int number = n % 10;
        reversedNumber = reversedNumber * 10 + number; 
        n /= 10;
    }
    
    

    // TODO: implement the solution here
    return reversedNumber; // Placeholder return
}

int main(){
    //1230 = 321
    int n = 1230;
    std::cout << solution(n);
}