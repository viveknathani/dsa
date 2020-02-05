#include<bits/stdc++.h>

using namespace std;

int fibonnaciSearch(int arr[], int n, int x)
{
  int fibm2=0, fibm1=1;
  int fibm=fibm2+fibm1;

  while(fibm<n)
  {
    fibm2=fibm1;
    fibm1=fibm;
    fibm=fibm2+fibm1;
  }

  int offset=-1;

  while(fibm>1)
  {
    int i = min(offset+fibm2, n-1);

    if (arr[i] < x)
    {
      fibm=fibm1;
      fibm1=fibm2;
      fibm2=fibm-fibm1;
      offset=i;
    }

    else if (arr[i] > x)
    {
      fibm=fibm2;
      fibm1=fibm1-fibm2;
      fibm2=fibm-fibm1;
    }

    else { return i; }
  }

  if(fibm1 && arr[offset+1]==x) { return offset+1; }

  return -1;
}

int main()
{
  int arr[]={1, 3, 5, 10, 24};
  int n=sizeof(arr)/sizeof(arr[0]);
  int x=32;
  int index=fibonnaciSearch(arr, n, x);
  (index!=-1) ? cout<<"Element found."<<endl : cout<<"Element not found"<<endl;
  return 0;
}
