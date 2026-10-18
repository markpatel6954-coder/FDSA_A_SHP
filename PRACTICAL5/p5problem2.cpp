#include <iostream>
#include <string>
using namespace std;
class SinglyCircular {
    struct Node {
        string name;
        Node* next;
        Node(string n) {
            name = n;
            next = nullptr;
        }
    };
    Node* head;
public:
    SinglyCircular() {
        head = nullptr;
    }
    void join(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    void leave(string name) {
        if (head == nullptr)
            return;
        if (head->next == head) {
            if (head->name == name) {
                delete head;
                head = nullptr;
            }
            return;
        }
        Node* current = head;
        Node* previous = nullptr;
        do {
            if (current->name == name) {
                if (current == head) {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }
    void display() {
        if (head == nullptr) {
            cout << "Singly Circular: Empty" << endl;
            return;
        }
        cout << "Singly Circular: ";
        Node* temp = head;
        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

class DoublyCircular {
    struct Node {
        string name;
        Node* next;
        Node* prev;
        Node(string n) {
            name = n;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node* head;
public:
    DoublyCircular() {
        head = nullptr;
    }
    void join(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    void leave(string name) {
        if (head == nullptr)
            return;
        Node* current = head;
        do {
            if (current->name == name) {
                if (current->next == current) {
                    delete current;
                    head = nullptr;
                    return;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == head) {
                    head = current->next;
                }
                delete current;
                return;
            }
            current = current->next;
        } while (current != head);
    }
    void display() {
        if (head == nullptr) {
            cout << "Doubly Circular: Empty" << endl;
            return;
        }
        cout << "Doubly Circular: ";
        Node* temp = head;
        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main() {
    SinglyCircular singly;
    DoublyCircular doubly;
    cout << "Join Alice" << endl;
    singly.join("Alice");
    doubly.join("Alice");
    singly.display();
    doubly.display();
    cout << "\nJoin Bob" << endl;
    singly.join("Bob");
    doubly.join("Bob");
    singly.display();
    doubly.display();
    cout << "\nJoin Charlie" << endl;
    singly.join("Charlie");
    doubly.join("Charlie");
    singly.display();
    doubly.display();
    cout << "\nJoin David" << endl;
    singly.join("David");
    doubly.join("David");
    singly.display();
    doubly.display();
    cout << "\nLeave Charlie" << endl;
    singly.leave("Charlie");
    doubly.leave("Charlie");
    singly.display();
    doubly.display();
    cout << "\nLeave manav" << endl;
    singly.leave("manav");
    doubly.leave("manav");
    singly.display();
    doubly.display();
    cout << "\nJoin priyam" << endl;
    singly.join("priyam");
    doubly.join("priyam");
    singly.display();
    doubly.display();
    cout << "\nLeave bomb" << endl;
    singly.leave("bomb");
    doubly.leave("bomb");
    singly.display();
    doubly.display();
    return 0;
}
