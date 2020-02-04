#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main()
{
  map <char, int> container;

  container.insert(pair<char, int>('A', 20));
  container.insert(pair<char, int>('B', 400));
  container.insert(pair<char, int>('C', -1));
  container.insert(pair<char, int>('D', 40));
  container.insert(pair<char, int>('E', 0));
  container.insert(pair<char, int>('F', 68));
  container.insert(pair<char, int>('G', 23));

  map <char, int> :: iterator itr;

  cout<<"Your map is : "<<endl;
  for(itr=container.begin(); itr!=container.end(); ++itr)
  {
    cout<<"     "<<"Key : "<<itr->first<<"  "<<" Element : "<<itr->second<<endl;
  }

  container.erase(container.begin(), container.find('C'));

  cout<<"Your modified map is : "<<endl;
  for(itr=container.begin(); itr!=container.end(); ++itr)
  {
    cout<<"     "<<"Key : "<<itr->first<<"  "<<" Element : "<<itr->second<<endl;
  }

  return 0;
}
