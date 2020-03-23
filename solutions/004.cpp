#include<bits/stdc++.h>

using namespace std;


//my solution
void kthSmallest(int arr[], int n, int k)
{
  set <int> elements(arr, arr+n);
  set <int> :: iterator itr=elements.begin();
  advance(itr, k-1);
  cout<<"kth smallest : "<<*itr<<endl;
}

void kthLargest(int arr[], int n, int k)
{
  set <int, greater<int> > elements(arr, arr+n);
  set <int> :: iterator itr=elements.begin();
  advance(itr, k-1);
  cout<<"kth largest : "<<*itr<<endl;
}

// gfg solution :
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/

int main()
{
  int arr[] = {12, 3, 5, 7, 4, 19, 26};
  int n = sizeof(arr)/sizeof(arr[0]), k = 3;
  kthSmallest(arr, n, k);
  return 0;
}
