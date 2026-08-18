#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

   
    int shift = h % n;

   
    for (int i = shift; i < n; i++) {
        cout << a[i] << " ";
    }

   
    for (int i = 0; i < shift; i++) {
        cout << a[i] << " ";
    }

    return 0;
}