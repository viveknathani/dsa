#include<iostream>
#define MAX 1000

using namespace std;

class Queue
{
private:
  int q[MAX], front=-1, rear=-1;

public:
  void enQueue(int data);
  void deQueue();
  int getFront();
  int getRear();
  void print();
};

void Queue::enQueue(int data)
{
  if(rear==MAX-1)
  {
    cout<<"Queue overflow.\n";
  }
  else
  {
    if(front==-1) { front=0; }
    rear++;
    q[rear]=data;
    cout<<"enQueued "<<data<<endl;
  }
}

void Queue::deQueue()
{
  if(front==-1 || front>rear)
  {
    cout<<"Queue underflow.\n";
  }
  else
  {
    cout<<"deQueued "<<q[front]<<endl;
    front++;
  }
}

int Queue::getFront()
{
  return q[front];
}

int Queue::getRear()
{
  return q[rear];
}

void Queue::print()
{
  if(front==-1)
  {
    cout<<"Queue is empty.\n";
  }
  else
  {
    for(int i=front; i<=rear; i++)
    {
      cout<<q[i]<<"--";
    }
    cout<<"|"<<endl;
  }
}

int main()
{
  Queue q;
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
