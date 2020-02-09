#include<bits/stdc++.h>

using namespace std;

const int RUN=32;

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while
     (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void timSort(int arr[], int n)
{
  for (int i = 0; i < n; i+=RUN)
      insertionSort(arr, i, min((i+31), (n-1)));

  for (int size = RUN; size < n; size = 2*size)
  {
    for (int left = 0; left < n; left += 2*size)
    {
      int mid = left + size - 1;
      int right = min((left + 2*size - 1), (n-1));
      merge(arr, left, mid, right);
    }
  }
}

void print_array(int arr[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int arr[]={4, 5, 6, 2, 3, 10};
  int s=sizeof(arr)/sizeof(arr[0]);
  print_array(arr, s);
  timSort(arr, s);
  print_array(arr, s);
  return 0;
}
