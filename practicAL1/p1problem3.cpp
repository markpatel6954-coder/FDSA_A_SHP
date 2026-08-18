#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);

    string word, longest = "";
    stringstream ss(sentence);

    while (ss >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }

    cout << longest << " " << longest.length();

    return 0;
}