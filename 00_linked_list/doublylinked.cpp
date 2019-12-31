#include<iostream>

using namespace std;

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
  void addAtEnd(int value);
  void print();
  void deleteHead();
  void deleteTail();
};

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

void doublyLinkedList::addAtEnd(int value)
{
  if(tail==NULL)
  {
    tail=new Node;
    tail->data=value;
    tail->next=NULL;
    tail->prev=NULL;
    head=tail;
  }
  else
  {
    Node *n=new Node;
    n->data=value;
    n->next=NULL;
    n->prev=tail;
    tail->next=n;
    tail=n;
  }
}

void doublyLinkedList::print()
{
  Node *disp=head;
  while(disp!=NULL)
  {
    cout<<disp->data<<" ";
    if(disp->next==NULL) { break; }
    disp=disp->next;
  }
  cout<<endl;
}

void doublyLinkedList::deleteHead()
{
  head=head->next;
  delete head->prev;
}

void doublyLinkedList::deleteTail()
{
  tail=tail->prev;
  delete tail->next;
  tail->next=NULL;
}

int main()
{
  doublyLinkedList list;
  list.addAtEnd(5);
  list.addAtEnd(15);
  list.addAtStart(10);
  list.print();
  list.deleteHead();
  list.print();
  list.addAtEnd(256);
  list.deleteTail();
  list.print();
  return 0;
}
