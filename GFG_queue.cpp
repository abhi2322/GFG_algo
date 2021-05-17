#include <iostream>
#include<queue>
using namespace std;

struct Queue{
int *arr;
int s;
int cap;
    Queue(int x)
    {
        arr=new int[x];
        cap=x;
        s=0;
    }
    bool isEmpty()
    {
        if(s==0)
            return true;
        return false;
    }

    bool isFull()
    {
        if(s==cap)
        {
            return true;
        }
        return false;
    }

    void EnQueue(int data)
    {
        if(isFull())
        {
            cout<<"Overflow";
            return;
        }
        arr[s]=data;
        s++;
    }

    void DeQueue()
    {
        if(isEmpty())
        {
            cout<<"underflow";
            return;
        }
        for(int i=0;i<s-1;i++)
        {
            arr[i]=arr[i+1];
        }
        s--;
    }

    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[0];
        }
    }

    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[s-1];
    }

};

struct myqueue{
int *arr;
int cap;
int s;
int front;

myqueue(int x)
{
    cap=x;
    arr=new int[cap];
    s=0;
    front=0;
}
    bool isEmpty()
    {
        return !s;
    }
    bool isFull()
    {
        if(s==cap)
        {
            return true;
        }
        return false;

    }

    void Enqueue(int data)
    {
        if(isFull())
        {
            cout<<"overflow";
            return;
        }

        arr[(front+s)%cap]=data;
        s++;
    }

    void Deqeue()
    {
        if(isEmpty())
        {
            cout<<"underflow";
            return;
        }
        arr[front]=0;
        front=(front+1)%cap;
        s--;
    }
    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[(front+s-1)%cap];
    }
};

struct node{
int data;
node*next;

    node(int x)
    {
        data=x;
        next=NULL;
    }
};

struct LinkQueue{

node*head;
node*tail;
int size;
    LinkQueue()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    void EnQueue(int data)
    {
        node*p=new node(data);
        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
        {
            tail->next=p;
            tail=p;
        }
        size++;
    }
    void DeQueue()
    {
        if(head==NULL)
        {
            return;
        }
        node*temp=head;
        if(head->next==NULL)
        {
            head=NULL;
            tail=NULL;
        }
        else
        {
        head=head->next;
        }
        size--;
        delete temp;;
    }

    int getRear()
    {
        if(tail==NULL)
        {
            return -1;
        }
        return tail->data;
    }

    int getFront()
    {
        if(head==NULL)
        {
            return -1;
        }
        return head->data;
    }
    int getSize()
    {
        return size;
    }

};

//implementing stack using two queue

struct mystack{
queue<int>q1;
queue<int>q2;

    int getTop(){
    return q1.front();
    }

    int getSize()
    {
        return q1.size();
    }
    void pop()
    {
        if(q1.empty())
        {
            return;
        }
        q1.pop();

    }

    void push(int data)
    {
        q2.push(data);
        while(q1.empty()==false)
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }


};

struct mystack2{
queue<int>q1,q2;
    int top()
    {
        return q1.back();
    }
    int getSize()
    {
        return q1.size();
    }
    void push(int data)
    {
        q1.push(data);
    }
    void pop()
    {
        if(q1.size()==0)
        {
            return;
        }
     while(q1.size()!=1)
     {
         q2.push(q1.front());
         q1.pop();
     }
     q1.pop();
    swap(q1,q2);
    }
};

//function to reverse a queue
void reversequeue(queue<int>&q)
{
    if(q.empty()==true)
    {
        return;
    }
    int temp=q.front();
    q.pop();
    reversequeue(q);
    q.push(temp);
}

//function to implement stack using queue
struct mystack3{
queue<int>q1;

    int top(){
        return q1.front();
    }

    void push(int data)
    {
        reversequeue(q1);
        q1.push(data);
        reversequeue(q1);
    }
    void pop()
    {
        q1.pop();
    }


};

//function to print numbers containing the set
void print_n(int n)
{
    queue<int>Q;
    Q.push(5);
    Q.push(6);
    int count=0;
    while(count<n)
    {  int temp=Q.front();
        cout<<temp<<" ";
        Q.pop();
        Q.push(temp*10+5);
        Q.push(temp*10+6);
        count++;

    }
}


int main()
{
    print_n(100);

}
