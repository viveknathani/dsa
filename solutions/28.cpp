#include<bits/stdc++.h>

using namespace std;

void printTwoRepeatingElements(int arr[], int arr_size, int n)
{
  int sum=0;
  int general_sum=n*(n+1)/2;
  int product=1;
  int nfac=1;

  for(int i=2; i<=n; i++)
      nfac*=i;

  for(int i=0; i<arr_size; i++)
  {
    sum+=arr[i];
    product*=arr[i];
  }
  int x, y;
  sum-=general_sum;
  product=product/nfac;

  int D=sqrt(sum*sum-(4*product));

  x=(sum+D)/2;
  y=(sum-D)/2;

  cout<<x<<" "<<y<<endl;
}

int main()
{
  int arr[]={4, 2, 4, 5, 2, 3, 1};
  int arr_size=sizeof(arr)/sizeof(arr[0]);
  int n=arr_size-2;
  printTwoRepeatingElements(arr, arr_size, n);
  return 0;
}
