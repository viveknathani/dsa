#include<iostream>
#define MAX 20

using namespace std;

class circularQueue
{
private:
  int q[MAX], front=-1, rear=-1;

public:
  void insert(int data);
  void print();
  void deleteFront();
};

void circularQueue::insert(int data)
{
  if((rear==MAX-1 && front==0) || (rear==front-1))
  {
    cout<<"Queue is full.\n";
  }
  else if(rear==MAX-1 && front!=0)
  {
    rear=0;
    q[rear]=data;
  }
  else if(front==-1)
  {
    front=rear=0;
    q[rear]=data;
  }
  else
  {
    rear++;
    q[rear]=data;
  }
}

void circularQueue::deleteFront()
{
  //there are four cases to deal with

  //case 1: queue is empty
  if(front==-1)
  {
    cout<<"Queue is empty.\n";
  }

  int to_delete=q[front];
  cout<<"Deleting: "<<to_delete<<endl;

  //case 2: only one element is present
  if(front==rear)
  {
    front=rear=-1;
  }

  //case 3: front has reached its max value
  else if(front==MAX-1)
  {
    front=0;
  }

  //case 4: front is at 0 and rear<=MAX-1
  else
  {
    front++;
  }
}

void circularQueue::print()
{
  if(front==-1)
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
  circularQueue queue;
  for(int i=1; i<=MAX; i++)
  {
    queue.insert(i);
  }
  queue.print();
  for(int i=0; i<5; i++)
  {
    queue.deleteFront();
  }
  queue.print();
  return 0;
}
