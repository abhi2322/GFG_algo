#include <bits/stdc++.h>

using namespace std;

struct node{

int data;
node *next;

node(int x)
{
    data=x;
    next=NULL;
}

};

//function to traverse through a linked list
void print_list(node *head) //when we pass head we create a new local variable head and copy the address to this local head
                            //even though they point to same address they are different
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
//function to print a linked list using recursion
void printList_rec(node *head)
{
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    printList_rec(head->next);

}
//function to insert at the begning of a linked list
node * insert_begin(node *head,int data)
{

    node*p=new node(data);
    if(head==NULL)
    {
        return p;
    }
    p->next=head;
    return p;
}
//function to insert at the end in a linked list
node * insert_end(node*head,int data)
{
    node *p=new node(data);
    if(head==NULL)
    {
        return p;
    }
    node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=p;
    return head;
}
//function to delete first node of an linked list
node * deleteFirst(node*head)
{
    if(head==NULL)
        return NULL;
   node* temp=head->next;
   delete head;  // Can use free but  delete is faster as it is  an operator and free is a function also free does not call destructor but delete does
   return temp;
}
//function to delete last element of a linked list
node * deleteLast(node *head)
{
    if(head==NULL)
        return NULL;

    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }

    node*curr=head;

    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    delete curr->next;
    curr->next=NULL;
    return head;
}
//function to add a element at a given position in a linked list
node *Insert_atPos(node*head,int data,int pos)
{
    node*p=new node(data);

    if(head==NULL)
    {
        head=p;
        p->next=NULL;
        return head;
    }
    if(pos<=1)
    {
        p->next=head;
        head=p;
        return head;
    }
    node*curr=head;
    for(int i=1;i<=pos-2&&curr!=NULL;i++)
    {
        curr=curr->next;
    }
    if(curr==NULL)
    {
        return head;
    }
    p->next=curr->next;
    curr->next=p;
    return head;
}
//function to implement search in a linked list
int Search_key(node *head,int key)
{
    int pos=1;
    while(head!=NULL)
    {
        if(head->data==key)
          return pos;
        head=head->next;
        pos++;

    }
    return -1;
}

//function to implement a search in a linked list(recursive)
int search_key_rec(node*head,int key)
{
    if(head==NULL)
        return -1;
    if(head->data==key)
        return 1;
    int res=search_key_rec(head->next,key);
    if(res==-1)
    {
        return -1;
    }
    else
   {return 1+(res);}
}

struct Doublenode
{   int data;
    Doublenode *next;
    Doublenode *prev;
    Doublenode(int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }

};

//function to insert at begin of a Doublely linked list
 Doublenode * insert_at_begin(Doublenode*head,int data)
 {
     Doublenode *p=new Doublenode(data);
     p->next=head;
     if(head!=NULL)
     {
         head->prev=p;

     }
     return p;

 }
 //function to traverse through dll
 void printlist(Doublenode*head)
 {
     while(head!=NULL)
     {
         cout<<head->data<<" ";
         head=head->next;
     }
 }

 //function to insert at end of a dll
 Doublenode * insert_atend(Doublenode *head,int data)
 {
     Doublenode*p=new Doublenode(data);
     if(head==NULL)
     {
         return p;
     }
     Doublenode * curr=head;
     while(curr->next!=NULL)
     {
         curr=curr->next;
     }
     p->prev=curr;
     curr->next=p;
     return head;

 }

 //function to reverse a dll
 void reverse_dll(Doublenode*head)
 {
     Doublenode*tail=head;
     Doublenode*curr=head;
     if(head==NULL || head->next==NULL)
     {
         return;
     }
     int pos=1;
     while(tail->next!=NULL)
     {
         tail=tail->next;
         pos++;
     }
     pos=floor(pos/2);
     for(int i=1;i<=pos;i++)
     {
         int temp=curr->data;
         curr->data=tail->data;
         tail->data=temp;
         curr=curr->next;
         tail=tail->prev;

         cout<<endl;
         printlist(head);
     }


 }
 //function to reverse a dll by reference and not by swapping value
 Doublenode * reversedll(Doublenode *head)
 {
     if(head==NULL || head->next==NULL)
     {
         return head;
     }
     Doublenode *temp=head;
     Doublenode *curr=head;
     while(curr!=NULL)
    {

     temp=curr->prev;
     curr->prev=curr->next;
     curr->next=temp;
     curr=curr->prev;
     }
     return temp->prev;

 }

