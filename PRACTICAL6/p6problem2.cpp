#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<string> history;
    string currentPage = "Home";
    int n;
    cout << "Enter number of operations: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "visit") {
            string page;
            cin >> page;
            history.push_back(currentPage);
            currentPage = page;
        }
        else if (operation == "back") {
            if (!history.empty()) {
                currentPage = history.back();
                history.pop_back();
            }
            else {
                cout << "No history left. Cannot go back." << endl;
            }
        }
        cout << "Current page: " << currentPage << endl;
    }
    return 0;
}

