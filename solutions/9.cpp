#include<iostream>
using namespace std;

int main()
{
  int arr[]={9, 0, 8, 90, -1};
  int n=sizeof(arr)/sizeof(arr[0]);

  for(int i=1; i<n; i++)
    cout<<" "<<arr[i];

  cout<<" "<<arr[0]<<endl;
  return 0;
}
