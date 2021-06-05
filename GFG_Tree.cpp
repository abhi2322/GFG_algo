#include <iostream>
#include<queue>
#include<stack>
#include<deque>
#include<unordered_map>
#include<math.h>

using namespace std;

struct node{

int key;
node*left;
node*right;
    node(int x)
    {
        key=x;
        left=NULL;
        right=NULL;
    }
};

//function to traverse in inorder
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->key<<" ";
        return;
    }
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->key<<" ";
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";

}

void preorder(node*root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

//function to find height of binary tree
int height(node*root)
{
   if(root==NULL)
   {
       return 0;
   }

   return max(height(root->left),height(root->right))+1;

}

//function to print nodes after k distance
void K_distance(node*root,int k)
{
    if(root!=NULL)
    {
        K_distance(root->left,k-1);
        if(k==0)
        {
            cout<<root->key<<" ";
        }
        K_distance(root->right,k-1);

    }
}

//function to print in breath first manner level order
void level_order(node*root)
{
    queue<node*>q;
    if(root==NULL)
       {
           return;
       }
    q.push(root);
    while(q.empty()==false)
        {
            if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL)
            {
                q.push(q.front()->right);
            }
            cout<<q.front()->key<<" ";
            q.pop();
        }
}

//function to print every level line by line
void Level(node*root)
{
    queue<node*>p;
    p.push(root);
    p.push(NULL);
    while(p.front()!=NULL)
    {
            node*curr=p.front();
            if(curr->left!=NULL)
            {
                p.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                p.push(curr->right);
            }
            cout<<curr->key<<" ";
            p.pop();
            if(p.front()==NULL)
            {
                p.pop();
                cout<<endl;
                p.push(NULL);
            }
    }
}

void Level2(node*root)
{
    queue<node*>q;
    q.push(root);
    while(q.empty()==false)
    { int count=q.size();
        for(int i=0;i<count;i++)
        {
            node*curr=q.front();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            q.pop();
        }
        cout<<endl;
    }
}

//function to find number of nodes
int counter(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    queue<node*>q;
    q.push(root);
    int count=0;
    while(q.empty()==false)
    {
         node*curr=q.front();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            count++;
            q.pop();
    }
    return count;
}

//function to return size of binary tree
int counter2(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+counter2(root->left)+counter2(root->right);
}

//function to find maximum number in a binary tree
int max_number(node*root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }

    return max(max(max_number(root->left),max_number(root->right)),root->key);
}

void left_view(node*root)
{
    queue<node*>q;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        cout<<q.front()->key<<" ";
        for(int i=0;i<count;i++)
        {
            node*curr=q.front();
              if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            q.pop();
        }
    }

}

//function to print left-view of binary tree
int maxlevel=0;
void print_left(node*root,int level)
{
    if(root==NULL)
    {
        return;
    }

    if(maxlevel<level)
    {
        cout<<root->key<<" ";
        maxlevel=level;
    }
    print_left(root->left,level+1);
    print_left(root->right,level+1);
}

//function to check if tree follows child sum property
bool sum(node*root)
{
    if(root==NULL)
    {
        return true;
    }
    queue<node*>q;
    q.push(root);

    while(q.empty()==false)
    {
        node*curr=q.front();
        int sum=0;
        if(curr->left!=NULL)
        {
            q.push(curr->left);
            sum+=curr->left->key;
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
            sum+=curr->right->key;
        }
        if(sum!=curr->key&&sum!=0)
        {
            return false;
        }
        q.pop();
    }
    return true;

}

//function to find if tree follows child sum property
bool sum2(node*root)
{
     if(root==NULL)
    {
        return true;
    }
    if(root->right==NULL&&root->left==NULL)
    {
        return true;
    }
    int sum=0;
    if(root->left!=NULL)
    {
        sum+=root->left->key;
    }
    if(root->right!=NULL)
    {
        sum+=root->right->key;
    }

    return (sum==root->key)&&sum2(root->left)&&sum2(root->right);
}

//function to check if tree is balanced or not
int balanced(node*root)
{
  if(root==NULL)
  {
      return 0;
  }
  int left_l=balanced(root->left);
  int right_l=balanced(root->right);
  if(left_l==-1||right_l==-1)
  {
      return -1;
  }
  if(abs(left_l-right_l)>1)
  {
      return -1;
  }

  return 1+max(left_l,right_l);
}

//function to find maximum width of an tree
int max_width(node*root)
{
    queue<node*>q;
    q.push(root);
    int width=0;
    while(q.empty()==false)
    {
        int count=q.size();
        width=max(width,count);
        for(int i=0;i<count;i++)
        {
            node*curr=q.front();
              if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            q.pop();
        }
    }
    return width;
}

//function to convert tree into doubley linked linked list in place

node* convert(node*root)
{
    if(root==NULL)
    {
        return NULL;
    }
    static node*prev=NULL;
    node*head=convert(root->left);
    if(prev==NULL)
    {
        head=root;
    }
    else
    {
        prev->right=root;
        root->left=prev;
    }
    prev=root;
    convert(root->right);
    return head;
}

