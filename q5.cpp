// Write a program to find sum of every row and every column in a two-dimensional array. 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    vector<vector<int>> arr(r, vector<int>(c));

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    cout<<endl;

    // Sum of each row
    cout << "Sum of each row:" << endl;
    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i + 1 << " sum = " << rowSum << endl;
    }
    cout<<endl;
    
    // Sum of each column
    cout << "Sum of each column:" << endl;
    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << " sum = " << colSum << endl;
    }

    return 0;
}
