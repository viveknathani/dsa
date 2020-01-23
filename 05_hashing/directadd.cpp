//program to demonstrate direct address table
#include<iostream>
using namespace std;

//universe of keys
class universe
{
public:
  int data;
};

int main()
{
  universe keys[10];

  //feeding values into the universe
  for(int i=0; i<10; i++)
  {
    keys[i].data=2*i;
  }

  int directAddressTable[8];

  //storing a subset of the universe into a direct address table
  for(int i=0; i<8; i++)
  {
    directAddressTable[i]=keys[i].data;
    cout<<" "<<directAddressTable[i];
  }

  cout<<endl;
   
  return 0;
}
