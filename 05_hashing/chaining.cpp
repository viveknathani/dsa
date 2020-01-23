#include<iostream>
#include<math.h>
using namespace std;

float A=(sqrt(5)-1)/2;

//universe of keys
class universe
{
public:
  int data;
  int key;
};

class Node
{
public:
  int data;
  Node *prev;
  Node *next;
};

class doublyLinkedList
{
private:
  Node *head, *tail;

public:
  doublyLinkedList();
  void addAtStart(int value);
  void print();
  bool isEmpty();
};

int hashFunction(int key, int m);
void chainedHashInsert(doublyLinkedList hashTable[], int m, int x, int y);
void chainedHashSearch(doublyLinkedList hashTable[], int m, int key);
void chainedHashDelete(doublyLinkedList hashTable[], int m, int x);
void chainedHashDisplay(doublyLinkedList hashTable[], int m);

int main()
{
  universe keys[100];

  for(int i=0; i<100; i++)
  {
    keys[i].key=i;
    keys[i].data=(i-5)*0.5;
  }

  cout<<"An example set of universe of keys is as follows :\n";

  for(int i=34; i<39; i++)
  {
    cout<<"   Key : "<<keys[i].key<<"   "<<"Data : "<<keys[i].data<<endl;
  }

  int m=20;
  doublyLinkedList hashTable[m];

  for(int i=0; i<70; i++)
  {
    chainedHashInsert(hashTable, m, keys[i].key, keys[i].data);
  }

  chainedHashDisplay(hashTable, m);

  return 0;
}

doublyLinkedList::doublyLinkedList()
{
  head=NULL;
  tail=NULL;
}

void doublyLinkedList::addAtStart(int value)
{
  if(head==NULL)
  {
    head=new Node;
    head->data=value;
    head->prev=NULL;
    head->next=NULL;
  }
  else
  {
    Node *n=new Node;
    n->data=value;
    n->prev=NULL;
    n->next=head;
    head->prev=n;
    head=n;
  }
}

void doublyLinkedList::print()
{
  if(this->isEmpty())
  {
    cout<<"list empty\n";
  }
  else
  {
    Node *disp=head;
    cout<<"  ";
    while(disp!=NULL)
    {
      cout<<" "<<disp->data<<"->";
      if(disp->next==NULL) { break; }
      disp=disp->next;
    }
    cout<<"End"<<endl;
  }
}

bool doublyLinkedList::isEmpty()
{
  if(head==NULL)
  {
    return true;
  }

  else
  {
    return false;
  }
}

int hashFunction(int key, int m)
{
  return key%m;
}

void chainedHashInsert(doublyLinkedList hashTable[], int m, int x, int y)
{
  int i=hashFunction(x, m);
  hashTable[i].addAtStart(y);
}

void chainedHashDisplay(doublyLinkedList hashTable[], int m)
{
  cout<<"Following is your hash table."<<endl;

  for(int i=0; i<m; i++)
  {
    hashTable[i].print();
  }
}
