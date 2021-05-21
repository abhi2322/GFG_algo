#include <iostream>
#include <deque>

using namespace std;

struct Dequeue{
int cap;
int *arr;
int front;
int size;
    Dequeue(int x)
    {
        arr=new int[x];
        cap=x;
        front=0;
        size=0;
    }

    bool isFull()
    {
        if(size==cap)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if(size==0)
            return true;
        return false;
    }

    void insertAtFront(int data)
    {
        if(isFull())
        {
            return;
        }
        front=(front+cap-1)%cap;
        arr[front]=data;
        size++;
    }

    void insertAtRear(int data)
    {
        if(isFull())
        {
            return;
        }
        int rear=front+size-1;
        rear=(rear+1)%cap;
        arr[rear]=data;
        size++;
    }

    void deleteAtFront()
    {
        if(isEmpty())
        {
            return;
        }
        arr[front]=0;
        front=(front+1)%cap;
        size--;
    }
    void deletAtRear()
    {
        if(isEmpty())
        {
            return;
        }
        size--;
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
        return arr[(front+size-1)%cap];
    }



};

//functions to maintain max/min
struct min_max{
deque<int>dq;
 void insert_min(int data)
 {

        dq.push_front(data);
 }
 void insert_max(int data)
 {

        dq.push_back(data);
 }
 int getMin()
 {
     if(dq.empty())
     {
         return -1;
     }
     return dq.front();
 }
 int getMax()
 {
     if(dq.empty())
     {
         return -1;
     }
     return dq.back();
 }
 int delete_min()
 {
     int x=dq.front();
    dq.pop_front();
    return x;
 }

 int delete_max()
 {
    int x=dq.back();
    dq.pop_back();
    return x;
 }


};

//function to find max in all subsequent
void findMax(int arr[],int n,int k)
{
    deque<int>dq;
    int i;
   for( i=0;i<k;i++)
   {
       while(dq.empty()==false&&arr[i]>=arr[dq.back()])
       {
           dq.pop_back();
       }
       dq.push_back(i);
   }
   for(i=k;i<n;i++)
   {
       cout<<arr[dq.front()]<<" ";
       while(dq.empty()==false&&dq.front()<=i-k)
       {
           dq.pop_front();
       }
       while(dq.empty()==false&&arr[i]>=arr[dq.back()])
       {
           dq.pop_back();
       }
       dq.push_back(i);
   }
   cout<<arr[dq.front()];
}
//function to find the start point
void start_point(int dis[],int n,int p[])
{
    int res=-1;
    for(int i=0;i<n;i++)
    {
        int carry=p[i]-dis[i];
        int flag=false;
        int j=i+1;
        if(carry<0)
        {
            continue;
        }
        while(true)
        {
            carry=p[j]-dis[j]+carry;
            if(carry<0)
            {
                break;
            }
            if(j==i)
            {
                flag=true;
                break;
            }

            j=(j+1)%n;
        }

        if(flag)
        {
            res=i+1;;
            break;
        }
    }
    cout<<res;
}

//function to find the

int main()
{
int p[]={8,9,4};
int dis[]={5,10,12};
start_point(dis,3,p);
}




