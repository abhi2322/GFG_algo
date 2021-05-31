#include<bits/stdc++.h>
using namespace std;

struct min_heap
{
    int *arr;
    int cap;
    int size;

    min_heap(int x)
    {
        arr=new int[x];
        cap=x;
        size=0;
    }

    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {
        return (2*i+2);
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    void insert(int data)
    {
        if(size==cap)
        {
            cout<<"head is full";
            return;
        }
        size++;
        arr[size-1]=data;
        int i=size-1;
        while(i!=0&&arr[parent(i)]>arr[i])
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }

    }

    void heapify(int i)
    {
        int smallest=i;
        int lt=left(i);
        int rt=right(i);

        if(lt<size&&arr[lt]<arr[i])
        {
            smallest=lt;
        }
        if(rt<size&&arr[rt]<arr[smallest])
        {
            smallest=rt;
        }
        if(smallest!=i)
        {
            swap(arr[smallest],arr[i]);
            heapify(smallest);
        }
    }


    int extract_min()
    {
        if(size==0)
        {
            return INT_MIN;
        }
        if(size==1)
        {
            size --;
            return arr[0];
        }
        swap(arr[0],arr[size-1]);
        size--;
        heapify(0);
        return arr[size];
    }

    void decrease(int i,int data)
    {   arr[i]=data;
        while(i!=0&&arr[parent(i)]>arr[i])
        {
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

    void delete_key(int i)
    {
        decrease(i,INT_MIN);
        extract_min();
    }

    void build_heap()
    {

        for(int i=(cap-2)/2;i>=0;i--)
        {
            heapify(i);
        }
    }
    void sort_h()
    {
        for(int i=0;i<cap;i++)
        {
            cout<<arr[0]<<" ";
            extract_min();

        }
    }
};

//function to sort an array which is already k sorted
void k_sort(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<=k;i++)
    {
        pq.push(arr[i]);
    }
    int index=0;
    for(int i=k+1;i<n;i++)
    {
        arr[index++]=pq.top();
        pq.pop();
    }
    while(pq.empty()==false)
    {
        arr[index++]=pq.top();
        pq.pop();
    }
}

//purchase maximum number from a given sum
int max_count(int arr[],int res,int n)
{
    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+n);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(pq.top()<=res){
                count++;
            res-=pq.top();
            pq.pop();
        }
        else
        {
            break;
        }
    }
    return count;
}

//function to find first kth largest element
void first_kth(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+k);
    for(int i=k;i<n;i++)
    {
        if(pq.top()<arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while(pq.empty()==false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

//function to merge k arrays
vector<int> mergeArray(vector<int>arr1,vector<int>arr2)
{
    int i=0,j=0;
    vector<int>res;
    while(i<(int)arr1.size()&&j<(int)arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
        }
        else
        {
            res.push_back(arr2[j]);
            j++;
        }
    }
    while(i<(int)arr1.size())
    {
        res.push_back(arr1[i]);
        i++;
    }
    while(j<(int)arr2.size())
    {
        res.push_back(arr2[j]);
        j++;
    }
    return res;
}

void mergeKArray(vector<vector<int>>arr)
{
    vector<int>res;
    res=arr[0];
    for(int i=1;i<(int)arr.size();i++)
    {
        res=mergeArray(res,arr[i]);
    }
   for(int i=0;i<(int)res.size();i++)
   {
       cout<<res[i]<<" ";
   }
}

//function to merge k sorted array
struct triplet{
int data;
int vp;
int ap;
    triplet(int item,int Vp,int Ap)
    {
        data=item;
        vp=Vp;
        ap=Ap;
    }
};
struct mycamp{

    bool operator()(triplet &h1,triplet &h2)
    {
        return h1.data>h2.data;
    }
};
void mergeKArray1(vector<vector<int>>arr)
{
    priority_queue<triplet,vector<triplet>,mycamp>pq;
    vector<int>res;
    for(int i=0;i<(int)arr.size();i++)
    {
        triplet h1(arr[i][0],i,0);
        pq.push(h1);
    }
    while(pq.empty()==false)
    {
        triplet t=pq.top();
        pq.pop();
        int vp=t.vp;
        int ap=t.ap;
        res.push_back(t.data);
        if(ap+1<(int)arr[vp].size())
        {
            triplet t1(arr[vp][ap+1],vp,ap+1);
            pq.push(t1);
        }

    }
    for(int i=0;i<(int)res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}

//function to find the k nearest element to a given number
void nearest(int arr[],int n,int k,int key)
{
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<k;i++)
    {
        pq.push({abs(key-arr[i]),i});
    }
    for(int i=k;i<n;i++)
    {
        auto it=pq.top();
        int diff=abs(arr[i]-key);
        if(it.first>diff)
        {
            pq.pop();
            pq.push({diff,i});
        }
    }

    while(pq.empty()==false)
    {
        auto it=pq.top();
        pq.pop();
        cout<<arr[it.second]<<" ";
    }

}

//function to find median at every index
void median(int arr[],int n)
{
    int res[n];
    int size=1;
    res[0]=arr[0];
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j;
        for(j=size-1;j>=0;j--)
        {
            if(res[j]>temp)
            {
                res[j+1]=res[j];
            }
            else
            {
                break;
            }
        }
        res[j+1]=temp;
        size++;

        if(size%2==0)
        {
            cout<<(float)(res[size/2]+res[(size-1)/2])/2<<" ";
        }
        else
        {
            cout<<res[size/2]<<" ";
        }
    }
}

//function to print median of each element
struct node{
int data;
node*left;
node*right;
int lnode;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
        lnode=0;
    }
};

