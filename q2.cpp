// ) Design the logic to remove the duplicate elements from an Array and after the
// deletion the array should contain the unique elements.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n=0;
    vector<int> arr;
    cout<<"enter the no of elements in the array: "<<endl;
    cin>>n;
    cout<<"now u shall enter the elements of array :"<<endl;
    for(int i=0;i<n;i++){
    int x=0;
    cin >> x;
    arr.push_back(x);
    }

    // M-1
    // sort(arr.begin(),arr.end());
    // auto last = unique(arr.begin(), arr.end());
    // arr.erase(last, arr.end());
    // cout << "Array after removing duplicates:" << endl;
    // for (int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //M-2
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        if(arr[i]==arr[j]){
            for(int k=j;k<n-1;k++){
                arr[k] = arr[k+1];
            }
            n--;
            j--;
        }
    }
    }
    cout << "Array after removing duplicates:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}