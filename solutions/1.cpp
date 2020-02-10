#include<iostream>

using namespace std;

int main()
{
  int n, m;
  cin>>n;
  cin>>m;

  int x;
  while(n--)
  {
    cin>>x;
    if(x==m)
    {
      cout<<"Element found."<<endl;
      break;
    }  
  }
  return 0;
}
