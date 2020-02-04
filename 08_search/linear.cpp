#include<iostream>
using namespace std;

int main()
{
  int arr[]={4, 8, -1, 34, 23, 98};
  int n=sizeof(arr)/sizeof(arr[0]);

  int p; //element to look for
  int flag=0; //will change to 1 if element exists
  cin>>p;

  for(int i=0; i<n; i++)
  {
    if(arr[i]==p)
    {
      flag=1;
      break;
    }
  }

  if(flag==1) { cout<<"Element found."<<endl; }
  else { cout<<"Element does not exist."<<endl; }
  return 0;
}
