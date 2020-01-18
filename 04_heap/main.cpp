#include<bits/stdc++.h>
using namespace std;

void Swap(int *a, int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}

class heap
{
private:
  int heap_size;
public:
  heap(int arr[], int Size);
  int PARENT(int i);
  int LEFT(int i);
  int RIGHT(int i);
  void maxHeapify(int arr[], int i);
  void buildMaxHeap(int arr[], int Size);
  void heapSort(int arr[], int Size);
  void printHeap(int arr[], int Size);
};

int main()
{
  int arr[]={ 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
  int n=sizeof(arr)/sizeof(arr[0]);

  cout<<"INPUT ARRAY : \n";
  for(int i=0; i<n; i++)
  {
    cout<<" "<<arr[i];
  }

  heap h(arr, n);
  h.heapSort(arr, n);
  cout<<"\nOUPUT HEAP : \n";
  h.printHeap(arr, n);
  return 0;
}

int heap::PARENT(int i) { return (i/2); }
int heap::LEFT(int i) { return ((2*i)+1); }
int heap::RIGHT(int i) { return ((2*i)+2); }

heap::heap(int arr[], int Size)
{
  heap_size=Size;
}

void heap::maxHeapify(int arr[], int i)
{
  int largest=i;
  int l=LEFT(i), r=RIGHT(i);

  if(l<heap_size && arr[l]>arr[largest])
  {
    largest=l;
  }

  if(r<heap_size && arr[r]>arr[largest])
  {
    largest=r;
  }

  if(largest!=i)
  {
    Swap(&arr[i], &arr[largest]);
    maxHeapify(arr, largest);
  }
}

void heap::buildMaxHeap(int arr[], int Size)
{
  int start=(Size/2)-1;
  for(int i=arr[start]; i>=0; i--)
  {
    maxHeapify(arr, i);
  }
}

void heap::heapSort(int arr[], int Size)
{
  buildMaxHeap(arr, Size);
  for(int i=arr[Size-1]; i>=1; i--)
  {
    Swap(&arr[0], &arr[i]);
    heap_size=heap_size-1;
    maxHeapify(arr, 0);
  }
}

void heap::printHeap(int arr[], int Size)
{
  for(int i=0; i<Size; i++)
  {
    cout<<" "<<arr[i];
  }
  cout<<endl;
}
