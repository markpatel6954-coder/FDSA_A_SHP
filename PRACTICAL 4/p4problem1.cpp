#include <iostream>
#include <deque>
using namespace std;
int main() {
    deque<int> q;
    int n;
    cout << "Enter number of operations: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int type, patient, pos;
        cout << "\nEnter operation type (1=Front, 2=End, 3=Position): ";
        cin >> type;
        if (type == 1) {
            cin >> patient;
            q.push_front(patient);
        }
        else if (type == 2) {
            cin >> patient;
            q.push_back(patient);
        }
        else if (type == 3) {
            cin >> patient >> pos;
            if (pos >= 0 && pos <= q.size()) {
                q.insert(q.begin() + pos, patient);
            }
            else {
                cout << "Invalid position!" << endl;
            }
        }
        cout << "Queue: ";
        for (int x : q) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}