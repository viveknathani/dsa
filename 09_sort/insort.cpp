#include<iostream>

using namespace std;

void print_array(int arr[], int n);  //simple function to print the array
void insort_ascend(int arr[], int n);
void insort_descend(int arr[], int n);

int main()
{
  int arr[]={4, 5, 6, 2, 3, 10};
  int s=sizeof(arr)/sizeof(arr[0]);
  print_array(arr, s);
  insort_ascend(arr, s);
  print_array(arr, s);
  return 0;
}

void print_array(int arr[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void insort_ascend(int arr[], int n)
{
  int key, i;

  //iterating from arr[1] and placing it in it's correct position
  for(int j=1; j<n; j++)
  {
    key=arr[j];
    i=j-1;

    while(i>=0 && arr[i]>key)
    {
      arr[i+1]=arr[i];
      i=i-1;
    }

    arr[i+1]=key;
  }
}

void insort_descend(int arr[], int n)
{
  int key, i;

  //iterating from arr[1] and placing it in it's correct position
  for(int j=1; j<n; j++)
  {
    key=arr[j];
    i=j-1;

    while(i>=0 && arr[i]<key) 
    {
      arr[i+1]=arr[i];
      i=i-1;
    }

    arr[i+1]=key;
  }
}
