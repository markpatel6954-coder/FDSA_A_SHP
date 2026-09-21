#include <iostream>
#include <vector>
using namespace std;


int iterativeSearch(vector<string> plates, string target) {
    for (int i = 0; i < plates.size(); i++) {
        if (plates[i] == target)
            return i;
    }
    return -1;
}


int recursiveSearch(vector<string> plates, string target, int index) {
    if (index == plates.size())
        return -1;

    if (plates[index] == target)
        return index;

    return recursiveSearch(plates, target, index + 1);
}

int main() {
    int n;
    cin >> n;

    vector<string> plates(n);

    for (int i = 0; i < n; i++) {
        cin >> plates[i];
    }

    string target;
    cin >> target;

    int iterativeResult = iterativeSearch(plates, target);
    int recursiveResult = recursiveSearch(plates, target, 0);

    cout << "Iterative position: " << iterativeResult << endl;
    cout << "Recursive position: " << recursiveResult << endl;

    return 0;
}