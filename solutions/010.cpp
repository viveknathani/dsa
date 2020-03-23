#include<iostream>
using namespace std;

int getMissingNo(int arr[], int n)
{
  int sum=(n+1)*(n+2)/2;

  for(int i=0; i<n; i++)
      sum-=arr[i];

  return sum;
}

int main()
{
    int arr[]={ 1, 2, 4, 5, 6 };
    int n=sizeof(arr) / sizeof(arr[0]);
    int miss=getMissingNo(arr, n);
    cout<<miss<<endl;
}