//function to delete the head of an doublely linked list
Doublenode * deleteHead(Doublenode *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Doublenode * temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return head;
}

//Delete last node of an Doubly linked list
Doublenode * delete_Last(Doublenode *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Doublenode *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
     curr->prev->next=NULL;
    delete curr;
    return head;


}

struct Circular_list
{
    int data;
    Circular_list*next;
    Circular_list(int x)
    {
        next=NULL;
        data=x;
    }

};

//function to print a linked list
void printCirclels(Circular_list*head)
{

    if(head==NULL)
        return;
    Circular_list*curr=head;

    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;

}

//function to insert at the head of an circular linked list(naive)
Circular_list* insert_atBegin(Circular_list*head,int data)
{
    Circular_list*p=new Circular_list(data);
    if(head==NULL)
    {
        p->next=p;
    }
    else{
    Circular_list*curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=p;
    p->next=head;
    }

    return p;
}

//function to insert at the head of an circular linked list(efficient)
Circular_list*insert_atB(Circular_list*head,int data)
{
    Circular_list*p=new Circular_list(data);
    if(head==NULL)
    {
        p->next=p;
        return p;
    }
    else
    {
        p->next=head->next;
        head->next=p;
        int temp=head->data;
        head->data=p->data;
        p->data=temp;
        return head;
    }

}

//function to insert at the end of an circular linked list(naive)
Circular_list* insert_atlast(Circular_list*head,int data)
{
    Circular_list*p=new Circular_list(data);
    if(head==NULL)
    {
        p->next=p;
        return p;
    }
    else
    {  Circular_list*curr=head;
        while(curr->next!=head)
        {
            curr=curr->next;
        }
        curr->next=p;
        p->next=head;
        return head;
   }
}

//function to insert at the end of an circular linked list(effective)
Circular_list*insertat_last(Circular_list*head,int data)
{
    Circular_list*p=new Circular_list(data);
    if(head==NULL)
    {
        p->next=p;
        return p;
    }
    else
    {
        p->next=head->next;
        head->next=p;
        int temp=head->data;
        head->data=p->data;
        p->data=temp;
       return p;
    }

}

//function to delete the head of an circular linked list
Circular_list * delete_head(Circular_list*head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    Circular_list*curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=head->next;
    delete head;
    return curr->next;
}

//function to delete the head of a circular linked list(effective)
Circular_list* delete_headeff(Circular_list*head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Circular_list*temp=head->next;
    head->next=temp->next;
    delete temp;
    return head;
}

//function to delete a node at kth position assuming we get k i bound 1<=k<=number of nodes
Circular_list*delete_kth(Circular_list*head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(k==1)
    {
    head->data=head->next->data;
    Circular_list*temp=head->next;
    head->next=temp->next;
    delete temp;
    return head;
    }
    Circular_list*curr=head;
    for(int i=1;i<=k-2;i++)
    {
        curr=curr->next;
    }
    Circular_list *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}

// implementing  circular doubly linked list
struct CircleDouble_list{
int data;
CircleDouble_list*next;
CircleDouble_list*prev;

 CircleDouble_list(int x)
 {
     data=x;
     next=NULL;
     prev=NULL;
 }
};

//function to insert an element at begin in circular doubly linked list
CircleDouble_list* insertat_begin(CircleDouble_list*head,int data)
{
    CircleDouble_list*p=new CircleDouble_list(data);
    if(head==NULL)
    {
        p->next=p;
        p->prev=p;
        return p;
    }
    else
    { p->next=head;
      p->prev=head->prev;
      head->prev->next=p;
      head->prev=p;
      return p;  //return head of you want to insert the end
    }
}

//function to traverse circular doubly linked list
void traverse(CircleDouble_list*head)
{
    if(head==NULL)
    {
        return;
    }
    CircleDouble_list*curr=head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head);
}

