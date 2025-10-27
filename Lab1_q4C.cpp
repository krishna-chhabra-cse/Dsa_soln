// 4) Implement the logic to
// c. Find the Transpose of a Matrix
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int r,c;
    cout<<"enter no of rows :- ";
    cin>>r;
    cout<<"enter no of columns :- ";
    cin>>c;
    vector<vector<int>> matrix(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"enter the element at "<<i<<"th row and at "<<j<<"th col :- ";
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> transpose(c, vector<int>(r));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    cout << "\n Matrix:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "\nTranspose of matrix:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
