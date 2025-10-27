#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define MAX 100

// ===================== 1. SIMPLE QUEUE USING ARRAY =====================
class SimpleQueue {
    int arr[MAX];
    int front, rear;
public:
    SimpleQueue() {
        front = rear = -1;
    }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == MAX - 1; }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty!\n";
        else cout << "Front element: " << arr[front] << endl;
    }
};

// ===================== 2. CIRCULAR QUEUE USING ARRAY =====================
class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % MAX == front; }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Circular Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow!\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty!\n";
            return;
        }
        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) cout << "Circular Queue is empty!\n";
        else cout << "Front element: " << arr[front] << endl;
    }
};

// ===================== 3. INTERLEAVE QUEUE =====================
void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue must have even number of elements!\n";
        return;
    }

    queue<int> firstHalf;
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }

    cout << "Interleaved Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

// ===================== 4. FIRST NON-REPEATING CHARACTER =====================
void firstNonRepeating(string s) {
    queue<char> q;
    int freq[26] = {0};

    for (char c : s) {
        freq[c - 'a']++;
        q.push(c);

        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

// ===================== 5(a). STACK USING TWO QUEUES =====================
class StackTwoQ {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) cout << "Stack Underflow!\n";
        else {
            cout << "Popped: " << q1.front() << endl;
            q1.pop();
        }
    }

    void top() {
        if (q1.empty()) cout << "Stack is empty!\n";
        else cout << "Top: " << q1.front() << endl;
    }

    bool isEmpty() { return q1.empty(); }
};

// ===================== 5(b). STACK USING ONE QUEUE =====================
class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) cout << "Stack Underflow!\n";
        else {
            cout << "Popped: " << q.front() << endl;
            q.pop();
        }
    }

    void top() {
        if (q.empty()) cout << "Stack is empty!\n";
        else cout << "Top: " << q.front() << endl;
    }

    bool isEmpty() { return q.empty(); }
};

// ===================== MAIN MENU =====================
int main() {
    int choice;
    SimpleQueue sq;
    CircularQueue cq;

    do {
        cout << "\n================= QUEUE MENU =================";
        cout << "\n1. Simple Queue Operations";
        cout << "\n2. Circular Queue Operations";
        cout << "\n3. Interleave Queue";
        cout << "\n4. First Non-Repeating Character";
        cout << "\n5. Stack using Two Queues";
        cout << "\n6. Stack using One Queue";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int ch, val;
            do {
                cout << "\n--- Simple Queue Menu ---";
                cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Back";
                cout << "\nEnter choice: ";
                cin >> ch;
                switch (ch) {
                case 1: cout << "Enter value: "; cin >> val; sq.enqueue(val); break;
                case 2: sq.dequeue(); break;
                case 3: sq.display(); break;
                case 4: sq.peek(); break;
                }
            } while (ch != 5);
            break;
        }

        case 2: {
            int ch, val;
            do {
                cout << "\n--- Circular Queue Menu ---";
                cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Back";
                cout << "\nEnter choice: ";
                cin >> ch;
                switch (ch) {
                case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
                case 2: cq.dequeue(); break;
                case 3: cq.display(); break;
                case 4: cq.peek(); break;
                }
            } while (ch != 5);
            break;
        }

        case 3: {
            queue<int> q;
            int n, val;
            cout << "Enter even number of elements: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> val;
                q.push(val);
            }
            interleaveQueue(q);
            break;
        }

        case 4: {
            string s;
            cout << "Enter lowercase string: ";
            cin >> s;
            firstNonRepeating(s);
            break;
        }

        case 5: {
            StackTwoQ s;
            s.push(10); s.push(20); s.push(30);
            s.top();
            s.pop();
            s.top();
            break;
        }

        case 6: {
            StackOneQ s;
            s.push(5); s.push(10); s.push(15);
            s.top();
            s.pop();
            s.top();
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

