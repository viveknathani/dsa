#include<iostream>

using namespace std;

int interpolationSearch(int arr[], int n, int x)
{
  int low=0, high=(n-1);

  while(low<=high && x>=arr[low] && x<=arr[high])
  {
    if(low==high)
    {
      if(arr[low]==x) { return low; }
      return -1;
    }

    //probe position formula
    int pos=low + (((double)(high-low)/(arr[high]-arr[low]))*(x-arr[low]));

    if(arr[pos]==x) { return pos; }

    if(arr[pos]<x) { low=pos+1; }

    else { high=pos-1; }
  }
  return -1;
}

int main()
{
  int arr[]={1, 3, 5, 10, 24};
  int n=sizeof(arr)/sizeof(arr[0]);
  int x=10;
  int index=interpolationSearch(arr, n, x);
  (index!=-1) ? cout<<"Element found."<<endl : cout<<"Element not found"<<endl;
  return 0;
}
