#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULLptr;
        rear = NULLptr;
    }
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULLptr;
        newNode->prev = rear;
        if (front == NULLptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void deleteValue(int value) {
        Node* temp = front;
        while (temp != NULLptr && temp->data != value) {
            temp = temp->next;
        }
        if (temp == NULLptr) {
            cout << "Patient token not found." << endl;
            return;
        }
        if (temp == front)
            front = temp->next;
        if (temp == rear)
            rear = temp->prev;
        if (temp->prev != NULLptr)
            temp->prev->next = temp->next;
        if (temp->next != NULLptr)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Patient token deleted." << endl;
    }
    void forwardPrint() {
        Node* temp = front;
        cout << "Queue (Front to Back): ";
        while (temp != NULLptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reversePrint() {
        Node* temp = rear;
        cout << "Queue (Back to Front): ";
        while (temp != NULLptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    q.insert(101);
    q.insert(102);
    q.insert(103);
    q.insert(104);
    q.insert(105);
    cout << "Original queue:" << endl;
    q.forwardPrint();
    cout << "\nReverse queue:" << endl;
    q.reversePrint();
    cout << "\nDeleting patient token 103..." << endl;
    q.deleteValue(103);
    cout << "\nQueue after deletion:" << endl;
    q.forwardPrint();
    cout << "\nReverse printing after deletion:" << endl;
    q.reversePrint();
    return 0;
}