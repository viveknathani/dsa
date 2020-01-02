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
  Node *front, *rear, *ptr;
public:
  linkedList();
  void enQueue(int value);
  void deQueue();
  void print();
};

linkedList::linkedList()
{
  front=NULL;
  rear=NULL;
}

void linkedList::enQueue(int value)
{
  ptr=new Node;
  ptr->data=value;
  ptr->next=NULL;

  if(front==NULL)
  {
    front=ptr;
    rear=ptr;
  }
  else
  {
    rear->next=ptr;
    rear=rear->next;
  }

  cout<<"enQueued "<<rear->data<<endl;
}

void linkedList::deQueue()
{
  if(front==NULL)
  {
    cout<<"Queue is empty!"<<endl;
  }

  else
  {
    Node *n=front;
    cout<<"deQueued "<<front->data<<endl;
    front=front->next;
    delete n;
  }
}

void linkedList::print()
{
  Node *temp=front;
  while(temp!=NULL)
  {
    cout<<temp->data<<"--";
    temp=temp->next;
  }
  cout<<"|"<<endl;
}

int main()
{
  linkedList q;
  for(int i=1; i<=10; i++)
  {
    q.enQueue(i);
  }
  q.print();
  for(int i=1; i<=10; i++)
  {
    q.deQueue();
  }
  return 0;
}
