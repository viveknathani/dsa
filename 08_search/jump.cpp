#include<bits/stdc++.h>

using namespace std;

int jumpSearch(int arr[], int n, int x)
{
  int step=sqrt(n);

  int prev=0;

  while(arr[min(step,n)-1]<x)
  {
    prev=step;
    step+=sqrt(n);
    if(prev>=n)
    {
      return -1;
    }
  }

  while(arr[prev]<x)
  {
    prev++;
    if(prev==min(step, n)) { return -1; }
  }

  if(arr[prev]==x)  { return prev; }

  return -1;
}

int main()
{
  int arr[]={1, 3, 5, 10, 24};
  int n=sizeof(arr)/sizeof(arr[0]);
  int x=10;
  int index=jumpSearch(arr, n, x);
  (index!=-1) ? cout<<"Element found."<<endl : cout<<"Element not found"<<endl;
  return 0;
}
