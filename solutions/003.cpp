#include<iostream>

using namespace std;

int main()
{
  int arr[]={9, 0, 8, 90, -1};
  int n=sizeof(arr)/sizeof(arr[0]);

  for(int i=n-1; i>=0; i--)
      cout<<" "<<arr[i];

  cout<<endl;    
  return 0;
}
