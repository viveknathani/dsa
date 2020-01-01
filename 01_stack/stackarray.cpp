#include<iostream>
#define MAX 1000

using namespace std;

class stack
{
private:
  int top;

public:
  int a[MAX];
  stack();
  void push(int x);
  void pop();
  int topx();
  bool isEmpty();
  void display();
};

stack::stack()
{
  top=-1;
}

void stack::push(int x)
{
  if(top>=MAX-1)
  {
    cout<<"Stack overflow"<<endl;
  }
  else
  {
    a[++top]=x;
    cout<<"Pushed "<<x<<endl;
  }
}

void stack::pop()
{
  if(top<0)
  {
    cout<<"Stack underflow"<<endl;
  }
  else
  {
    int tmp;
    tmp=a[top--];
    cout<<"Popped "<<tmp<<endl;
  }
}

int stack::topx()
{
  if(top<0)
  {
    cout<<"Stack is empty"<<endl;
    return 0;
  }
  else
  {
    return a[top];
  }
}

bool stack::isEmpty()
{
  return (top<0);
}

void stack::display()
{
  if(isEmpty())
  {
    cout<<"Stack is empty"<<endl;
  }
  else
  {
    cout<<"Stack elements are: ";
    for(int i=0; i<=top; i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
}

int main()
{
  stack s;
  s.push(5);
  s.push(10);
  s.display();
  s.pop();
  s.display();
  s.pop();
  s.display();
  return 0;
}
