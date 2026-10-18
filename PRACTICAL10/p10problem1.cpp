#include <iostream>
using namespace std;
int main() {
    int slots[10] = {0}, n, reg;
    cin >> n;
    while (n--) {
        cin >> reg;
        int pos = reg % 10, start = pos;
        while (slots[pos] != 0) {
            pos = (pos + 1) % 10;
            if (pos == start) {
                cout << "Parking full\n";
                break;
            }
        }
        if (slots[pos] == 0)
            slots[pos] = reg;
    }
    for (int i = 0; i < 10; i++)
        cout << i << ": " << slots[i] << endl;
    return 0;
}