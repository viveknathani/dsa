#include<bits/stdc++.h>

using namespace std;

void gcdGivenRange(int arr[], int n, int Start, int End)
{
  int minimumIndex=-1;
  for(int i=Start; i<=End; i++)
  {
    if(abs(arr[i])<minimumIndex)
    {
      minimumIndex=i;
    }
  }

  for(int j=arr[minimumIndex]; j>=1; j--)
  {
    int flag=0;
    for(int k=Start; k<=End; k++)
    {
      if(arr[k]%j!=0)
        flag=1;
        break;
    }

    if(flag==0)
    {
      cout<<"GCD : "<<j<<endl;
      break;
    }
  }
}

int main()
{
  int arr[]={2, 3, 6, 9, 5};
  int n=sizeof(arr)/sizeof(arr[0]);
  gcdGivenRange(arr, n, 1, 3);
  return 0;
}
