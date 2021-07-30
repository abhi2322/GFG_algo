#include <iostream>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<queue>
using namespace std;
struct node{
int key;
node*right;
node*left;
int lnode;
    node(int x)
    {
        left=NULL;
        right=NULL;
        key=x;
        lnode=0;
    }
};
//insertion in BST
void insert_node(node*&root,int key)
{

    if(root==NULL)
    {
        root=new node(key);
        return;
    }
    if(root->key<key)
    {
        if(root->right!=NULL)
        {
            insert_node(root->right,key);
        }
        else
        {
            root->right=new node(key);
            return;
        }
    }
    else
    {
        if(root->left!=NULL)
        {
            insert_node(root->left,key);
        }
        else
        {
            root->left=new node(key);
            return;
        }

    }
}
//insertion in BST recursive effective
node*in(node*root,int key)
{
    if(root==NULL)
    {
        return new node(key);
    }
    if(root->key<key)
    {
        root->right=in(root->right,key);
    }
    else{
        root->left=in(root->left,key);
        root->lnode++;
    }
    return root;
}

//insertion in BST iterative
node*insert_iterative(node*root,int key)
{    node*curr=root;
     node*prev=NULL;
    while(curr!=NULL)
    {
        prev=curr;
        if(curr->key<key)
        {
            curr=curr->right;
        }
        else if(curr->key>key)
        {
            curr->lnode++;
            curr=curr->left;
        }
        else
        {
            return root;
        }

    }
  if(prev==NULL)
  {
      return  new node(key);
  }
  if(prev->key<key)
  {
      prev->right=new node(key);
  }
  else
  {
      prev->left=new node(key);
  }
   return root;
}

//function to delete in BST
node*getSucssesor(node*root)
{
    root=root->right;
    while(root!=NULL&&root->left!=NULL)
    {
        root=root->left;
    }
    return root;

}
node* delete_node(node*root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->key<key)
    {
        root->right=delete_node(root->right,key);
    }
    else if(root->key>key)
    {
        root->left=delete_node(root->left,key);
    }
    if(root->key==key)
    {
       if(root->left==NULL)
       {
           node*temp=root->right;
           delete root;
           return temp;
       }
       else if(root->right==NULL)
       {
           node*temp=root->left;
           delete root;
           return temp;
       }
       else
       {
           node*temp=getSucssesor(root);
           root->key=temp->key;
           root->right=delete_node(root->right,temp->key);
       }
    }
    return root;
}


void preorder(node*root)
{
    if(root!=NULL)
    {

    preorder(root->left);
    cout<<root->key<<":"<<root->lnode<<" ";
    preorder(root->right);
    }
}


//function to return floor of an number
int floor(node*root,int key)
{
    node*curr=root;
    int flor=-1;
    while(curr!=NULL)
    {
        if(curr->key<key)
        {
            flor=curr->key;
            curr=curr->right;
        }
        else if(curr->key>key)
        {
            curr=curr->left;
        }
        else
        {
            return curr->key;
        }
    }
    return flor;
}


//function to find the ceil of a number
int ceil(node*root,int key)
{
    node*curr=root;
    int cel=-1;
    while(curr!=NULL)
    {
        if(curr->key==key)
        {
            return curr->key;
        }
        else if(curr->key>key)
        {
            cel=curr->key;
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
    return cel;
}

//function to print ceil of an array
void ceil2(int arr[],int n)
{
    cout<<"-1 ";
    set<int>s;
    s.insert(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(s.lower_bound(arr[i])!=s.end())
        {
            cout<<*(s.lower_bound(arr[i]))<<" ";
        }
        else
        {
            cout<<"-1 ";
        }
        s.insert(arr[i]);
    }


}

//function to find the kth smallest node in a binary tree
int kth_smallest(node*root,int k)
{
    node*curr=root;
    while(curr!=NULL)
    {
        if(curr->lnode+1==k)
        {
            return curr->key;
        }

        else if(curr->lnode+1>k)
        {
            curr=curr->left;
        }
        else
        {
            k=k-curr->lnode-1;
            curr=curr->right;

        }
    }
    return -1;
}

//function to check if a tree is BST or not
bool BST(node*root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    else
    {
        return root->key>min&&root->key<max&&BST(root->left,min,root->key)&&BST(root->right,root->key,max);
    }
}

//function to check is a tree is BST or not
bool BST1(node*root,int &prev)
{
    if(root==NULL)
    {
        return true;
    }

    if(BST1(root->left,prev)==false)
    {return false;}
    if(root->key<=prev)
    {
        return false;
    }
    else
    {
        prev=root->key;
    }
    return BST1(root->right,prev);
}

//function to repair a BST whose two nodes are swapped

    node*prevv=NULL;
    node* first=NULL;
    node* second=NULL;
void swaap(node*root)
{
    if(root==NULL)
    {
        return;
    }
    swaap(root->left);
    if(prevv!=NULL&&root->key < prevv->key)
        {
            if(first==NULL)
            {
                first=prevv;
                second=root;
            }else
            {
                second=root;
            }
        }
        prevv=root;
     swaap(root->right);

}

//function to find a pair of given sum in a tree
bool find_pair(node*root,int sum)
{
    static unordered_set<int>h;
    if(root==NULL)
    {
        return false;
    }
    if(find_pair(root->left,sum)==true)
    return true;
    if(h.find(sum-root->key)!=h.end())
    {
        return true;
    }
    else
    {
        h.insert(root->key);
    }

    return find_pair(root->right,sum);
}

//function to print vertical sum
map<int,int>m;
void vertical_sum(node*root,int lvl)
{

    if(root==NULL)
    {
        return;
    }
    m[lvl]+=root->key;
    vertical_sum(root->left,lvl-1);
    vertical_sum(root->right,lvl+1);
}

//function to print in vertical direction

void vertical_sum2(node*root)
{
    map<int,vector<int>>ver;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(q.empty()==false)
    {
        auto p=q.front();
        node*curr=p.first;
        int hd=p.second;
        q.pop();
        ver[hd].push_back(curr->key);
        if(curr->left)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right)
        {
            q.push({curr->right,hd+1});
        }
    }

    for(auto p:ver)
    {
        vector<int>c=p.second;
        for(auto z:c)
        {
            cout<<z<<" ";
        }
        cout<<endl;
    }

}

//function to print top view of BST


void top_view(node*root)
{
    map<int,int>ver;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(q.empty()==false)
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
        auto p=q.front();
        node*curr=p.first;
        int hd=p.second;
        q.pop();
        if(ver.find(hd)==ver.end())
        {
            ver[hd]=curr->key;
        }
        if(curr->left)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right)
        {
            q.push({curr->right,hd+1});
        }
        }
    }

    for(auto p:ver)
    {
        cout<<p.first<<":"<<p.second<<" ";
    }

}

//function to print the bottom view of the binary tree
void bottom_view(node*root)
{
    map<int,int>ver;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(q.empty()==false)
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
        auto p=q.front();
        node*curr=p.first;
        int hd=p.second;
        q.pop();
        ver[hd]=curr->key;
        if(curr->left)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right)
        {
            q.push({curr->right,hd+1});
        }
        }

    }
    for(auto x:ver)
    {
        cout<<x.first<<":"<<x.second<<" ";
    }
}



int main()
{
    node*root=new node(60);
    root->left=new node(8);
    root->left->left=new node(4);
    root->left->right=new node(10);
    root->right=new node(80);
    root->right->left=new node(20);
    root->right->right=new node(100);
    swaap(root);

    int temp=second->key;
    second->key=first->key;
    first->key=temp;
    bottom_view(root);
}