//function to make a binary tree from inorder and pre-order traversal
int preIndex=0;
node* binary_tree(int in[],int pre[],int start,int end)
{
    if(end<start)
    {
       return NULL;
    }
     node*root=new node(pre[preIndex++]);
    int mid;
    for(int i=start;i<=end;i++)
    {
        if(in[i]==root->key)
        {
            mid=i;
            break;
        }
    }
    root->left=binary_tree(in,pre,start,mid-1);
    root->right=binary_tree(in,pre,mid+1,end);
    return root;
}

//function to print elements of tree in a spiral form
void print_spiral(node*root)
{
    int reverseal=false;
    queue<node*>q;
    q.push(root);
    stack<node*>s;
    while(q.empty()==false)
    {
        int count=q.size();
        if(reverseal)
        {
            for(int i=0;i<count;i++)
            {node*curr=q.front();
             q.pop();
              s.push(curr);
              if(curr->left!=NULL)
              {
                  q.push(curr->left);
              }
              if(curr->right!=NULL)
              {
                  q.push(curr->right);
              }
            }

            while(s.empty()==false)
            {
                cout<<s.top()->key<<" ";
                s.pop();
            }
            reverseal=false;
        }
        else
        {
            for(int i=0;i<count;i++)
            {node*curr=q.front();
             q.pop();
              cout<<curr->key<<" ";
              if(curr->left!=NULL)
              {
                  q.push(curr->left);
              }
              if(curr->right!=NULL)
              {
                  q.push(curr->right);
              }
            }
            reverseal=true;

        }
    }
}

//function to print tree in spiral form
void spiral_print(node*root)
{
    deque<node*>q;
    bool reversal=false;
    q.push_back(root);
    while(q.empty()==false)
    {
        int count=q.size();
        if(reversal)
        {
            for(int i=0;i<count;i++)
            {
                node*curr=q.back();
                cout<<curr->key<<" ";
                q.pop_back();
                if(curr->right!=NULL)
                {
                    q.push_front(curr->right);
                }
                if(curr->left!=NULL)
                {
                    q.push_front(curr->left);
                }
            }
            reversal=false;
        }
        else
        {
            for(int i=0;i<count;i++)
            {node*curr=q.front();
             q.pop_front();
              cout<<curr->key<<" ";
              if(curr->left!=NULL)
              {
                  q.push_back(curr->left);
              }
              if(curr->right!=NULL)
              {
                  q.push_back(curr->right);
              }
            }
            reversal=true;
        }
    }
}

//function to return max diameter of an tree
int d=0;
int max_diameter(node*root)
{
   if(root==NULL)
   {
       return 0;
   }
   int l=max_diameter(root->left);
   int r=max_diameter(root->right);
   d=max(d,l+r+1);
   return 1+max(l,r);
}

//function to find max diameter of an tree
int height2(node*root)
{
    if(root==NULL)
    {
        return 0;
    }

    return 1+max(height2(root->left),height2(root->right));
}
int max_diameter1(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int d1=1+height2(root->left)+height2(root->right);
    int d2=max_diameter1(root->left);
    int d3=max_diameter1(root->right);

    return max(d1,max(d2,d3));

}

//function to print the max diameter effective
unordered_map<node*,int>h;
int preprocess(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int h1=preprocess(root->left);
    int h2=preprocess(root->right);
    h[root]=max(h1,h2)+1;
    return max(h1,h2)+1;
}
int max_diameter2(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int d1=1+h[root->left]+h[root->right];
    int d2=max_diameter2(root->left);
    int d3=max_diameter2(root->right);
    return max(d1,max(d2,d3));
}

//function to find lca of two nodes
int prepstack(node*root,stack<int>&s,int n)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->key==n)
    {
        s.push(root->key);
        return 1;
    }
    if(prepstack(root->left,s,n)||prepstack(root->right,s,n))
    {
        s.push(root->key);
        return 1;
    }
    else
    {
        return 0;
    }
}
int lca(node*root,int n1,int n2)
{
    stack<int>s1;

    stack<int>s2;
    int c1=prepstack(root,s1,n1);
    int c2=prepstack(root,s2,n2);
    if(c1==0||c2==0)
    {
        return -1;
    }

    int res=0;
    while(s1.empty()==false && s2.empty()==false&&s1.top()==s2.top())
    {
        res=s1.top();
        s1.pop();
        s2.pop();
    }
    return res;
}

//function to find the lca of two nodes assumption both the nodes are present(note. You can also use +1 method in which whenever you see the root node you return
//+1 and as soon as it becomes two return that root node).
node* lca1(node*root,int n1,int n2)
{
    if(root==NULL)
    {
        return 0;
    }
     if(root->key==n1||root->key==n2);
    {
        return root;
    }
    node* l=lca1(root->left,n1,n2);
    node* r=lca1(root->right,n1,n2);
    if(l!=NULL&&r!=NULL)
   {
       return root;
   }

   if(l!=NULL)
   {
       return l;
   }
}

