#include<iostream>

using namespace std;

int main()
{
  int arr[]={9, 0, 8, 90, -1};
  int n=sizeof(arr)/sizeof(arr[0]);

  int max=0, min=0;

  for(int i=0; i<n; i++)
  {
    if(arr[i]>max)
    {
      max=arr[i];
    }
  }

  for(int i=0; i<n; i++)
  {
    if(arr[i]<min)
    {
      min=arr[i];
    }
  }

  int range=max-min;
  cout<<max<<" "<<min<<" "<<range<<endl;

  return 0;
}
