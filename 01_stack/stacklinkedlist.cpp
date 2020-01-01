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
  void addAtEnd(int value); //push function
  void deleteTail(); //pop function
  void print();
};

linkedList::linkedList()
{
  head=NULL;
  tail=NULL;
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
  cout<<"Pushed "<<ptr->data<<endl;
}

void linkedList::print()
{
  Node *temp=head;
  if(head==NULL)
  {
    cout<<"Stack is empty"<<endl;
  }
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

void linkedList::deleteTail()
{
  if(tail==NULL)
  {
    cout<<"Stack is empty!"<<endl;
  }

  cout<<"Popped "<<tail->data<<endl;

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
  linkedList stack;
  stack.addAtEnd(5);
  stack.addAtEnd(10);
  stack.print();
  stack.deleteTail();
  stack.print();
  stack.deleteTail();
  stack.print();
  return 0;
}