//function to find how much time it will take to burn a tree from given leaf node(naive)
/*
int burn(node*root,int n)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->key==n)
    {
        return 1;
    }

   int ln=burn(root->left,n);
   if(ln!=0)
   {int h=height(root->right);
    result=max(ln+h+1,result);
     ln++;
   }
   int rn=burn(root->right,n);
   if(rn!=0)
   {
    int h=height(root->left);
    result=max(rn+h+1,result);
    rn++;
   }

   return max(ln,rn);
}*/

//function to find time needed to burn a tree
int burn2(node*root,int n,int &d,int &result)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->key==n)
    {
        d=0;
        return 1;

    }
    int ld=-1;
    int rd=-1;
    int lh=burn2(root->left,n,ld,result);

    int rh=burn2(root->right,n,rd,result);
    if(ld!=-1)
    {
        d=ld+1;
        result=max(result,d+rh);

    }
    else if(rd!=-1)
    {
        d=rd+1;
        result=max(result,d+lh);
    }

    return max(lh,rh)+1;

}
//function to return height of a complete binary tree
int left_traversal(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+left_traversal(root->left);
}
int right_traversal(node*root)
{
    if(root==NULL)
    {
     return 0;
    }
    return 1+right_traversal(root->right);
}
int height3(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=left_traversal(root);
    int rh=right_traversal(root);
    if(lh==rh)
    {
        return pow(2,lh)-1;
    }

    return 1+height3(root->left)+height3(root->right);
}
//function for serilization
void serialize(node*root,vector<int>&s)
{
    if(root==NULL)
    {
        s.push_back(-1);
        return ;
    }
    s.push_back(root->key);
    serialize(root->left,s);
    serialize(root->right,s);

}

//function for de-serilisation

node* de_serialize(vector<int>s,int &index)
{
    if(index==(int)s.size())
    {
        return NULL;
    }
    if(s[index]==-1)
    {
        index++;
        return NULL;
    }
    node*root=new node(s[index++]);
    root->left=de_serialize(s,index);
    root->right=de_serialize(s,index);
    return root;


}

//function to delete a node in binary tree
void delete_rightmost(node*root,node*d_node)
{
    queue<node*>q;
    q.push(root);
    while(q.empty()==false)
    {
        node*temp=q.front();
        q.pop();

        if(temp->left)
        {
            if(temp->left==d_node)
            {
                temp->left=NULL;
                delete d_node;
                return;
            }
            else
            {q.push(temp->left);}
        }
        if(temp->right)
        {
            if(temp->right==d_node)
            {
                temp->right=NULL;
                delete d_node;
                return;
            }
            else
            {q.push(temp->right);}
        }
    }

}
void delete_node(node*root,int key)
{
    queue<node*>q;
    q.push(root);
    node*d_node;
    node*temp;
    while(q.empty()==false)
    {
        temp=q.front();
        q.pop();
        if(temp->key==key)
        {
            d_node=temp;
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
   d_node->key=temp->key;
    delete_rightmost(root,temp);



}

//function to do inorder traversal of tree
void inorder_iterative(node*root)
{
    stack<node*>s;
    s.push(root);
    while(s.empty()==false)
    {
        node*curr=s.top();
        if(curr->left!=NULL&&curr->left->key!=-1)
        {

            s.push(curr->left);
            continue;
        }
        cout<<curr->key<<" ";
        curr->key=-1;
        s.pop();
        if(curr->right!=NULL)
        {
            s.push(curr->right);
        }
    }
}

//function to do inorder traversal of tree
void inorder_iterative2(node*root)
{
    stack<node*>s;
    node*curr=root;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }

       curr=s.top();
       s.pop();
       cout<<curr->key<<" ";
       curr=curr->right;

    }
}

//function to perform preorder traversal of tree
void preorder_iterative(node*root)
{
    stack<node*>s;
    node*curr=root;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            cout<<curr->key<<" ";
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        curr=curr->right;
    }
}

//function to perform iterative preorder-traversal
void preorder_iterative2(node*root)
{
    stack<node*>s;
    s.push(root);
    while(s.empty()==false)
    {
        node*curr=s.top();
        cout<<curr->key<<" ";
        s.pop();
        if(curr->right)
        {
            s.push(curr->right);
        }
        if(curr->left)
        {
            s.push(curr->left);
        }
    }

}

//function to perform preorder iterative with space optimization
void preorder_iterative3(node*root)
{
    stack<node*>s;
    s.push(root);
    node*curr=root;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            cout<<curr->key<<" ";
            if(curr->right)
            {
                s.push(curr->right);
            }
            curr=curr->left;
        }
        if(s.empty()==false){
        curr=s.top();
        s.pop();
        }
    }
}

int main()
{   node*head=new node(170);
    node*child1=new node(100);
    node*child2=new node(80);
    node*child1_1=new node(40);
    node*child1_2=new node(60);
    node*child2_2=new node(70);
    head->left=child1;
    head->right=child2;
    child1->left=child1_1;
    child1->right=child1_2;
    child2->left=child2_2;
    preorder(head);
    cout<<endl;
    preorder_iterative3(head);
}
