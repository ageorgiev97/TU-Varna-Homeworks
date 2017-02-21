#include <iostream>

using std::cout;
using std::endl;

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

    a.pushRight(1);
    a.pushLeft(2);
    a.pushRight(3);

    cout<<a.popRight()<<endl;
    cout<<a.popLeft()<<endl;
    cout<<a.popRight()<<endl;

    return 0;
}