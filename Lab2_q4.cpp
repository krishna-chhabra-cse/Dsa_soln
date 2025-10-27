#include <iostream>
#include <string>
using namespace std;
int main(){
    string s1 = "Thapar";
    string s2 = "Institute";
    cout<<s1+s2<<endl; // concatenate 2 strings
    
    int n = s1.length();
    for(int i=0;i<n/2;i++){
        swap(s1[i],s1[n-1-i]); // reverse string
    }
    cout<<s1<<endl;

  //convert a character from uppercase to lowercase
  for(int i=0;i<n;i++){
         if (s[i] >= 65 && s[i] <= 90 )
            s[i] = s[i]-'A'+'a' ;
  }
  cout<<s<<endl;
  
  // sort the strings in alphabetical order
 string arr[] = {"Thapar", "Institute", "Of", "Engineering", "And", "Technology"};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Bubble sort for strings
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "(d) Sorted strings: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
  
  // delete all the vowels from the string.
  string ans = "";
  for(int i=0;i<n;i++){
         if (s[i] != 'a' && s[i] != 'e' && l != 'i' && s[i] != 'o' && s[i] != 'u')
            ans += s[i];
  }
    }
cout<<ans<<endl;
    return 0;
}
