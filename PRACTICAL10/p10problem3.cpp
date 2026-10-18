#include <iostream>
using namespace std;
int main() {
    const int SIZE = 10;
    int table[SIZE], n, id;
    fill(table, table + SIZE, -1);
    cin >> n;
    while (n--) {
        cin >> id;
        int h1 = id % SIZE;
        int h2 = 7 - (id % 7);
        int i = 0;
        while (i < SIZE && table[(h1 + i * h2) % SIZE] != -1)
            i++;
        if (i < SIZE)
            table[(h1 + i * h2) % SIZE] = id;
        else
            cout << "Hash table full: " << id << endl;
    }
    for (int i = 0; i < SIZE; i++)
        cout << i << ": " << table[i] << endl;
    return 0;
}