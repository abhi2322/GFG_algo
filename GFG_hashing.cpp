#include <iostream>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;


//function to implement chaining in hashing
struct MyHash
{
    int bucket;
    list<int>*table;
    MyHash(int b)
    {
        bucket=b;
        table=new list<int>[b];
    }

void add(int key)
{
    int i=key%bucket;
    table[i].push_back(key);
}
void del(int key)
{
    int i=key%bucket;
    table[i].remove(key);
}
bool sear(int key)
{
    int i=key%bucket;
    for(auto x:table[i])
    {
        if(x==key)
            return true;
    }
    return false;
}



};

//implement open addressing linear probing
struct Ohash
{   int bucket;
    int *hashtable;
    int space;
    Ohash(int b)
    {
        bucket=b;
        space=0;
        hashtable=new int[bucket];
        for(int i=0;i<bucket;i++)
        {
            hashtable[i]=-1;
        }
    }

    int hashfunc(int key)
    {
        return key%bucket;
    }
    bool increase(int key)
    { if(space==bucket)
    {
        return false;
    }
        int i=hashfunc(key);
        while(hashtable[i]!=-1 && hashtable[i]!=-2 && hashtable[i]!=key)
            {
                i=(i+1)%bucket;
            }
            if(hashtable[i]==key)
            {
                return false;
            }
            else
            {
            hashtable[i]=key;
            space++;
            return true;
            }
    }

     bool findkey(int key)
    {   if(space==0)
        {
            return false;
        }

        int h=hashfunc(key);
        int i=h;
        while(hashtable[i]!=-1)
        {
            if(hashtable[i]==key)
            {
                return true;
            }

            i=(i+1)%bucket;
            if(i==h)
            {
                return false;
            }
        }
            return false;
    }

    bool decrease(int key)
    { if(space==0)
    {
        return false;
    }
        int h=hashfunc(key);
        int i=h;
        while(hashtable[i]!=-1)
        { if(hashtable[i]==key)
        {
            hashtable[i]=-2;
            return true;
        }

            i=(i+1)%bucket;
            if(i==h)
        {
            return false;
        }
        }
            return false;

   }
    void display()
    {
        for(int i=0;i<bucket;i++)
        {
            cout<<hashtable[i]<<" ";
        }
    }




} ;
//function to count distinct element in a array(naive method)
int distinct_arr(int arr[],int n)
{ int res=1;
    for(int i=1;i<n;i++)
    { bool flag=true;
        for(int j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
                {
                    flag=false;
                    break;
                }
        }
        if(flag==true)
        res++;
    }
    return res;
}

//function to count distinct elements in an array
int arr_distinct(int arr[],int n)
{
    unordered_set <int> s(arr,arr+n);
    return s.size();
}

//function to find the frequency of occurrences of elements in an array(naive)
void Frequence(int arr[],int n)
{
    for(int i=0;i<n;i++)
    { bool flag=false;
      int res=1;
        for(int j=0;j<i;j++)
        {
           if(arr[i]==arr[j])
           {
               flag=true;
               break;
           }
        }
           if(flag==true)
            {continue;}
           for(int k=i+1;k<n;k++)
           {
               if(arr[k]==arr[i])
                res++;
           }
           cout<<arr[i]<<":"<<res<<endl;
        }
    }

//function to find the frequency of occurrences of elements in an array
void frequency(int arr[],int n)
{
    unordered_map <int,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(auto x:m)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}

//function to find the intersection of two unsorted array having duplicates
int intersection(int arr1[],int arr2[],int n,int m)
{ int res=0;
    unordered_set<int> container(arr1,arr1+n);
    for(int i=0;i<n;i++)
    {
        if(container.find(arr2[i])!=container.end())
        {
            res++;
            container.erase(arr2[i]);
        }
    }
    return res;
}

//function to find a pair which is equal a given sum in an array
bool pairtwo(int arr[],int n,int sum)
{
    unordered_set <int> hashtable;
    for(int i=0;i<n;i++)
    {
        if(hashtable.find(sum-arr[i])!=hashtable.end())
        {
            return true;
        }
        hashtable.insert(arr[i]);

    }
    return false;
}

//function to check if there is a sub array with sum equal to zero
bool zerosum(int arr[],int n)
{ unordered_set <int> h;

  int sum=0;
    for(int i=0;i<n;i++)
    { sum+=arr[i];
        if(h.find(sum)!=h.end())
        {
            return true;
        }
        if(sum==0)
            return true;

        h.insert(sum);

    }
    return false;
}
//function to find the sub array with given sum
bool givensum(int arr[],int n,int given_sum)
{   unordered_set<int>h;
    int prefix_sum=0;
    for(int i=0;i<n;i++)
    {
        prefix_sum+=arr[i];
        if(h.find(prefix_sum-given_sum)!=h.end())
        {
            return true;
        }
        if(prefix_sum==given_sum)
            return true;
        h.insert(prefix_sum);
    }
    return false;
}

//function to find the longest sub array of given sum
int Lgivensum(int arr[],int n,int sum)
{
    unordered_map<int ,int> h;
    int res=0;
    int pre_sum=0;
    for(int i=0;i<n;i++)
    { pre_sum+=arr[i];
        if(pre_sum==sum)
        {
            res=i+1;
        }
        if(h.find(pre_sum)==h.end())
        {
           h.insert({pre_sum,i});
        }
        if(h.find(pre_sum-sum)!=h.end())
        {
            res=max(res,i-h[pre_sum-sum]);
        }
    }
    return res;
}
//function to find the maximum length of sub array having equal zeros and one
int zeroOne(int arr[],int n)
{
    unordered_map<int,int> h;
    int pre_sum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            pre_sum--;
        }
        else
        {
            pre_sum++;
        }
        if(pre_sum==0)
        {
            res=i+1;
        }
        if(h.find(pre_sum+n)==h.end())//No idea why we added in the pre_sum
        {
            h.insert({pre_sum+n,i});
        }
        else
        {
            res=max(res,i-h[pre_sum+n]);
        }
}
return res;
}

