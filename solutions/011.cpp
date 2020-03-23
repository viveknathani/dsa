#include<iostream>

using namespace std;

void findPairsWithGivenSum(int arr[], int n, int sum)
{
  for(int i=0; i<n; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      if(arr[i]+arr[j]==sum)
        cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
    }
  }
}

int main()
{
  int arr[]={1, 4, 45, 6, 10, -8};
  int n=sizeof(arr)/sizeof(arr[0]);
  int sum=16;
  findPairsWithGivenSum(arr, n, sum);
  return 0;
}
