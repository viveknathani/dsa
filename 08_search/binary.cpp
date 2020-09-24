#include<iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
  if(right>=left)
  {
    int mid=left+(right-left)/2;

    if(arr[mid]==x) { return mid; }

    if(arr[mid]>x) { return binarySearch(arr, left, mid-1, x); }

    return binarySearch(arr, mid+1, right, x);
  }
  return -1;
}

int main()
{
  int arr[] = { 2, 3, 4, 10, 40 };
  int x = -2;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, n - 1, x);
  (result==-1) ?  cout<<"Element does not exist."<<endl : cout<<"Element found at index : "<<result<<endl;
  return 0;
}
