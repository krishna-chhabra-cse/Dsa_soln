#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

#define MAX 100

// ---------------------- STACK USING ARRAY ----------------------
class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ---------------------- REVERSE STRING USING STACK ----------------------
string reverseString(string s) {
    stack<char> st;
    for (char c : s) st.push(c);
    string rev = "";
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }
    return rev;
}

// ---------------------- CHECK BALANCED PARENTHESES ----------------------
bool isBalanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return s.empty();
}

// ---------------------- INFIX TO POSTFIX ----------------------
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) postfix += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

// ---------------------- POSTFIX EVALUATION ----------------------
int evaluatePostfix(string postfix) {
    stack<int> st;
    for (char c : postfix) {
        if (isdigit(c))
            st.push(c - '0');
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

// ---------------------- MAIN MENU ----------------------
int main() {
    Stack s;
    int choice, val;
    string str, expr, infix, postfix;

    do {
        cout << "\n================= STACK MENU =================";
        cout << "\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek";
        cout << "\n7. Reverse a String\n8. Check Balanced Parentheses";
        cout << "\n9. Infix to Postfix Conversion\n10. Evaluate Postfix Expression";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            val = s.pop();
            if (val != -1)
                cout << "Popped value: " << val << endl;
            break;
        case 3:
            cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            break;
        case 4:
            cout << (s.isFull() ? "Stack is full" : "Stack is not full") << endl;
            break;
        case 5:
            s.display();
            break;
        case 6:
            val = s.peek();
            if (val != -1)
                cout << "Top element: " << val << endl;
            break;
        case 7:
            cout << "Enter string: ";
            cin >> str;
            cout << "Reversed string: " << reverseString(str) << endl;
            break;
        case 8:
            cout << "Enter expression: ";
            cin >> expr;
            cout << (isBalanced(expr) ? "Balanced" : "Not Balanced") << endl;
            break;
        case 9:
            cout << "Enter infix expression: ";
            cin >> infix;
            postfix = infixToPostfix(infix);
            cout << "Postfix expression: " << postfix << endl;
            break;
        case 10:
            cout << "Enter postfix expression: ";
            cin >> postfix;
            cout << "Evaluated value: " << evaluatePostfix(postfix) << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}

