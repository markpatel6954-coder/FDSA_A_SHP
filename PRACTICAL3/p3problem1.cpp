#include <iostream>
#include <vector>
using namespace std;


void bubbleSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}


void selectionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        swap(a[i], a[minIndex]);
    }
}


void insertionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void printArray(vector<int> a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    vector<int> c = a;

    bubbleSort(a);
    selectionSort(b);
    insertionSort(c);

    cout << "Bubble Sort: ";
    printArray(a);

    cout << "Selection Sort: ";
    printArray(b);

    cout << "Insertion Sort: ";
    printArray(c);

    return 0;
}