//function to find the longest common subsequence in an binary array
int LCS_Binary(int arr1[],int arr2[],int n)
{
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=arr1[i]-arr2[i];
    }
    unordered_map<int,int>h;
    int pre_sum=0;
    int res;
    for(int i=0;i<n;i++)
    { pre_sum+=arr[i];
        if(pre_sum==0)
        {
            res=i+1;
        }
        if(h.find(pre_sum)==h.end())
        {
            h.insert({pre_sum,i});
        }else
        {
            res=max(res,i-h[pre_sum]);
        }
    }
    return res;
}

//function to find the longest consecutive sequence in an array(naive way)
int LCS(int arr[],int n)
{ sort(arr,arr+n);
 int res=1;
 int max_res=1;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]-arr[i]==1)
        {
            res++;
        }
        else
        {
            max_res=max(res,max_res);
            res=1;
        }
    }
    max_res=max(max_res,res);
    return max_res;
}

//function to find the longest consecutive sequence in an array(effective method)
int LCS_E(int arr[],int n)
{
    unordered_set<int>h(arr,arr+n);

    int max_res=1;
    for(int i=0;i<n;i++)
    {
        if(h.find(arr[i]-1)==h.end())
        { int res=1;
        while(h.find(arr[i]+res)!=h.end())
        {
            res++;

        }
        max_res=max(res,max_res);
    }
    }
    return max_res;
}
//function to find the distinct elements in an array

void distinct_win(int arr[],int n,int k)
{
    for(int i=0;i<=n-k;i++)
    { int res=0;

        for(int j=0;j<k;j++)
        { bool flag=true;
            for(int b=0;b<j;b++)
            {
                if(arr[j+i]==arr[b+i])
                {  flag=false;
                    break;
                }
            }
            if(flag==true)
            {res++;}

        }
        cout<<res<<" ";
    }
}

//function to find distinct element in an given window(high space requirement)
int arr_distinct1(int arr[],int l,int h)
{
    unordered_set <int> s(arr+l,arr+h);
    return s.size();
}
void PRINTw(int arr[],int n,int k)
{
for(int i=0;i<=n-k;i=i+k)
{
    int res=arr_distinct1(arr,i,i+k);
    cout<<res<<" ";

}
}

//function to find the distinct elements in a given window of an array(effective way)
void Fre(int arr[],int n,int k)
{
    unordered_map<int,int>h;
    for(int i=0;i<k;i++)
    {
        h[arr[i]]++;
    }
    cout<<h.size()<<" ";
    for(int i=k;i<n;i++)
    {
        h[arr[i-k]]--;
        if(h[arr[i-k]]==0)
            h.erase(arr[i-k]);
        h[arr[i]]++;
        cout<<h.size()<<" ";

    }
}
//Question from geeks for geeksforgeek
int getsum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int getTarget(int sum1,int sum2)
{
    if((sum1-sum2)%2!=0)
    {
        return 0;
    }
    else
        return (sum1-sum2)/2;
}
void FindPair(int arr1[],int arr2[],int n,int m)
{
    int sum1=getsum(arr1,n);
    int sum2=getsum(arr2,m);

    unordered_set<int>h(arr1,arr1+n);
    int target=getTarget(sum1,sum2);
    for(int i=0;i<m;i++)
    {
    if(h.find(arr2[i]+target)!=h.end())
    {
        cout<<arr2[i]+target<<" "<<arr2[i];
        break;
    }
    }
}
//function to find the elements with n/k more occurrences
void occurrences(int arr[],int n,int k)
{
    unordered_map <int,int>h;
    for(int i=0;i<n;i++)
    {
        h[arr[i]]++;
    }
    for(auto x:h)
    {
        if(x.second>(n/k))
            cout<<x.first<<" ";
    }
}

//function to find the elements with more than n/k occurrences
void occurrences1(int arr[],int n,int k)
{ unordered_map <int,int>h;
  for(int i=0;i<n;i++)
  {
      if(h.find(arr[i])!=h.end())
      {
          h[arr[i]]++;
      }
      else if((int)h.size()<k-1)
        {
          h[arr[i]]=1;
        }

        else
          {
              for(auto x:h)
              {
                  x.second--;
                  if(x.second==0)
                  {
                      h.erase(x.first);
                  }
              }
          }

      }

for(auto y:h)
{
    int counter=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==y.first)
            counter++;
    }
    if(counter>(n/k))
        cout<<y.first<<" ";
}



}


int main()
{
    int arr1[]={30, 10, 20, 20, 20, 10, 40, 30, 30};
    int n=9;
    occurrences1(arr1,n,4);



  /*Ohash mh(7);
  cout<<mh.increase(10)<<endl;
  cout<<mh.increase(20)<<endl;
  cout<<mh.increase(15)<<endl;
  cout<<mh.increase(22)<<endl;
  cout<<mh.increase(29)<<endl;
  cout<<mh.increase(27)<<endl;
  cout<<mh.increase(42)<<endl;
  cout<<mh.increase(54)<<endl;
  mh.display();
  cout<<endl;
  cout<<mh.decrease(15)<<endl;
  mh.display();
  cout<<endl;
  cout<<mh.findkey(10);*/
}
