#include <iostream>

using std::cout;
using std::endl;
using std::cin;

template <typename T>
class Deque{
private:
    T *arr;
    int numberOfElementsInside;
    int capacity;

public:
    Deque(int size) {
        this->arr=new T[size];
        this->capacity=size+1;
        this->numberOfElementsInside=0;
    }

    ~Deque(){
        delete[] arr;
    }

    void pushRight(T element){
        if(numberOfElementsInside+1>=capacity){
            cout<<"Stack Overflow Exception!"<<endl;
        }
        else{
            arr[numberOfElementsInside]=element;
            numberOfElementsInside++;
        }
    }

    void removeLast(){
        if(numberOfElementsInside==0){
            cout<<"The Deque Is Empty!"<<endl;
        }
        else{
            numberOfElementsInside--;
        }
    }

    int peekLast(){
        if(numberOfElementsInside==0){
            cout<<"The Deque Is Empty!"<<endl;
            throw std::exception();
        }
        else{
            return arr[numberOfElementsInside-1];
        }
    }

    void pushLeft(T element){
        if(numberOfElementsInside+1>=capacity){
            cout<<"Stack Overflow Exception!"<<endl;
        }
        else{
            for (int i = numberOfElementsInside+1; i > 0; i--) {
                arr[i]=arr[i-1];
            }
            arr[0]=element;
            numberOfElementsInside++;
        }
    }

    void removeFirst(){
        if(numberOfElementsInside==0){
            cout<<"The Deque Is Empty!"<<endl;
        }
        else{
            for (int i = 0; i < numberOfElementsInside; i++) {
                arr[i]=arr[i+1];
            }

            numberOfElementsInside--;
        }

    }

    int peekFirst(){
        if(numberOfElementsInside==0){
            cout<<"The Deque Is Empty!"<<endl;
            throw std::exception();
        }
        else{
            return arr[0];
        }
    }

    T popLeft(){
        if (numberOfElementsInside == 0) {
            cout<<"The Deque Is Empty!"<<endl;
            throw std::exception();
        }
        else {
            T tmp = peekFirst();
            removeFirst();
            return tmp;
        }
    }
    T popRight(){
        if (numberOfElementsInside == 0) {
            cout<<"The Deque Is Empty!"<<endl;
            throw std::exception();
        }
        else {
            T tmp = peekLast();
            removeLast();
            return tmp;
        }
    }


};


int main(){

    Deque<int> a= Deque<int>(5);

    int input;
    int tmp;

    cout<<"Chose an option from the menu:"<<endl;
    cout<<"1. Push element to Right"<<endl;
    cout<<"2. Push element to Left"<<endl;
    cout<<"3. Pop element from Right"<<endl;
    cout<<"4. Pop element from Left"<<endl;
    cout<<"5. Exit"<<endl;

    do{
        cin>>input;

        switch(input){
            case 1:
                cin>>tmp;
                a.pushRight(tmp);
                break;
            case 2:
                cin>>tmp;
                a.pushLeft(tmp);
                break;
            case 3:
                cout<<"Poped from the right:"<<endl;
                cout<<a.popRight()<<endl;
                break;
            case 4:
                cout<<"Poped from the left:"<<endl;
                cout<<a.popLeft()<<endl;
                break;
            case 5:
                cout<<"Bye!"<<endl;
                break;
            default:
                cout<<"Incorect Value!"<<endl;

        }

    }while(input!=5);

    return 0;
}