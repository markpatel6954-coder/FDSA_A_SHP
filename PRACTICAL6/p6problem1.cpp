#include <iostream>
using namespace std;
class TrayStack {
    int stack[5];
    int top;
    int capacity;
public:
    TrayStack(int n) {
        capacity = n;
        top = -1;
    }
    void place(int tray) {
        if (top == capacity - 1) {
            cout << "Error: Stack is full" << endl;
            return;
        }
        stack[++top] = tray;
        cout << "Placed tray: " << tray << endl;
        cout << "Top tray: " << stack[top] << endl;
    }
    void take() {
        if (top == -1) {
            cout << "Error: Stack is empty" << endl;
            return;
        }
        cout << "Taken tray: " << stack[top--] << endl;
        if (top == -1)
            cout << "Top tray: None" << endl;
        else
            cout << "Top tray: " << stack[top] << endl;
    }
};
int main() {
    TrayStack trays(5);
    trays.place(101);
    trays.place(102);
    trays.place(103);
    trays.take();
    trays.take();
    trays.place(104);
    trays.place(105);
    return 0;
}