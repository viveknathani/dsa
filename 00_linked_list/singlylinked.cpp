#include<iostream>

using namespace std;

class  Node
{
public:
  int data;
  Node *next;
};

class linkedList
{
private:
  Node *head, *tail, *ptr, *save;
public:
  linkedList();
  void addAtStart(int value);
  void addAtEnd(int value);
  void print();
  void deleteHead();
  void deleteTail();
};

linkedList::linkedList()
{
  head=NULL;
  tail=NULL;
}

void linkedList::addAtStart(int value)
{
  ptr=new Node;
  ptr->data=value;
  ptr->next=NULL;

  if(head==NULL)
  {
    head=ptr;
    tail=ptr;
  }
  else
  {
    save=head;
    head=ptr;
    ptr->next=save;
  }
}

void linkedList::addAtEnd(int value)
{
  ptr=new Node;
  ptr->data=value;
  ptr->next=NULL;

  if(head==NULL)
  {
    head=ptr;
    tail=ptr;
  }
  else
  {
    tail->next=ptr;
    tail=tail->next;
  }
}

void linkedList::print()
{
  Node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

void linkedList::deleteHead()
{
  if(head==NULL)
  {
    cout<<"List is empty!"<<endl;
  }

  else
  {
    save=head->next;
    save->next=head->next->next;
    head=save;
  }
}

void linkedList::deleteTail()
{
  if(tail==NULL)
  {
    cout<<"List is empty!"<<endl;
  }

  if(head==tail)
  {
    delete head;
    head=tail=NULL;
  }

  else
  {
    Node *tmp;
    for(tmp=head; tmp->next!=tail; tmp=tmp->next);
    delete tail;
    tail=tmp;
    tail->next=NULL;
  }
}

int main()
{
  linkedList list;
  list.addAtEnd(45);
  list.addAtEnd(34);
  list.addAtEnd(32);
  list.print();
  list.deleteTail();
  list.addAtStart(256);
  list.print();
  list.deleteHead();
  list.print();
  return 0;
}
