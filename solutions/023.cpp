#include<bits/stdc++.h>

using namespace std;

void frequencyNByK(int arr[], int n, int k)
{
  int frequency=n/k;

  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++)
      mp[arr[i]]++;

  unordered_set<int> s(arr, arr+n);

	for (int i: s)
	{
    if(mp[i]>frequency)
        cout<<i<<" ";
  }
  cout<<endl;
}

int main()
{
  int arr[]={4, 5, 6, 7, 8, 4, 4, 5, 5, 5, 5, 5 ,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  int k = 3;
  frequencyNByK(arr, n, k);
  return 0;
}