//function to insert elements in a linked list in a sorted way
node * insertSorted(node*head,int data)
{
    node * p=new node(data);
    if(head==NULL)
    {
        return p;
    }
    node * curr=head;
    node*temp=head;
   while(curr!=NULL)
   {
       if(curr->data>data)
       {
           break;
       }
       temp=curr;
       curr=curr->next;
   }
   if(temp==head)
   {
       p->next=head;
       return p;
   }
   else
   {
       p->next=temp->next;
       temp->next=p;
       return head;

   }


}

//function to insert element in sorted order in a linked list(sir's more cleaner way)
node* insert_sorted(node *head,int data)
{
    node*p=new node(data);
    if(head==NULL)
    {
      return p;
    }
    if(data<head->data)
    {
        p->next=head;
        return p;
    }
    node*curr=head;
    while(curr->next!=NULL &&curr->next->data<data)
    {
        curr=curr->next;
    }
    p->next=curr->next;
    curr->next=p;
    return head;

}

//function to find  middle of a linked list(naive)
int find_middle(node*head)
{
    int pos=0;
    node*curr=head;
    while(curr!=NULL)
    {
        pos++;
        curr=curr->next;
    }
    pos=(floor(pos/2))+1;
    while(pos!=1)
    {
        head=head->next;
        pos--;
    }
    return head->data;
}

