#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    queue<string> patients;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "arrive") {
            string patient;
            cin >> patient;
            patients.push(patient);
        }
        else if (operation == "attend") {
            if (!patients.empty()) {
                patients.pop();
            } else {
                cout << "Error: Ward is empty" << endl;
                continue;
            }
        }
        if (!patients.empty()) {
            cout << patients.front() << endl;
        } else {
            cout << "Ward is empty" << endl;
        }
    }
    return 0;
}
