#include<iostream>

using namespace std;

int main()
{
  int arr[5]={2, 3, 33, 3, -11};
  int ctr=0;

  for(int i=0; i<5; i++)
  {
    if(arr[i]==3)
      ctr++;
  }

  cout<<ctr<<endl;
  return 0;
}
