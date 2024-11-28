
#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n) {
  set < int > set;
  //bruteforce approach
  //pushing all the elements in the set
  //reason : set only store unique elements
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]); //O(n*log(n))
  }

  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  //pushing element back to the array
  return k;
  //TC = O(n*log(n))+O(n)
}

//optimised approach 
//using two pointers
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
        //comapring if prev != curr
      i++;
      arr[i] = arr[j]; //making the array overwrite with uniuqe element
    }
  }
  return i + 1; //index no.of last unique elemnt+1 = size
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate  is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

