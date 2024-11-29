//Brute force 
// sorting the array hence its obvious that the largest elemnt will be the last elemnt 
#include<bits/stdc++.h>
using namespace std;
 
int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}
 
int main() {
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<sortArr(arr2);
   
    return 0;
    //TC O(N* log N)
}


//optimised approach 
//1. instead of sorting the array 
// intialise a max element and compare with all the no.
//return the max elemnt 

#include <bits/stdc++.h>
 
using namespace std;
int findLargestElement(int arr[], int n) {
 
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}
int main() {
  int arr1[] = {2,5,1,3,0};
  int n = 5;
  int max = findLargestElement(arr1, n);
  cout << "The largest element in the array is: " << max << endl;
}