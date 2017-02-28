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
    Node *from;
    Node *to;
    int price;

    Link(Node *from, Node *to, int price){
        this->from=from;
        this->to=to;
        this->price=price;
    }
};


struct Node{
    string name;
    vector<Link> links;
    bool visited;
    int price = 0;

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
        cout<<"1. Add nodes."<<endl;
        cout<<"2. Add links"<<endl;
        cout<<"3. Pop element from Right"<<endl;
        cout<<"4. Pop element from Left"<<endl;
        cout<<"5. Exit"<<endl;
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

                    Link linkOne = Link(foundFrom, foundTo, distance);
                    Link linkTwo = Link(foundTo, foundFrom, distance); //maybe

                    foundFrom->addLink(linkOne);
                    foundTo->addLink(linkTwo);


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

                for (auto const &link : foundFrom->links) {
                    potential.push_back(link.to);
                }

                while (potential.size() > 0) {
                    int cost = 0;
                    Node *next;

                    for (auto const n: potential) {
                        for (auto const &link : n->links) {
                            if (link.price > cost && link.to->visited) {
                                cost = link.price;
                                next = link.from;
                            } //else if (!link.to->visited)
                                //potential.erase(std::remove(potential.begin(), potential.end(), link.to), potential.end());
                            if (link.to->price + link.price > link.from->price)
                                link.from->price = link.from->price + link.price;
                        }
                    }

                    next->visited = true;

                    for (auto const &link : next->links) {
                        if (!link.to->visited && std::find(potential.begin(), potential.end(), link.to) == potential.end())
                            potential.push_back(link.to);
                    }

                    potential.erase(std::remove(potential.begin(), potential.end(), next), potential.end());
                }

                cout << foundTo->price << endl;

        }
                break;
            case 4:

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