//function to find middle of a linked list(effective)
int find_mid(node*head)
{
    int counter=0;
    int mid=0;
    if(head==NULL)
    {
        return -1;
    }
    if(head->next==NULL)
    {
        return head->data;
    }
    head=head->next;
    node *m =head;
    while(head!=NULL)
    {
        if((counter & 1)==0)
        {
            mid=m->data;
            m=m->next;
        }
        counter++;
        head=head->next;
    }
    return mid;

}
//function to find the middle point in a linked list(effective)
int find_mid1(node*head)
{
    if(head==NULL)
    {
        return -1;
    }
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

//function to find nth node from the end
int find_nth(node* head,int pos)
{
    if(head==NULL)
    {
        return -1;
    }
   if(head->next==NULL && pos==1)
   {
       return head->data;
   }
   node*curr=head;
   while(pos!=1 && curr->next!=NULL)
   {
       curr=curr->next;
       pos--;
   }
   while(curr->next!=NULL)
   {
       head=head->next;
       curr=curr->next;
   }
   return head->data;
}

//function to find the nth node from the last
int find_nth1(node*head,int pos)
{
    if(head==NULL)
    {
        return -1;
    }
    node*curr=head;
    while(pos!=0&&curr!=NULL)
    {
        curr=curr->next;
        pos--;
    }
    if(pos!=0)
    {
        return -1;
    }
    while(curr!=NULL)
    {
        head=head->next;
        curr=curr->next;
    }
    return head->data;


}

//function to reverse a linked list
node * reverse_linked(node*head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node*head2=NULL;
    while(head!=NULL)
    {  node*p=new node(head->data);
        if(head2==NULL)
        {
            head2=p;

        }
        else
        {
            p->next=head2;
            head2=p;
        }
        node *f=head;
        head=head->next;
        delete f;
    }
    return head2;
}

//function to reverse a linked list
node* reverse_list(node *head)
{
    node*curr=head;
    node * prev=NULL;
    while(head!=NULL)
    {
        curr=head;
        head=head->next;
        curr->next=prev;
        prev=curr;
    }
    return curr;
}
//function to reverse a linked list
node *rl(node*head)
{
    node*curr=head;
    node*prev=NULL;
    while(curr!=NULL)
    {
        node*next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

//reverse of on linked list using recuurion
node* rec_reverse(node*head,node*head2)
{
    if(head==NULL)
    {
        return head2;
    }

    head2=insert_begin(head2,head->data);
    return rec_reverse(head->next,head2);
}

//function to reverse a linked list
node* rece_reverse2(node*head)
{
   if(head==NULL|| head->next==NULL)
   {
       return head;
   }
    node *last=rece_reverse2(head->next);
    node *temp=head->next;
    temp->next=head;
    head->next=NULL;
    return last;
}

node* reverse_rec(node*head,node*prev)
{
    if(head==NULL)
    {
        return prev;
    }

    node*next=head->next;
    head->next=prev;

    return reverse_rec(next,head);
}

//function to delete duplicates in a sorted linked list(causes memory fragmentation)
node* delete_duplicates(node*head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    node*temp=head;
    node*curr=head->next;
    while(curr!=NULL)
    {
        if(temp->data!=curr->data)
        {
            temp->next=curr;
            temp=curr;
        }
        curr=curr->next;
    }
    return head;
}

//function to delete duplicates in an linked list
void delete_dup(node*head)
{
    node*curr=head;
    while(curr!=NULL && curr->next!=NULL)
    {
        if(curr->next->data==curr->data)
        {
            node*temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);
        }
        else
        {
            curr=curr->next;
        }
    }
}

//function to reverse a linked list after kth iterations(recursion method)
node* reverse_k(node*head,int k)
{
   node*curr=head;
   node*next=NULL;
   node*prev=NULL;
   int counter=0;
   while(curr!=NULL && counter<k)
   {
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
       counter++;
   }
   if(curr!=NULL){
   node *head2=reverse_k(curr,k);
   head->next=head2;
   }
   return prev;
}

//function to reverse a linked list after Kth iterations(iterative method)
node* reversek(node*head,int k)
{
  node*curr=head;
  node*prevfirst=NULL;
  bool isfirstpass=true;
  while(curr!=NULL)
  {  int counter=0;
     node*first=curr;
     node*prev=NULL;
     node*next=NULL;

      while(curr!=NULL &&counter<k)
      {
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
          counter++;
      }
      if(isfirstpass)
      {
          head=prev;
          isfirstpass=false;
      }
      else
      {
          prevfirst->next=prev;
      }
      prevfirst=first;

  }
  return head;
}

//function to find loop in a linked list
bool find_loop(node*head)
{
    node*temp=new node(0);
    node*curr=head;
    node*next=NULL;
    while(curr!=NULL)
    {
        if(curr->next==temp)
        {
            return true;
        }
        next=curr->next;
        curr->next=temp;
        curr=next;
    }
    return false;
}

//function to find loop in a linked list
bool findloop(node*head)
{
    node*curr=head;
    unordered_set<node*>s;
    while(curr!=NULL)
    {
        if(s.find(curr)!=s.end())
        {
            return true;
        }
        else
        {
            s.insert(curr);
            curr=curr->next;
        }
    }
    return false;
}

//function to find loop in a linked list
bool findloop1(node*head)
{
    node*slow=head;
    node*fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
         if(slow==fast)
        {
            return true;
        }
    }


        return false;

}

//function to delete loops in a linked list
node* deleteloop(node*head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==head)
    {
        head->next=NULL;
        return head;
    }
    unordered_set<node*>s;
    node*curr=head;
    node*prev=NULL;
    while(curr!=NULL)
    {
        if(s.find(curr)!=s.end())
        {
            prev->next=NULL;
            return head;
        }
        prev=curr;
        s.insert(curr);
        curr=curr->next;
    }
    return head;



}

//function to delete the loop in the linked list
node* deleteloop1(node*head)
{
     if(head==NULL)
    {
        return NULL;
    }
    if(head->next==head)
    {
        head->next=NULL;
        return head;
    }
    node*slow=head;
    node*fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            break;
    }
    if(fast!=slow)
    {
        return head;
    }
    slow=head;
    while(fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    fast->next=NULL;
    return head;

}

//function to delete a node of an singley linked list with pointer given only to the node that is to be deleted
void deletenode(node*point)
{
    if(point==NULL)
    {
        return;
    }
    node*temp=point->next;
    point->data=temp->data;
    point->next=temp->next;
    delete temp;
}

//function to sort linked list in form of even and odd
node* even_odd(node*head)
{
    if(head==NULL)
    {
        return NULL;
    }

    node*even_start=NULL;
    node*even_end=NULL;
    node*odd_start=NULL;
    node*odd_end=NULL;
    node*curr=head;
    while(curr!=NULL)
    {
        if((curr->data&1)==0)
        {
            if(even_start==NULL)
            {
                even_start=curr;
                even_end=curr;
            }
            else
            {
                even_end->next=curr;
                even_end=curr;
            }
        }
        else
        {
            if(odd_start==NULL)
            {
                odd_start=curr;
                odd_end=curr;
            }
            else
            {
                odd_end->next=curr;
                odd_end=curr;
            }
        }

        curr=curr->next;
    }
    if(even_end==NULL || odd_start==NULL)
    {
        return head;
    }
    else
    {
        even_end->next=odd_start;
        return even_start;
    }

}

