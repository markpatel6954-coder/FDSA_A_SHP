#include <iostream>
#include <string>
using namespace std;
struct Node {
    string song;
    Node* prev;
    Node* next;
    Node(string s) {
        song = s;
        prev = nullptr;
        next = nullptr;
    }
};
class Playlist {
private:
    Node* head;
    Node* tail;
    int count;
public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    void addFirst(string song) {
        Node* newNode = new Node(song);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;   // Extra step in doubly linked list
            head = newNode;
        }
        count++;
    }
    void addLast(string song) {
        Node* newNode = new Node(song);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    void insertAfter(string target, string song) {
        Node* current = head;
        while (current != nullptr && current->song != target) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Song \"" << target << "\" not found. "
                 << "\"" << song << "\" not inserted.\n";
            return;
        }
        Node* newNode = new Node(song);
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        count++;
    }
    void removeFirst() {
        if (head == nullptr) {
            cout << "Playlist is empty. Nothing to remove.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        count--;
    }
    int size() {
        return count;
    }
    void display() {
        Node* current = head;
        cout << "Playlist: ";
        if (current == nullptr) {
            cout << "Empty";
        }
        while (current != nullptr) {
            cout << current->song;
            if (current->next != nullptr)
                cout << " -> ";
            current = current->next;
        }
        cout << "\n";
        cout << "Number of songs: " << count << "\n";
    }
    ~Playlist() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};
int main() {
    Playlist playlist;
    playlist.addFirst("Song A");
    playlist.display();
    cout << "\n";
    playlist.addLast("Song C");
    playlist.display();
    cout << "\n";
    playlist.insertAfter("Song A", "Song B");
    playlist.display();
    cout << "\n";
    playlist.insertAfter("Song C", "Song D");
    playlist.display();
    cout << "\n";
    playlist.removeFirst();
    playlist.display();
    cout << "\n";
    playlist.insertAfter("Song X", "Song E");
    playlist.display();
    return 0;
}