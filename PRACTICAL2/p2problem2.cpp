#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> books(n);
    unordered_map<int, int> count;

    
    for (int i = 0; i < n; i++) {
        cin >> books[i];
        count[books[i]]++;
    }

    
    unordered_map<int, bool> printed;

    for (int i = 0; i < n; i++) {
        if (count[books[i]] > 1 && !printed[books[i]]) {
            cout << books[i] << " ";
            printed[books[i]] = true;
        }
    }

    return 0;
}