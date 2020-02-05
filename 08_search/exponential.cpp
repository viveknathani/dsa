#include<bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
  if(right>=left)
  {
    int mid=left+(right-1)/2;

    if(arr[mid]==x) { return mid; }

    if(arr[mid]>x) { return binarySearch(arr, left, mid-1, x); }

    return binarySearch(arr, mid+1, right, x);
  }
  return -1;
}

int exponentialSearch(int arr[], int n, int x)
{
  if(arr[0]==x) { return 0; }

  int i=1;
  while(i<n && arr[i]<=x) { i=i*2; }

  return binarySearch(arr, i/2, min(i, n), x);
}

int main()
{
  int arr[]={1, 3, 5, 10, 24};
  int n=sizeof(arr)/sizeof(arr[0]);
  int x=10;
  int index=exponentialSearch(arr, n, x);
  (index!=-1) ? cout<<"Element found."<<endl : cout<<"Element not found"<<endl;
  return 0;
}
