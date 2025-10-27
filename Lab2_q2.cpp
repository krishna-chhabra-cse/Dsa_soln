// code buuble sort
#include <iostream>
using namespace std;
int main(){
    int arr[7] = {64,34,25,12,22,11,90};
    cout<<"BEFORE Bubble sorting algo"<<endl;
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<7-1;i++){
        for(int j=0;j<7-1-i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
    cout<<"AFTER Bubble sorting algo"<<endl;
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
