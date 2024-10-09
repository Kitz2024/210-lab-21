//Kit Pollinger
//210-Lab-21 | Goat Herd Manager 3000

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

int main (){
    DoublyLinkedList list;
    list.push_back(Goat("Snior", "Yellow", 6));
    list.push_back(Goat("Godlike", "Red", 7));
    list.push_back(Goat("Old", "Red", 2));
    list.push_back(Goat("Old", "Gold", 6));
    list.push_back(Goat("Mature", "Mauve", 6));
    list.push_back(Goat("Teen", "Gold", 10));
    list.push_back(Goat("Teen", "White", 17));
    cout << "Forward:" << endl;
    list.printForward();

    cout << "\nBackward:" << endl;
    list.printBackward();
    
    return 0;
}