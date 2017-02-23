// Programing Basics 2: Lecture 2
// Example problems with recursion

#include <iostream>

using std::cout;
using std::endl;

void printVertical(int number){ //recursive function that print vertically Integer
    if(number<10) { //When the number is below 10 the function prints the last number
        cout << number << endl;
    }
    else {
        printVertical(number / 10); //we are calling the same function with number with one less digit
        cout << number % 10 << endl;
    }
}

void printPow(double number, double powNumber) { //recursive function that calculates number^powNumber
    if(powNumber==1){
        cout << number << endl;
    }
    else if(powNumber==0){
        cout << 1 << endl;
    }
    else{
        printPow(number*number,--powNumber);
    }

}

int printPowAlternative(int number, int powNumber) { //alternative function that calculates number^powNumber
    if(powNumber==1){
       return(number);
    }
    else if(powNumber>0){
        return(printPowAlternative(number, powNumber - 1)*number);
    }
    else{
        return 1;
    }

}

int factorial(int number){ //recursive function that calculates factorial of Integer
    if(number>1){
        return factorial(number-1)*number;
    }
    else if(number==1){
        return number;
    }
}

int main() {
    //Tests
    printVertical(1997);

    printPow(2.0,4);

    cout<< printPowAlternative(2, 8)<<endl;

    cout<< factorial(5)<<endl;

    return 0;
}

