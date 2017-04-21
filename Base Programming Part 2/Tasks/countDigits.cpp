#include <iostream>

int countDigits(int number){
    if(number < 10)
        return 1;
    return countDigits(number / 10) + 1;
}


int main() {
    int number;
    std::cin >> number;

    std::cout << countDigits(number) << std::endl;
	
    return 0;
}
