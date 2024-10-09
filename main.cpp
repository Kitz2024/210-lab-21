//Kit Pollinger
//210-Lab-21 | 



//
//210-Demo-Chair-1
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Goat {
    string name;
    string color;
    int age;

    Goat(const string& name, const string& color, int age) : name(name), color(color), age(age){}
};

class DoublyLinkedList{
    public:
    DoublyLinkedList() : head(nullptr), tail(nullptr){}
    void push_back(const Goat& goat) {
        Node* newNode = new Node(goat);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void printForward() const {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << "  " << current->data.name << " (" << current->data.color << ", " << current->data.age << ")" << endl;
            current = current->next;
        }
    }

    void printBackward() const {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = tail;
        while (current != nullptr) {
            cout << "  " << current->data.name << " (" << current->data.color << ", " << current->data.age << ")" << endl;
            current = current->prev;
        }
    }
    private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;

        Node(const Goat& goat) : data(goat), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
};



const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = 0;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
    }
    Chair(int l) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    collection[0].setLegs(4);
    collection[0].setPrices(441.41, 552.52, 663.63);
    collection[1].setLegs(4);
    collection[1].setPrices(484.84, 959.59, 868.68);
    collection[2].setLegs(4);
    collection[2].setPrices(626.26, 515.15, 757.57);
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}