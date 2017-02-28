#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct TreeItem {
    int value;
    TreeItem *left;
    TreeItem *right;

    TreeItem() {
        this->left = nullptr;
        this->right = nullptr;
    }

    int insert(int value){
        if (this->value > value) {
            if (this->left != nullptr) {
                return this->left->insert(value) + 1;
            } else {
                this->left = new TreeItem();
                this->left->value = value;
                return 1;
            }
        } else if (this->value < value) {
            if (this->right != nullptr) {
                return this->right->insert(value) + 1;
            }
            else {
                this->right = new TreeItem();
                this->right->value=value;
                return 1;
            }
        }
        return 0;
    }

    void print() {
        if (this->left != nullptr) {
            this->left->print();
        }

        cout << ' ' <<  this->value << ' ';

        if (this->right != nullptr) {
            this->right->print();
        }
    }

    int sumChildren(){
        int sum =0;
        if(this->right!= nullptr){
            sum+=this->right->value;
        }
        if(this->left!= nullptr){
            sum+=this->left->value;
        }
        return sum;
    }

    int sumLevel(int level, int target) {
        if (++level != target) {
            int sum = 0;

            if(this->right!= nullptr){
                sum+=this->right->sumLevel(level, target);
            }

            if(this->left!= nullptr){
                sum+=this->left->sumLevel(level, target);
            }

            return sum;
        }

        return sumChildren();
    }
};

class BinaryTree{
private:
    TreeItem *root;
    int levels;

public:
    BinaryTree(){
        this->root = nullptr;
    }

    void insertItem(int value){
        if (this->root== nullptr){
            this->root = new TreeItem();
            this->root->value=value;
            this->levels=1;
        }
        else{
            int lvl = root->insert(value);

            if (lvl+1 > this->levels)
                this->levels = lvl+1;
        }
    }

    void print() {
        root->print();
    }

    int getLevels() const {
        return levels;
    }


    void printSumAtLevel(int target) {
        if(target==0){
            cout << this->root->value << endl;
        }
        else {
            cout << this->root->sumLevel(0, target) << endl;
        }
    }

    void printSumOfLevels() {
        int lvl = this->getLevels();
        int sum = 0;
        while (lvl)
            sum += lvl--;

        cout << sum << endl;
    }
};

int main() {
    BinaryTree a = BinaryTree();


    int input;


    do{
        cout<<"Chose an option from the menu:"<<endl;
        cout<<"1. Add element to the binary tree"<<endl;
        cout<<"2. Print sum of levels"<<endl;
        cout<<"3. Exit"<<endl;

        cin>>input;

        switch(input){
            case 1:
                int valuesToAdd;
                cout<<"How much values you want to add?"<<endl;
                cin>>valuesToAdd;

                while (valuesToAdd--){
                    int tmp;
                    cin>>tmp;
                    a.insertItem(tmp);
                }


                break;
            case 2:
                cout<<"Sum of levels:"<<endl;
                a.printSumOfLevels();
                break;
            case 3:
                cout<<"Bye!"<<endl;
                break;
            default:
                cout<<"Incorect Value!"<<endl;

        }

    }while(input!=3);



    return 0;
}