//function to find the intersection of an linked list
node* find_intersection(node*head1,node*head2)
{
    node*curr=head1;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=head2;
    node *fast=head1;
    node*slow=head1;
    while(fast->next!=NULL&&fast!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            break;
        }
    }
    slow=head1;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    curr->next=NULL;
    return fast;

}

//function to find the intersection of two linked list
node* find_intersection1(node*head1,node*head2)
{
    unordered_set<node*>hashtable;
    node*curr=head1;
    while(curr!=NULL)
    {
        hashtable.insert(curr);
        curr=curr->next;
    }

    node*curr2=head2;
    while(curr2!=NULL)
    {
        if(hashtable.find(curr2)!=hashtable.end())
        {
            return curr2;
        }
        curr2=curr2->next;
    }
    return NULL;

}

//function to find intersection of the linked lists(effective)
node* find_inter_effective(node*head1,node*head2)
{
    node*curr1=head1;
    node*curr2=head2;
    int count1=0;
    int count2=0;
    while(curr1!=NULL)
    {
        count1++;
        curr1=curr1->next;
    }
    while(curr2!=NULL)
    {
        count2++;
        curr2=curr2->next;
    }
    int diff=abs(count1-count2);
    curr1=head1;
    curr2=head2;
   if(count1>count2)
   {
       for(int i=0;i<diff;i++)
       {
           curr1=curr1->next;
       }
   }
   else
   {

       for(int i=0;i<diff;i++)
       {
           curr2=curr2->next;
       }
   }
   while(curr1!=NULL)
   {
       if(curr1==curr2)
       {
           return curr1;
       }
       curr1=curr1->next;
       curr2=curr2->next;
   }
return NULL;
}

//function to swap in pairs in a linked list
node* swap_pairs(node*head)
{
    node*curr=head;
    while(curr->next!=NULL && curr!=NULL)
    {
        swap(curr->data,curr->next->data);
        curr=curr->next->next;
    }
    return head;
}

//function to  swap pairs in a linked list
node* swap_pairs1(node*head)
{
    node*curr=head->next->next;
    node*prev=head;
    head=head->next;
    head->next=prev;
    while(curr->next!=NULL && curr!=NULL)
    {
        node*temp=curr->next->next;
        prev->next=curr->next;
        curr->next->next=curr;
        prev=curr;
        curr=temp;
    }
    prev->next=curr;
    return head;
}

struct random_node{
int data;
random_node*next;
random_node*random;

random_node(int x)
{
    data=x;
    next=NULL;
    random=NULL;
}

};

