#include <stdio.h>

void printUnion(int arr1[], int arr2[], int size1, int size2)
{
    int i=0, j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            printf("%d ", arr1[i++]);
        }
        else if(arr2[j]<arr1[i])
        {
            printf("%d ",arr2[j++]);
        }
        else
        {
            printf("%d ", arr2[j++]);
        }
    }
    while(i<size1)
    {
        printf("%d ", arr1[i++]);
    }
    while(j<size2)
    {
        printf("%d ", arr2[j++]);
    }
}

void printIntersection(int arr1[], int arr2[], int size1, int size2)
{
  int i=0, j=0;
  while(i<size1 && j<size2)
  {
    if(arr1[i]<arr2[j])
    {
        i++;
    }
    else if(arr2[j]<arr1[i])
    {
        j++;
    }
    else
    {
        printf("%d ", arr2[j++]);
        i++;
    }
  }
}

void insort_ascend(int arr[], int n)
{
    int key, i, j;
    for(j=1; j<n; j++)
    {
        key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]>key)
        {
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
}

int main()
{
  int arr1[]={5, 6, 8};
  int arr2[]={34, 6, 89, 23, 1};
  int size1=sizeof(arr1)/sizeof(arr1[0]);
  int size2=sizeof(arr2)/sizeof(arr2[0]);
  insort_ascend(arr1, size1);
  insort_ascend(arr2, size2);
  printf("Union: ");
  printUnion(arr1, arr2, size1, size2);
  printf("\nIntersection: ");
  printIntersection(arr1, arr2, size1, size2);
	return 0;
}
