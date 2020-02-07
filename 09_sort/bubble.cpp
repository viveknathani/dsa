#include<iostream>

using namespace std;

void swap(int *x, int *y)
{
  int t=*x;
  *x=*y;
  *y=t;
}

void bubbleSort(int arr[], int n)
{
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<(n-i-1); j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

void printArray(int arr[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int arr[]={4, 5, 6, 2, 3, 10};
  int n=sizeof(arr)/sizeof(arr[0]);
  printArray(arr, n);
  bubbleSort(arr, n);
  printArray(arr, n);
  return 0;
}