node* insert_node(node*root,int data)
{
    if(root==NULL)
    {
        return new node(data);
    }

    if(root->data<data)
    {
        root->right=insert_node(root->right,data);
    }
    else
    {
        root->left=insert_node(root->left,data);
        root->lnode++;
    }
    return root;
}

int keth_element(node*root,int k)
{
    node*curr=root;
    while(curr!=NULL)
    {
        int count=curr->lnode+1;
        if(count==k)
        {
            return curr->data;
        }
        else if(count<k)
        {
            k=k-count;
            curr=curr->right;
        }
        else
        {
            curr=curr->left;
        }
    }
    return -1;
}

float find_median(node*root,int s)
{
    if(s%2!=0)
    {
        return keth_element(root,(s/2)+1);
    }
    else
    {
        int k1=keth_element(root,(s/2)+1);
        int k2=keth_element(root,s/2);

        return (float)(k1+k2)/2;

    }
}
void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<":"<<root->lnode<<" ";
    inorder(root->right);
}

void median2(int arr[],int n)
{
    int s=0;
    node*root=NULL;
    for(int i=0;i<n;i++)
    {
        root=insert_node(root,arr[i]);
        s++;

        cout<<find_median(root,s)<<" ";
    }
}

void median3(int arr[],int n)
{
    priority_queue<int>s;
    priority_queue<int,vector<int>,greater<int>>g;
    s.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++)
    {
        if(s.size()>g.size())
        {
            if(s.top()>arr[i])
            {
                g.push(s.top());
                s.pop();
                s.push(arr[i]);
            }
            else
            {
                g.push(arr[i]);
            }
            cout<<(float)(s.top()+g.top())/2<<" ";

        }
        else
        {
           if(arr[i]<=s.top())
           {
               s.push(arr[i]);
           }
           else
           {
               g.push(arr[i]);
               s.push(g.top());
               g.pop();
           }
           cout<<s.top()<<" ";
        }
    }
}



int main()
{
    min_heap s(5);
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(5);
    s.insert(4);
    int arr[]={2,5,6,14,8,4,13,10,11};
    median3(arr,9);

    /*min_heap s(5);
    s.arr[0]=15;
    s.arr[1]=10;
    s.arr[2]=5;
    s.arr[3]=7;
    s.arr[4]=11;
    s.build_heap();
    for(int i=0;i<5;i++)
    {
        cout<<s.arr[i]<<" ";
    }
    */
}
