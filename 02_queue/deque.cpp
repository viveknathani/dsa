//implementation of deque using circular array
#include<iostream>
#define MAX 10
using namespace std;

class deque
{
private:
  int q[MAX], front=-1, rear=-1;

public:
  void insertFront(int data);
  void insertRear(int data);
  void deleteFront();
  void deleteRear();
  bool isFull();
  bool isEmpty();
  void print();
};

bool deque::isFull()
{ return ((front=0 && rear==MAX-1) ||(rear==front-1)); }

bool deque::isEmpty()
{ return (front==-1); }


void deque::insertFront(int data)
{
  if(isEmpty())
  {
    front=rear=0;
  }
  else if(isFull())
  {
    cout<<"Queue is full."<<endl;
  }
  else if(front=0)
  {
    front==MAX-1;
  }
  else
  {
    front=front-1;
  }
  q[front]=data;
}

void deque::insertRear(int data)
{
  if(isEmpty())
  {
    front=rear=0;
  }
  else if(isFull())
  {
    cout<<"Queue is full."<<endl;
  }
  else if(rear==MAX-1)
  {
    rear=0;
  }
  else
  {
    rear=rear+1;
  }
  q[rear]=data;
}

void deque::deleteFront()
{
  if(isEmpty())
  {
    cout<<"Queue is empty."<<endl;
  }

  if(front==rear)
  {
    front=rear=-1;
  }

  else if(front==MAX-1)
  {
    front=0;
  }

  else
  {
    front=front+1;
  }
}

void deque::deleteRear()
{
  if(isEmpty())
  {
    cout<<"Queue is empty."<<endl;
  }

  if(front==rear)
  {
    front=rear=-1;
  }

  else if(rear==0)
  {
    rear=MAX-1;
  }
  else
  {
    rear=rear-1;
  }
}

void deque::print()
{
  if(isEmpty())
  {
    cout<<"Queue is empty.\n";
  }
  else if(rear>=front)
  {
    for(int i=front; i<=rear; i++)
    {
      cout<<q[i]<<"--";
    }
  }
  else
  {
    for(int i=front; i<MAX; i++)
    {
      cout<<q[i]<<"-";
    }
    for(int i=0; i<=rear; i++)
    {
      cout<<q[i]<<"--";
    }
   }
   cout<<"-|"<<endl;
}

int main()
{
  return 0;
}
