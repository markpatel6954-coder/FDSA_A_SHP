#include <iostream>
using namespace std;
struct Node {
    int code;
    Node *left, *right;
    Node(int x) : code(x), left(nullptr), right(nullptr) {}
};
Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->code)
        root->left = insert(root->left, x);
    else if (x > root->code)
        root->right = insert(root->right, x);
    return root;
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->code << " ";
    inorder(root->right);
}
int main() {
    Node* root = nullptr;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        root = insert(root, x);
    }
    inorder(root);
    return 0;
}