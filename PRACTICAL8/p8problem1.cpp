#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}
void preorder(Node* r) {
    if (!r) return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}
void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}
void levelorder(Node* r) {
    if (!r) return;
    queue<Node*> q;
    q.push(r);
    while (!q.empty()) {
        Node* t = q.front();
        q.pop();
        cout << t->data << " ";
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Inorder: ";    inorder(root);
    cout << "\nPreorder: ";  preorder(root);
    cout << "\nPostorder: "; postorder(root);
    cout << "\nLevel order: "; levelorder(root);
    return 0;
}