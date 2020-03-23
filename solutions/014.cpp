#include<bits/stdc++.h>

using namespace std;

void firstRepeatingElement(int arr[], int n)
{
  // Initialize index of first repeating element
    int min = -1;

    // Creates an empty hashset
    set<int> myset;

    // Traverse the input array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // If element is already in hash set, update min
        if (myset.find(arr[i]) != myset.end())
            min = i;

        else   // Else add element to hash set
            myset.insert(arr[i]);
    }

    // Print the result
    if (min != -1)
        cout << "The first repeating element is " << arr[min];
    else
        cout << "There are no repeating elements";
}

int main()
{
  int arr[]={10, 5, 3, 4, 3, 5, 6};
  int n=sizeof(arr)/sizeof(arr[0]);
  firstRepeatingElement(arr, n);
  return 0;
}
