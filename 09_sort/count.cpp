#include<bits/stdc++.h>
#define range 255
using namespace std;

void countingSort(char arr[])
{
  char output[strlen(arr)];

  int count[range+1], i;
  memset(count, 0, sizeof(count));

  for(i=0; arr[i]; ++i)
  {
    ++count[arr[i]];
  }

  for(i=1; i<=range; ++i)
  {
    count[i]+=count[i-1];
  }

  for(i=0; arr[i]; ++i)
  {
    output[count[arr[i]]-1]=arr[i];
    --count[arr[i]];
  }

  for(i=0; arr[i]; ++i)
  {
    arr[i]=output[i];
  }
}

int main()
{
  char arr[]="coolshiz";
  countingSort(arr);
  cout<<arr<<endl;
  return 0;
}
