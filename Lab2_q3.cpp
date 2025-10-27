#include <iostream>
#include <vector>
using namespace std;

// using binary search 
int findMissingBinary(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + 1;
}

int main() {
    vector<int> arr = {1, 2, 3, 5, 6, 7};
    cout << "Missing Number: " << findMissingBinary(arr);
    return 0;
}

// using linera search
#include <iostream>
#include <vector>
using namespace std;

int findMissingLinear(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n + 1; // if last number is missing
}

int main() {
    vector<int> arr = {1, 2, 3, 5, 6, 7};
    cout << "Missing Number: " << findMissingLinear(arr);
    return 0;
}
