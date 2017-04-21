#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;


struct Item{
    string name;
    double price;
    int amount;
};


void addItems(Item *arr, int &itemsCount, int &itemsToAdd){
    for (int i = 0; i < itemsToAdd; i++) {

        if(itemsCount > 30) {
            cout << "The shop is full!" << endl;
            break;
        }

        string name;
        double price;
        int amount;

        cout<<"Item number "<<itemsCount + 1<<": "<<endl;

        cout<<"Name:"<<endl;
        cin>>name;

        cout<<"Price:"<<endl;
        cin>>price;

        cout<<"Amount:"<<endl;
        cin>>amount;

        Item tmp;
        tmp.name = name;
        tmp.price = price;
        tmp.amount = amount;

        arr[itemsCount] = tmp;
        itemsCount++;

    }
}

void findAndPrintItemByPrice(Item *arr, int &itemsCount, double price){
    for (int i = 0; i < itemsCount; i++) {
        if(arr[i].price == price){
            cout<<"Name: "<<arr[i].name<<endl;
            cout<<"Amount: "<<arr[i].amount<<endl;
            cout<<"Price: "<<arr[i].price<<endl;
            cout<<endl;
        }
    }
}


int main() {

    Item allItems[30];
    int itemsCount = 0;
    int input;

    do{
        cout<<"Chose an option from the menu:"<<endl;
        cout<<"1. Add items"<<endl;
        cout<<"2. Find item by price"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>input;

        switch(input) {
            case 1:
                int itemsToAdd;
                cout<<"How much items you want to add?"<<endl;
                cin>>itemsToAdd;
                addItems(allItems, itemsCount, itemsToAdd);

                break;
            case 2:
                double priceToFind;
                cout<<"Look for price:"<<endl;
                cin>>priceToFind;
                findAndPrintItemByPrice(allItems, itemsCount, priceToFind);
                break;
            case 3:
                cout<<"Bye!"<<endl;
                break;
            default:
                cout<<"Incorrect Value!"<<endl;

        }

    }while(input!=3);



    return 0;
}
