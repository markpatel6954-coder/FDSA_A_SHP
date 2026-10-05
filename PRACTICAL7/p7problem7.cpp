#include <iostream>
using namespace std;
class Queue {
    int *arr;
    int n;
    int front, rear, count;
public:
    Queue(int size) {
        n = size;
        arr = new int[n];
        front = 0;
        rear = -1;
        count = 0;
    }
    void join(int token) {
        if (count == n) {
            cout << "Error: Queue is full\n";
            return;
        }
        rear = (rear + 1) % n;
        arr[rear] = token;
        count++;
        cout << "Front: " << arr[front] << endl;
    }
    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty\n";
            return;
        }
        front = (front + 1) % n;
        count--;
        if (count > 0)
            cout << "Front: " << arr[front] << endl;
        else
            cout << "Front: Empty" << endl;
    }
    ~Queue() {
        delete[] arr;
    }
};
int main() {
    int n, operations;
    cin >> n;
    cin >> operations;
    Queue q(n);
    for (int i = 0; i < operations; i++) {
        char op;
        cin >> op;
        if (op == 'J') {
            int token;
            cin >> token;
            q.join(token);
        }
        else if (op == 'S') {
            q.serve();
        }
    }
    return 0;
}