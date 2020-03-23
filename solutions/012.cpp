#include<bits/stdc++.h>

using namespace std;

void printDuplicates(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    {
        int index = arr[i] % n;
        arr[index] += n;
    }

    for (int i = 0; i < n; i++)
      {
          if ((arr[i]/n) > 1)
              cout << i << " ";
      }
}

int main()
{
  int arr[]={1, 6, 3, 1, 3, 6, 6};
  int n=sizeof(arr)/sizeof(arr[0]);
  printDuplicates(arr, n);
  return 0;
}
