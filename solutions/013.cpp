#include<bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
  if(right>=left)
  {
    int mid=left+(right-1)/2;

    if(arr[mid]==x) { return mid; }

    if(arr[mid]>x) { return binarySearch(arr, left, mid-1, x); }

    return binarySearch(arr, mid+1, right, x);
  }
  return -1;
}

//my solution
void printCommonElements(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
{
  set <int> elements(arr1, arr1+n1);

  set <int> :: iterator itr=elements.begin();

  for(itr=elements.begin(); itr!=elements.end(); ++itr)
  {
    if(binarySearch(arr2, 0, n2-1, *itr)!=-1 && binarySearch(arr3, 0, n3-1, *itr)!=-1)
        cout<<*itr<<endl;
  }
}

//gfg solution
void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
    // Initialize starting indexes for ar1[], ar2[] and ar3[]
    int i = 0, j = 0, k = 0;

    // Iterate through three arrays while all arrays have elements
    while (i < n1 && j < n2 && k < n3)
    {
         // If x = y and y = z, print any of them and move ahead
         // in all arrays
         if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
         {   cout << ar1[i] << " ";   i++; j++; k++; }

         // x < y
         else if (ar1[i] < ar2[j])
             i++;

         // y < z
         else if (ar2[j] < ar3[k])
             j++;

         // We reach here when x > y and z < y, i.e., z is smallest
         else
             k++;
    }
}

int main()
{
  int arr1[]={1, 5, 10, 20, 40, 80};
  int arr2[]={6, 7, 20, 80, 100};
  int arr3[]={3, 4, 15, 20, 30, 70, 80, 120};
  int n1=sizeof(arr1)/sizeof(arr1[0]);
  int n2=sizeof(arr2)/sizeof(arr2[0]);
  int n3=sizeof(arr3)/sizeof(arr3[0]);
  printCommonElements(arr1, arr2, arr3, n1, n2, n3);
  return 0;
}
