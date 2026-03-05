#include<iostream>
using namespace std;
class queue
{
  int front,rear;
  int a[5];
  
  public:
  queue()
  {
    front=0;
    rear=-1;
  }
  
  void insert(int x)
  {
    if(rear==4)
    {
      cout<<"Queue is full"<<endl;
    }
    else
    {
      a[++rear]=x;
      cout<<x<<"insreted"<<endl;
    }
  }
  
  void remove()
  {
    if(front>rear)
    {
      cout<<"Queue is empty"<<endl;
    }
    else
    {
      cout<<a[front++]<<"Deleted"<<endl;
    }
  }
};

int main()
{
  queue q;
  q.insert(10);
  q.insert(20);
  q.remove();
  
  return 0;
  
}
  
  
  