//function to print random_node
void print_clone(random_node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
//function to make a clone of an linked list having an extra pointer random that points to any node in linked list
random_node* clone(random_node*head)
{
    random_node*curr=head;
    unordered_map<random_node*,random_node*>h;
    random_node*head2=NULL;
    random_node*tail=NULL;
    while(curr!=NULL)
    {
        random_node*temp=new random_node(curr->data);
        if(head2==NULL)
        {
            head2=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        h[curr]=temp;
        curr=curr->next;
    }
    random_node*curr1=head2;
    curr=head;
    while(curr1!=NULL)
    {
        auto loc=h.find(curr->random);
        if(loc!=h.end())
        {
            curr1->random=loc->second;

        }
        curr1=curr1->next;
        curr=curr->next;

    }

return head2;
}

//function to make a copy of an linked list(effective method)
random_node* clone2(random_node*head)
{
    //adding new nodes in the linked list
    random_node*curr=head;
    while(curr!=NULL)
    {
       random_node*next=curr->next;
       curr->next=new random_node(curr->data);
       curr->next->next=next;
       curr=next;
    }

    curr=head->next;
    random_node*prev=head->random->next;
    while(curr!=NULL)
    {
        curr->random=prev;

        if(curr->next!=NULL)
        {
        prev=curr->next->random->next;
        random_node*next=curr->next->next;
        curr->next=next;
        curr=next;
        }
        else
        {
          curr=curr->next;
        }


    }
return head->next;;


}

//function to merge two sorted linked list
node* merge_list(node*head1,node*head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    node* curr1=head1;
    node*curr2=head2;
    node*head=NULL;
    node*tail=NULL;

    if(curr1->data<=curr2->data)
            {
                head=curr1;
                curr1=curr1->next;
                tail=head;
            }
    else
            {
                head=curr2;
                curr2=curr2->next;
                tail=head;

            }

    while(curr1!=NULL && curr2!=NULL)
    {

            if((curr1->data)<=(curr2->data))
            {
                tail->next=curr1;
                tail=curr1;
                curr1=curr1->next;
            }
            else
            {
                tail->next=curr2;
                tail=curr2;
                curr2=curr2->next;
            }
    }
    if(curr1!=NULL)
    {
        tail->next=curr1;
    }
    else{
        tail->next=curr2;
    }
    return head;
}

struct char_node{

 char data;
 char_node*next;

 char_node(int x)
 {
     data=x;
     next=NULL;
 }


};

char_node* insertbegin(char_node*head,int data)
{
    if(head==NULL)
    {
        return new char_node(data);
    }
    char_node*p=new char_node(data);
    p->next=head;
    return p;
}

void print_char(char_node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}


//function to check if a linked list is palindrome or not
bool palindrome(char_node*head)
{
    char_node*curr=head;
    char_node*head2=NULL;
    while(curr!=NULL)
    {
        head2=insertbegin(head2,curr->data);
        curr=curr->next;
    }
    char_node*curr2=head2;
    curr=head;
    while(curr!=NULL)
    {
        if(curr->data != curr2->data)
        {
            return false;
        }
        curr=curr->next;
        curr2=curr2->next;
    }

    return true;
}

//function to find the middel of a linked list
char_node* middel(char_node*head)
{
    char_node*fast=head;
    char_node*slow=head;
    while(fast->next!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}

//function to find the palindrome in a list
bool palindrome1(char_node*head)
{
    if(head==NULL)
    {
        return false;
    }
    if(head->next==NULL)
    {
        return true;
    }
    char_node*head1;
     head1=middel(head);

     char_node*curr=head1->next;
     head1->next=NULL;
     char_node*next=NULL;
     char_node*prev=NULL;
     while(curr!=NULL)
     {
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
     }
     head1=prev;

     while(head1!=NULL)
     {
         if(head1->data != head->data)
         {
             return false;
         }
         head1=head1->next;
         head=head->next;
     }

  return true;
}


int main()
{
    /*node *head= new node(10);
    node *temp1= new node(20);
    node *temp2= new node(30);
    head->next=temp1;
    temp1->next=temp2;
    print_list(head);
     head=insert_end(head,40);
     cout<<endl;
     print_list(head);
     head=deleteFirst(head);
     cout<<endl;
     print_list(head);
     head=deleteLast(head);
     head=insert_end(head,44);
     head=insert_end(head,48);
     cout<<endl;
     print_list(head);
     head=Insert_atPos(head,55,2);
     cout<<endl;
     print_list(head);
     cout<<search_key_rec(head,9);*/

     /*Doublenode * head=new Doublenode(10);
     Doublenode *temp1=new Doublenode(20);
     Doublenode *temp2=new Doublenode(30);
     head->next=temp1;
     temp1->prev=head;
     temp1->next=temp2;
     temp2->prev=temp1;
     head=insert_at_begin(head,17);
     head=insert_atend(head,19);
     printlist(head);
     head=reversedll(head);
     cout<<endl;
     printlist(head);
     head=delete_Last(head);
     cout<<endl;
     printlist(head);*/

     /*Circular_list *head=new Circular_list(10);
     Circular_list *temp1=new Circular_list(20);
     Circular_list *temp2=new Circular_list(30);
     Circular_list *temp3=new Circular_list(40);
     head->next=temp1;
     temp1->next=temp2;
     temp2->next=temp3;
     temp3->next=head;
     printCirclels(head);
     head=insert_atB(head,23);
     printCirclels(head);
     head=insert_atlast(head,88);
     printCirclels(head);
     head=insertat_last(head,90);
     printCirclels(head);
     head=delete_headeff(head);
     head=delete_headeff(head);
     printCirclels(head);
     head=delete_kth(head,2);
     printCirclels(head);*/

     /*CircleDouble_list*head=NULL;
     head=insertat_begin(head,10);
     head=insertat_begin(head,20);
     head=insertat_begin(head,30);
     head=insertat_begin(head,40);
     traverse(head);*/


     /*node*head=NULL;
     head=insert_sorted(head,1);
     head=insert_sorted(head,2);
     head=insert_sorted(head,13);
     head=insert_sorted(head,5);
     head=insert_sorted(head,1);
     head=insert_sorted(head,11);
     head=insert_sorted(head,2);
     head=insert_sorted(head,111);
     head=insert_sorted(head,4);
     head=insert_sorted(head,19);
     head=insert_sorted(head,4);
     head=insert_sorted(head,4);
     head=insert_sorted(head,23);
     head=insert_sorted(head,2);


     print_list(head);
     cout<<find_middle(head);
     cout<<endl;
     cout<<find_nth1(head,7);
    // head=reverse_rec(head,NULL);
     head=reversek(head,3);
     cout<<endl;
     print_list(head);
     node*tail=head;
     while(tail->next!=NULL)
     {
         tail=tail->next;
     }
     tail->next=head->next->next->next;
     cout<<findloop1(head);
     head=deleteloop1(head);

     cout<<findloop(head);
     cout<<endl;
     print_list(head);
     deletenode(head->next->next->next);
     cout<<endl;
     print_list(head);
     cout<<endl;
     node *head2=new node(13);
     head2->next=new node(99);
     head2->next->next=head->next->next->next->next->next;
     node*temp=find_inter_effective(head,head2);
     cout<<temp->data;
     head=swap_pairs1(head);
      print_list(head);*/


     /*random_node*head= new random_node(10);
     random_node*temp1=new random_node(20);
     random_node*temp2=new random_node(30);
     random_node*temp3=new random_node(50);
     head->next=temp1;
     head->random=temp3;
     temp1->next=temp2;
     temp1->random=head;
     temp2->next=temp3;
     temp2->random=temp1;
     temp3->random=temp1;
     cout<<endl;
     head=clone2(head);
     print_clone(head);
      cout<<head->random->data;*/

      /*bool choice=true;
      char ans;
      int activity;
      Doublenode*head=NULL;
      Doublenode*tail=NULL;
      int counter=0;
      unordered_map<int,Doublenode*>hashtable;
      while(choice){

            cout<<"Enter the activity=";
            cin>>activity;

           auto loc=hashtable.find(activity);
           if(loc==hashtable.end())
          {if(head==NULL)
            {
                head=first_node(activity);
                tail=head;
                hashtable[activity]=head;
                counter++;
            }
            else if(counter<4)
            {
                tail->next=new Doublenode(activity);
                tail->next->prev=tail;
                tail=tail->next;
            }
            else
            {
                tail->prev->next=NULL;
                Doublenode*temp=tail->prev;
                delete tail;
                tail=temp;
                Doublenode*p=new Doublenode(activity);
                p->next=head;
                head->prev=p;
                head=p;
            }

          }
          else
          {
              Doublenode*pos=loc;

          }











        cout<<"DO you wanna continue?(Y/N)";
        cin>>ans;
        if(ans=='N'|| ans=='n')
        {
            choice=false;
        }
      }*/



   /*node*head=new node(20);
   head->next=new node(50);
   head->next->next=new node(60);
   head->next->next->next=new node(80);
   node *head2=new node(10);
   head2->next=new node(30);
   head2->next->next=new node(70);
   head2->next->next->next=new node(90);

   node *head3=merge_list(head,head2);
   print_list(head3);*/




      char_node *head=NULL;
      head=insertbegin(head,'e');
      head=insertbegin(head,'k');
      head=insertbegin(head,'a');
      head=insertbegin(head,'n');
      head=insertbegin(head,'a');
      head=insertbegin(head,'k');
      cout<<palindrome1(head);














    return 0;
}
