#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
#define R 4
#define C 4

using namespace std;

struct mystack{

int *arr;
int top;
int cap;
    mystack(int c)
    {
        cap=c;
        arr= new int[cap];
        top=-1;
    }

    void push(int data)
    {
        if(top==cap-1)
        {
            cout<<"stack overflow";
        }
        else
        {
            top++;
        arr[top]=data;
        }
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"stack underflow";
            return -1;
        }
        else
        {   int res=arr[top];
            top--;
            return res;
        }
    }

    int len()
    {
        return top+1;
    }

    int peek()
    {   if(top==-1)
    {
        return -1;
    }
        return arr[top];
    }
    bool isempty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_stack()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
    }


};

//linked list implementation of stack

struct node
{
    int data;
    node*next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

struct Mystack{

node*top;
int sz;
    Mystack()
    {
        top=NULL;;
        sz=0;
    }
    void push(int data)
    {
        sz++;
        node*p=new node(data);
        p->next=top;
        top=p;

    }

    int pop()
    {
        if(top==NULL)
        {
            return -1;
        }
        sz--;
        int temp=top->data;
        node* t=top;
        top=top->next;
        delete t;
        return temp;

    }
    int len()
    {
        return sz;
    }
    int peek()
    {
        if(top==NULL)
        {
            return -1;
        }
        return top->data;
    }
    void print_stack()
    {
        node*curr=top;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }

};

//function to check balanced brackets
bool balanced(string S)
{
    stack<char>st;
    unordered_map<char,char>h;
    h['}']='{';
    h[')']='(';
    h[']']='[';

    int len=S.length();
    for(int i=0;i<len;i++)
    {
        if(S[i]=='(' || S[i]== '[' || S[i]=='{')
            {
                st.push(S[i]);
            }
        else
        {
            if(st.empty())
            {

                return false;
            }
            else if(h[S[i]]!=st.top())
            {
                cout<<"here";
                return false;
            }
            else
            {
                st.pop();
            }
        }
        }


        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

//structure to accomodate two stacks in a single array
struct twostack{
int *arr;
int cap;
int top1;
int top2;
 twostack(int x)
 {
     cap=x;
     arr=new int[x];
     top1=-1;
     top2=cap;

 }

 void push1(int item)
 {
    if(top1<top2-1)
    {
        top1++;
        arr[top1]=item;
    }
    else
    {
        cout<<"stack overflow1";
    }
 }

 void push2(int item)
 {

     if(top2>top1+1)
     {
         top2--;
         arr[top2]=item;
     }
     else
     {
         cout<<"stack overflow2";
     }
 }

 int pop1()
 {
     if(top1>=0)
     {
         int x=arr[top1];
         top1--;
         return x;
     }
     else
     {
         cout<<"UNERFLOW";
         return 0;
     }
 }

  int pop2()
 {
     if(top2<cap)
     {
         int x=arr[top2];
         top2++;
         return x;
     }
     else
     {
         cout<<"UNERFLOW";
         return 0;
     }
 }



};
//function to find stock span
void stock_span(int arr[],int n)
{
    int arr2[n];

    for(int i=n-1;i>=0;i--)
    { int counter=1;
        for(int j=i-1;j>=0;j--)
        {

            if(arr[j]>arr[i])
            {
                break;
            }
            else
            {
                counter++;
            }
        }

        arr2[i]=counter;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr2[i]<<" ";

    }
}

//function to find the stock span
void stock (int arr[],int n)
{
    int arr2[n];
    stack<int>h;
    for(int i=0;i<n;i++)
    {
        while(h.empty()==false)
        {
            if(arr[h.top()]>arr[i])
            {
                arr2[i]=i-h.top();

                break;
            }
            else
            {
                h.pop();
            }
        }
        if(h.empty())
        {
            arr2[i]=i+1;

        }
        h.push(i);
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr2[i]<<" ";
    }
}

//function to find closest previous greater element
void prev_greater(int arr[],int n)
{
    stack <int>h;
    int arr2[n];
    for(int i=0;i<n;i++)
    {
        while(h.empty()==false && h.top()<=arr[i])
        {
            h.pop();
        }
        if(h.empty()==true)
        {
            arr2[i]=-1;
        }
        else
        {
            arr2[i]=h.top();
        }
        h.push(arr[i]);

    }
    for(int i=0;i<n;i++)
    {
        cout<<arr2[i]<<" ";
    }
}

//function to find the next greater element on right side of an element

void next_greater(int arr[],int n)
{
    stack<int>h;
    int arr2[n];
    for(int i=n-1;i>=0;i--)
    {
        while(h.empty()==false && h.top()<=arr[i])
        {
            h.pop();
        }
        if(h.empty()==true)
        {
            arr2[i]=-1;
        }
        else
        {
            arr2[i]=h.top();
        }
        h.push(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr2[i]<<" ";
    }
}

//function to find the greatest area
int greatest_area(int arr[],int n)
{    int max_area=0;;
    for(int i=0;i<n;i++)
    {

        int min_rec=arr[i];
        for(int j=i+1;j<n;j++)
        {
            min_rec=min(min_rec,arr[j]);
            max_area=max(max_area,min_rec*(j-i+1));
        }

    }
    max_area=max(max_area,arr[n-1]);
    return max_area;
}

//function to find max_area
int greatest_a(int arr[],int n)
{
    int nextSmaller[n];
    int prevSmaller[n];
    stack<int>NS;
    stack<int>PS;
    for(int i=0;i<n;i++)
    {
        while(PS.empty()==false && arr[PS.top()]>=arr[i])
        {
            PS.pop();
        }
        if(PS.empty())
        {
            prevSmaller[i]=i+1;
        }
        else
        {
            prevSmaller[i]=i-PS.top();
        }
        PS.push(i);

    }

    for(int i=n-1;i>=0;i--)
    {
        while(NS.empty()==false && arr[NS.top()]>=arr[i])
        {
            NS.pop();
        }
        if(NS.empty())
        {
            nextSmaller[i]=n-i-1;
        }
        else
        {
            nextSmaller[i]=NS.top()-i-1;
        }
        NS.push(i);

    }
    for(int i=0;i<n;i++)
    {
        cout<<nextSmaller[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<prevSmaller[i]<<" ";
    }
    cout<<endl;
    int max_greater=0;
    for(int i=0;i<n;i++)
    {
        max_greater=max(max_greater,arr[i]*(nextSmaller[i]+prevSmaller[i]));
    }

    return max_greater;
}

//function to find the maximum area ----retry---

int maxarea(int arr[],int n)
{
    stack<int>h;
    int res=0;
    int curr;
    int tp;
    for(int i=0;i<n;i++)
    {
        while(h.empty()==false && arr[h.top()]>=arr[i])
        {
            tp=h.top();
            h.pop();
            if(h.empty()){
                 curr=arr[tp]*i;
            }
            else
            {
                curr=arr[tp]*(i-h.top()-1);
            }
            res=max(curr,res);
        }
        h.push(i);
    }

    while(h.empty()==false)
    {

        tp=h.top();h.pop();
        curr=arr[tp]* (h.empty() ? n : n - h.top() - 1);
        res=max(res,curr);
    }
    return res;
}

//function to find the maximum area in a binary grid

int max_area(int arr[][C])
{
    int res= maxarea(arr[0],C);
    for(int i=1;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(arr[i][j])
            {
                arr[i][j]+=arr[i-1][j];
            }
        }
        res=max(res,maxarea(arr[i],C));
    }
    return res;
}

//Design a stack that enables  getmin() operation in O(1) time complexity
struct MYSTACK{
int *arr;
int *min_arr;
int cap;
int top;
int min_top;

MYSTACK(int x)
{
    cap=x;
    arr=new int[x];
    top=-1;
    min_arr=new int[x];
    min_top=-1;
}

void push(int item)
{
    if(top==-1)
    {min_top++;
     arr[top]=item;
     min_arr[min_top]=item;
    }

    top++;
    if(top==cap)
    {
        cout<<"stack overflow";
        return;
    }
    else
    {   top++;
        arr[top]=item;
        if(min_arr[min_top]>=item)
        {
            min_top++;
            min_arr[min_top]=item;
        }
    }
}

int pop()
{
    if(top==-1)
    {
        cout<<"stack underflow";
        return -1;
    }
    else
    {
        int t=arr[top];
        top--;
        if(min_arr[min_top]==t)
        {
            min_top--;
        }
        return t;
    }

}

int getmin()
{
    cout<<min_top;
    return min_arr[min_top];
}

};

//function to find the minimum of an stack
struct STACK
{
    int top;
    int *arr;
    int m;
    int cap;
    STACK(int x)
    {
        cap=x;
        arr=new int[x];
        m=INT_MAX;
        top=-1;
    }
    void push(int item)
    {
        if(top==-1)
        {
            m=item;
            top++;
            arr[top]=item;
        }
        top++;
        if(top==cap)
        {
            cout<<"stack overflow";
            return;
        }
        if(m>=item)
        {
            arr[top]=2*item-m;
            m=item;
        }
        else
        {
            arr[top]=item;
        }
    }

    int pop()
    {
        if(top==-1)
        {
            cout<<"stack overflow";
            return -1;
        }
        else
        {
            if(arr[top]<=m)
            {
                int t=m;
                m=2*m-arr[top];
                top--;
                return t;
            }
            else
            {
                int t=arr[top];
                top--;
                return t;
            }
        }
    }

};


int main()
{
  /*mystack se(5);
  se.push(24);
  se.push(30);
  se.push(55);
  se.push(47);
  se.print_stack();
  cout<<endl;
  cout<<se.pop()<<" ";
  cout<<se.pop();
  se.print_stack();
  cout<<se.len();*/
STACK se(10);
se.push(10);
se.push(16);
se.push(40);
se.push(60);
se.push(8);


cout<<se.m;





}
