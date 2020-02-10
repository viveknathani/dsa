#include<iostream>

using namespace std;

int main()
{
  int arr[]={0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
  int n=sizeof(arr)/sizeof(arr[0]);

  int count0=0, count1=0, count2=0;

  for(int i=0; i<n; i++)
  {
    if(arr[i]==0)
      count0++;

    if(arr[i]==1)
      count1++;

    if(arr[i]==2)
      count2++;
  }

  for(int i=0; i<count0; i++)
      cout<<" "<<"0";

  for(int i=0; i<count1; i++)
      cout<<" "<<"1";

  for(int i=0; i<count2; i++)
      cout<<" "<<"2";

  cout<<endl;
  return 0;
}
