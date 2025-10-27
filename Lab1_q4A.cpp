// 4) Implement the logic to
// a. Reverse the elements of an array
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> arr;
    int n;
    cout<<"enter the no of elements in array u wanna add :- ";
    cin>>n;
    cout<<"\n so u want to add "<<n<<" elements in a array"<<endl;
    for(int i=0;i<n;i++){
        int x;
        cout<<"enter element no. " <<i+1<<" in array :- ";
        cin>>x;
        arr.push_back(x);
    }
    int s=0;
    int e=n-1;
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
