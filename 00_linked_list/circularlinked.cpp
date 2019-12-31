#include<iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

class circularLinkedList
{
private:
  Node *head, *temp;

public:
  circularLinkedList();
  void add(int value);
  void print();
};

circularLinkedList::circularLinkedList()
{
  head=NULL;
  temp=NULL;
}

void circularLinkedList::add(int value)
{
  Node *newnode= new Node;
  newnode->data=value;
  newnode->next=NULL;

  if(head==NULL)
  {
    head=temp=newnode;
  }
  else
  {
    temp->next=newnode;
    temp=newnode;
  }
  temp->next=head;
}

void circularLinkedList::print()
{
  Node *disp=head;
  if(head!=NULL)
  {
    do {
      cout<<disp->data<<" ";
      disp=disp->next;
    } while(disp!=head);
  }
  cout<<endl;

  /*
     to test whether the list is truly circular or not, comment the above
     line of code and uncomment the following comment
  */

  //cout<<"next is "<<temp->next->data<<endl;
}

int main()
{
  circularLinkedList list;
  for(int i=1; i<=20; i++)
  {
    list.add(i);
  }
  list.print();
  return 0;
}
