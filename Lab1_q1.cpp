#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void create(){
    arr.clear();
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid size. Array not created.\n";
        return;
    }
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        arr.push_back(x); 
    }
    cout << "Array created successfully.\n";
}
void display(){
    if (arr.empty()) { 
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
void insertElement(){
    int pos, value;
    cout << "Enter position to insert at (0-based index): ";
    cin >> pos;
    if (pos < 0 || pos > arr.size()) {
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> value;
    arr.insert(arr.begin() + pos, value);
    cout << "Element inserted.\n";
}
void deleteElement(){
    if (arr.empty()) {
        cout << "Array is empty. Cannot delete.\n";
        return;
    }
    int pos;
    cout << "Enter position to delete (0-based index): ";
    cin >> pos;

    if (pos < 0 || pos >= arr.size()) {
        cout << "Invalid position!\n";
        return;
    }
    arr.erase(arr.begin() + pos);
    cout << "Element deleted.\n";
}
void linearSearch(){
    if (arr.empty()) {
        cout << "Array is empty.\n";
        return;
    }
    int target;
    cout << "Enter element to search for: ";
    cin >> target;
    bool found = false;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            cout << "Element found at index " << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Element not found in the array.\n";
    }
}
int main() {
    int choice;
    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. CREATE "<<endl;
        cout << "2. DISPLAY "<<endl;
        cout << "3. INSERT "<<endl;
        cout << "4. DELETE "<<endl;
        cout << "5. LINEAR SEARCH "<<endl;
        cout << "6. EXIT "<<endl;
        cout << "------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insertElement();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                linearSearch();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
