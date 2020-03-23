#include<bits/stdc++.h>

using namespace std;

void printThreeHighest(int arr[], int n)
{
  sort(arr, arr+n);
  cout<<arr[n-3]<<" ";
  cout<<arr[n-2]<<" ";
  cout<<arr[n-1]<<endl;
}

int main()
{
  int arr[]={3, 4, -6, 10, -2, 9};
  int n=sizeof(arr)/sizeof(arr[0]);
  printThreeHighest(arr, n);
  return 0;
}
