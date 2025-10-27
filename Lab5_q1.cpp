#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;


void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}


void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        cout << "Inserted " << value << " as the first node.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    cout << "Inserted " << value << " at the end.\n";
}


void insertBeforeAfter(int target, int value, bool after) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (!after && head->data == target) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " before " << target << ".\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        if (after && temp->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " after " << target << ".\n";
            return;
        } else if (!after && temp->next != nullptr && temp->next->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " before " << target << ".\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Node with value " << target << " not found.\n";
}


void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted node " << temp->data << " from beginning.\n";
    delete temp;
}


void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted node " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    cout << "Deleted node " << temp->next->data << " from end.\n";
    delete temp->next;
    temp->next = nullptr;
}


void deleteSpecific(int value) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node " << value << ".\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;

    if (temp->next == nullptr)
        cout << "Node not found!\n";
    else {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << "Deleted node " << value << ".\n";
    }
}


void searchNode(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Node " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found!\n";
}


void displayList() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {
    int choice, val, target;
    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before a Node\n4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n";
        cout << "8. Search Node\n9. Display List\n10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertAtEnd(val); break;
            case 3: cout << "Enter target value: "; cin >> target; cout << "Enter new value: "; cin >> val; insertBeforeAfter(target, val, false); break;
            case 4: cout << "Enter target value: "; cin >> target; cout << "Enter new value: "; cin >> val; insertBeforeAfter(target, val, true); break;
            case 5: deleteFromBeginning(); break;
            case 6: deleteFromEnd(); break;
            case 7: cout << "Enter value to delete: "; cin >> val; deleteSpecific(val); break;
            case 8: cout << "Enter value to search: "; cin >> val; searchNode(val); break;
            case 9: displayList(); break;
            case 10: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}

