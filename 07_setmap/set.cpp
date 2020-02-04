#include<iostream>
#include<set>
#include<iterator>


using namespace std;

int main()
{
  set <int> elements;

  elements.insert(80);
  elements.insert(10);
  elements.insert(30);
  elements.insert(50);
  elements.insert(20);
  elements.insert(60);

  set <int> :: iterator itr;
  cout<<"Elements of set \"elements\" are : "<<endl;
  for(itr=elements.begin(); itr!=elements.end(); ++itr)
  {
    cout<<" "<<*itr;
  }
  cout<<endl;

  set <int, greater<int>> values(elements.begin(), elements.end());
  cout<<"Elements of set \"values\" are : "<<endl;
  for(itr=values.begin(); itr!=values.end(); ++itr)
  {
    cout<<" "<<*itr;
  }
  cout<<endl;

  return 0;
}
