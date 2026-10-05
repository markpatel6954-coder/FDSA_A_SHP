#include <iostream>
#include <stack>
#include <string>
using namespace std;
int priority(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for (char ch : infix) {
        if (ch == ' ')
            continue;
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop();
        }
        else {
            while (!s.empty() && s.top() != '(' &&
                   priority(s.top()) >= priority(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    cout << "Postfix expression: " << infixToPostfix(infix);
    return 0;
}