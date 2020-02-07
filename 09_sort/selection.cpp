#include<iostream>

using namespace std;

void swap(int *x, int *y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
}

void selectionSort(int arr[], int n)
{
  for(int i=0; i<n; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      if(arr[j]<arr[i])
      { swap(&arr[i], &arr[j]); }
    }
  }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  selectionSort(arr, n);
  cout << "Sorted array: \n";
  printArray(arr, n);
  return 0;
}
