#include<bits/stdc++.h>

using namespace std;

bool subArrayExists(int arr[], int n)
{
  unordered_set<int> sum_table;
  int sum=0;

  for(int i=0; i<n; i++)
  {
    sum+=arr[i];

    if(sum==0 || sum_table.find(sum)!=sum_table.end())
        return true;

    sum_table.insert(sum);
  }
  return false;
}


int main()
{
  int arr[]={-3, 2, 3, -5, 1};
  int n=sizeof(arr)/sizeof(arr[0]);
  bool check=subArrayExists(arr, n);
  if(check)
    cout<<"Yes it exists."<<endl;
  else
    cout<<"No it doesn't."<<endl;
  return 0;
}
