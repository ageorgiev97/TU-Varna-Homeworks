#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;


struct Node;

struct Link{
    Node *to;
    int price;

    Link(Node *to, int price){
        this->to=to;
        this->price=price;
    }
};


struct Node{
    string name;
    vector<Link> links;
    bool visited;
    int price;

    Node(string name){
        this->visited = false;
        this->name=name;
    }


    void addLink(Link a){
        this->links.push_back(a);
    }
};

int main() {
    vector<Node> graph;

    int input;

    do{
        cout<<"Chose an option from the menu:"<<endl;
        cout<<"1. Add nodes"<<endl;
        cout<<"2. Add links"<<endl;
        cout<<"3. Find the longest path"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>input;

        switch(input) {
            case 1:
                cout << "How many nodes?" << endl;
                int nodesCount;
                cin >> nodesCount;
                while (nodesCount--) {
                    string nodeName;
                    cout << "Node name:" << endl;
                    cin >> nodeName;
                    graph.push_back(Node(nodeName));
                }
                break;
            case 2:
                cout << "How many links?" << endl;
                int linksCount;
                cin >> linksCount;
                while (linksCount--) {
                    string nodeFrom;
                    string nodeTo;
                    int distance;
                    cout << "From:" << endl;
                    cin >> nodeFrom;
                    cout << "To:" << endl;
                    cin >> nodeTo;
                    cout << "Distance:" << endl;
                    cin >> distance;

                    distance *= -1;

                    Node *foundFrom;
                    Node *foundTo;

                    for (Node &a : graph) {
                        if (a.name == nodeFrom) {
                            foundFrom = &a;
                            break;
                        }
                    }

                    for (Node &a : graph) {
                        if (a.name == nodeTo) {
                            foundTo = &a;
                            break;
                        }
                    }

                    Link linkOne = Link(foundTo, distance);

                    foundFrom->addLink(linkOne);



                }

                break;
            case 3:
            {

                string nodeFrom;
                string nodeTo;
                cout << "Enter start city: " << endl;
                cin >> nodeFrom;
                cout << "Enter end city: " << endl;
                cin >> nodeTo;

                for (Node &a : graph) {
                    a.price = INT32_MAX;
                }

                Node *foundFrom;
                Node *foundTo;

                for (Node &a : graph) {
                    if (a.name == nodeFrom) {
                        foundFrom = &a;
                        break;
                    }
                }

                for (Node &a : graph) {
                    if (a.name == nodeTo) {
                        foundTo = &a;
                        break;
                    }
                }

                vector<Node *> potential;
                foundFrom->visited = true;
                foundFrom->price = 0;

                for (auto const &link : foundFrom->links) {
                    potential.push_back(link.to);
                    link.to->price = link.price;
                }

                while (potential.size()) {
                    int cost = INT32_MAX;
                    Node *next;

                    for (Node *&n: potential) {
                        if (cost > n->price) {
                            next = n;
                            cost = n->price;
                        }
                    }

                    next->visited = true;

                    for (auto const &link : next->links) {
                        if (!link.to->visited &&
                            std::find(potential.begin(), potential.end(), link.to) == potential.end()) {
                            potential.push_back(link.to);
                        }
                        link.to->price = std::min(link.to->price, next->price + link.price);
                    }

                    potential.erase(std::remove(potential.begin(), potential.end(), next), potential.end());
                }
                cout << "Max distance: " << foundTo->price * -1 << endl;

            }
                break;
            case 4:
                cout << "Bye!" << endl;
                break;
            default:
                cout<<"Incorrect Value!"<<endl;

        }

    }while(input!=4);



    return 0;
}
