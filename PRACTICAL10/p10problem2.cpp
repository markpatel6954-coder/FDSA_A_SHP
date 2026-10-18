#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> shelf[10];
    int n, code;
    cin >> n;
    while (n--) {
        cin >> code;
        shelf[code % 10].push_back(code);
    }
    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";
        for (int x : shelf[i])
            cout << x << " ";
        cout << endl;
    }
    return 0;
}