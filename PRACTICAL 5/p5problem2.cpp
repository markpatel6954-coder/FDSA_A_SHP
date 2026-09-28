#include <iostream>
#include <string>
using namespace std;
struct SNode {
    string name;
    SNode* next;
    SNode(string n) {
        name = n;
        next = nullptr;
    }
};
class SinglyCircular {
private:
    SNode* head;
public:
    SinglyCircular() {
        head = nullptr;
    }
    void joinBeginning(string name) {
        SNode* newNode = new SNode(name);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;   // Points to itself
            return;
        }
        SNode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }
    void joinEnd(string name) {
        SNode* newNode = new SNode(name);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        SNode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
    void joinAfter(string student, string name) {
        if (head == nullptr) {
            cout << "Circle is empty.\n";
            return;
        }
        SNode* current = head;
        do {
            if (current->name == student) {
                SNode* newNode = new SNode(name);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Student " << student << " not found.\n";
    }
    void leave(string name) {
        if (head == nullptr) {
            cout << "Circle is empty.\n";
            return;
        }
        if (head->name == name && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        if (head->name == name) {
            SNode* last = head;
            while (last->next != head) {
                last = last->next;
            }
            SNode* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            return;
        }
        SNode* current = head;
        while (current->next != head) {
            if (current->next->name == name) {
                SNode* temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        cout << "Student " << name << " not found.\n";
    }
    void display() {
        if (head == nullptr) {
            cout << "Singly Circular: Empty\n";
            return;
        }
        cout << "Singly Circular: ";
        SNode* current = head;
        do {
            cout << current->name;
            current = current->next;
            if (current != head)
                cout << " -> ";
        } while (current != head);
        cout << " -> (back to " << head->name << ")\n";
    }
    ~SinglyCircular() {
        if (head == nullptr)
            return;
        SNode* current = head->next;
        while (current != head) {
            SNode* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
};
struct DNode {
    string name;
    DNode* next;
    DNode* prev;
    DNode(string n) {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyCircular {
private:
    DNode* head;
public:
    DoublyCircular() {
        head = nullptr;
    }
    void joinBeginning(string name) {
        DNode* newNode = new DNode(name);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        DNode* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    void joinEnd(string name) {
        DNode* newNode = new DNode(name);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        DNode* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    void joinAfter(string student, string name) {
        if (head == nullptr) {
            cout << "Circle is empty.\n";
            return;
        }
        DNode* current = head;
        do {
            if (current->name == student) {
                DNode* newNode = new DNode(name);
                DNode* nextNode = current->next;
                newNode->prev = current;
                newNode->next = nextNode;
                current->next = newNode;
                nextNode->prev = newNode;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Student " << student << " not found.\n";
    }
    void leave(string name) {
        if (head == nullptr) {
            cout << "Circle is empty.\n";
            return;
        }
        DNode* current = head;
        do {
            if (current->name == name) {
                if (current->next == current) {
                    delete current;
                    head = nullptr;
                    return;
                }
                DNode* previous = current->prev;
                DNode* nextNode = current->next;
                previous->next = nextNode;
                nextNode->prev = previous;
                if (current == head) {
                    head = nextNode;
                }
                delete current;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Student " << name << " not found.\n";
    }
    void display() {
        if (head == nullptr) {
            cout << "Doubly Circular: Empty\n";
            return;
        }
        cout << "Doubly Circular: ";
        DNode* current = head;
        do {
            cout << current->name;
            current = current->next;
            if (current != head)
                cout << " <-> ";
        } while (current != head);
        cout << " <-> (back to " << head->name << ")\n";
    }
    ~DoublyCircular() {
        if (head == nullptr)
            return;
        DNode* current = head->next;
        while (current != head) {
            DNode* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
};
int main() {
    SinglyCircular singleCircle;
    DoublyCircular doubleCircle;
    cout << "========== JOIN STUDENTS ==========\n";
    singleCircle.joinEnd("Alice");
    doubleCircle.joinEnd("Alice");
    singleCircle.display();
    doubleCircle.display();
    cout << "\n";
    singleCircle.joinEnd("Bob");
    doubleCircle.joinEnd("Bob");
    singleCircle.display();
    doubleCircle.display();
    cout << "\n";
    singleCircle.joinEnd("Charlie");
    doubleCircle.joinEnd("Charlie");
    singleCircle.display();
    doubleCircle.display();
    cout << "\n===INSERT AFTER===\n";
    singleCircle.joinAfter("Alice", "David");
    doubleCircle.joinAfter("Alice", "David");

    singleCircle.display();
    doubleCircle.display();

    cout << "\n===LEAVE===\n";
    singleCircle.leave("Bob");
    doubleCircle.leave("Bob");
    singleCircle.display();
    doubleCircle.display();
    cout << "\n========== HEAD LEAVES ==========\n";
    singleCircle.leave("Alice");
    doubleCircle.leave("Alice");
    singleCircle.display();
    doubleCircle.display();
    cout << "\n========== LAST STUDENTS LEAVE ==========\n";
    singleCircle.leave("Charlie");
    doubleCircle.leave("Charlie");
    singleCircle.display();
    doubleCircle.display();
    singleCircle.leave("David");
    doubleCircle.leave("David");
    singleCircle.display();
    doubleCircle.display();
    return 0;
}