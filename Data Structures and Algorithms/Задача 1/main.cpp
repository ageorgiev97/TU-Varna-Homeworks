#include <iostream>

using std::cout;
using std::endl;

void generateAllPossibleNumbers(int number[6], int position){
    if(position==5){
        for (int i = 0; i < 6; i++) {
           cout<<number[i];
        }
        cout<<endl;
    }
    else{
        int sum = 0;
        for (int i = 0; i < position; i++) {
            sum+=number[i];
        }

        if(sum<=20){
            for (int i = 0; i <= 9; i++) {
                if(sum+i<=20){
                    number[position]=i;
                    generateAllPossibleNumbers(number,position+1);
                }
            }
        }
    }
}



int main(){
    int numbers[6]={0};
    generateAllPossibleNumbers(numbers,0);
    return 0;
}