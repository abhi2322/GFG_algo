#include <iostream>
#include<algorithm>
#include<vector>
#include<random>

using namespace std;

//structure and function to implement my own object and order
struct point
{
    int x,y;
};

bool mycmp(point p1,point p2)
{
    return p1.x<p2.x;
}

//implementing bubble sort
void bubblesort(int arr[],int n)
{
    int i=0;
    int flag=0;
    while(i<n-1)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        cout<<"pit";
        if(flag==0)
        {
            break;
        }

        i++;
    }
}

//implementing selection sort
void selectionsort(int arr[],int n)
{    int i=0;
     int m=0;
    while(i<n-1)
    { m=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[m]>arr[j])
            {
                m=j;
            }
        }
        swap(arr[i],arr[m]);
        i++;
    }
}
//implementing insertion sort
void insertionsort(int arr[],int n)
{ int j=1;
int i=0;
    while(j<n)
    {
       int m=arr[j];
      for( i=j-1;i>=0;i--)
      {
          if(arr[i]>m)
             arr[i+1]=arr[i];
          else
            break;

      }
      arr[i+1]=m;
      j++;
    }
}
//function to merge and sort two sorted array
void Merge(int arr1[],int arr2[],int n,int m)
{ int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++;
        }
        else
        {
            cout<<arr2[j]<<" ";
            j++;
        }
    }
    while(i<n)
    {
        cout<<arr1[i]<<" ";
        i++;
    }
    while(j<m)
    {
        cout<<arr2[j]<<" ";
        j++;
    }
}
//merge function within a single array(naive inefficient solution 0(n2))
void Merge1(int arr[],int low,int mid,int high)
{ int j=mid+1;
   int i;
   while(j<=high)
    {
    int key=arr[mid+1];
    for( i=mid;i>=low;i--)
    {
        if(arr[i]>key)
            arr[i+1]=arr[i];
            else
                break;
    }
     arr[i+1]=key;
     j++;
     mid++;
     }

}
//merge function within a single array(effective method)
void Merge2(int arr[],int low,int mid,int high)
{  int n1,n2;
  n1=mid-low+1;
  n2=high-mid;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++)
    {
        left[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=low;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=right[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}
//function to implement merge sort
void mergesort(int arr[],int l,int r)
{
    if(r>l)
    { int m=l+(r-l)/2;
     mergesort(arr,l,m);
     mergesort(arr,m+1,r);
     Merge2(arr,l,m,r);//function used from above
    }
}

//function to find same elements in two array
void intersecton(int arr1[],int arr2[],int n,int m)
{
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(i>0 && arr1[i]==arr1[i-1])
        {i++; continue;}
      if(arr1[i]==arr2[j])
           {cout<<arr1[i]<<" ";
               i++;
               j++;
            }
      else if(arr1[i]>arr2[j])
            j++;
      else
            i++;
    }

}

//function to find union of two sorted array which is also sorted
void Union(int arr1[],int arr2[],int n,int m)
{
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(i>0 && arr1[i]==arr1[i-1])
        {i++;
        continue;
        }
         if(j>0 && arr2[j]==arr2[j-1])
        {
            j++;
            continue;
        }
     if(arr1[i]==arr2[j])
           {cout<<arr1[i]<<" ";
               i++;
               j++;
            }
      else if(arr1[i]>arr2[j])
            {  cout<<arr2[j]<<" ";
                j++;

            }
      else
      { cout<<arr1[i]<<" ";
          i++;
      }

    }
     while(i<n)
    {   if(i>0 && arr1[i]==arr1[i-1])
        {i++;
        continue;}
        cout<<arr1[i]<<" ";
        i++;
    }
    while(j<m)
    {  if(i>0 && arr2[j]==arr2[j-1])
    {
        j++;
        continue;
    }
        cout<<arr2[j]<<" ";
        j++;
    }

}

//function to implement naive partition
void naive(int arr[],int n,int p)
{
    int temp[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=arr[p])
        {
            temp[j]=arr[i];
            j++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[p])
        {
            temp[j]=arr[i];
            j++;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
}

//function to implement lomuto partitioning
void lomuto(int arr[],int l,int h,int p)
{
    swap(arr[h-1],arr[p]);
    p=h-1;
    int i=l-1;
    int j=0;
    for(j=0;j<h-1;j++)
    {
        if(arr[j]<=arr[p])
        {
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[h-1]);

}

//function to implement hoares's partitioning
int hoare(int arr[],int l,int h,int p)
{ int pivot=arr[p];
int i=l-1;
int j=h+1;
    while(true)
    {
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);

    }
}

//quick sort using lomuto partition
int Lomuto(int arr[],int l,int h)
{
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
void qsort1(int arr[],int l,int h)
{
    if(l<h)
    {


        int p=Lomuto(arr,l,h);
        qsort1(arr,l,p-1);
        qsort1(arr,p+1,h);
    }

}

//function to implement quick sort using hoare's partition
int Hoare(int arr[],int l,int h)
{
    int pivot=arr[l];
    int i=l-1;
    int j=h+1;
    while(true)
    {
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)
            return j;
      swap(arr[i],arr[j]);
    }
}
void qsort2(int arr[],int l,int h)
{
   if(l<h)
   {
       int p=Hoare(arr,l,h);
       qsort2(arr,l,p);
       qsort2(arr,p+1,h);
   }
}

//Most optimized solution for quicksort just for fun show only the above sort
int Hoare1(int arr[],int l,int h)
{
    int pivot=arr[l];
    int i=l-1;
    int j=h+1;
    while(true)
    {
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)
            return j;
      swap(arr[i],arr[j]);
    }
}

int random(int range_from, int range_to) {
    std::random_device                  rand_dev;                   //difficult method to calculate a random number
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>    distr(range_from, range_to);
    return distr(generator);
}
void qsort3(int arr[],int l,int h)
{ Begin:
   if(l<h)
   {  int pivot=random(l,h);
       swap(arr[pivot],arr[l]);
       int p=Hoare1(arr,l,h);
       if((p-l)+1 < h-p)
       {
           qsort3(arr,l,p);
           l=p+1;
           goto Begin;
       }
       else
       {
           qsort3(arr,p+1,h);
           h=p;
           goto Begin;
       }



   }
}

//function to find the kth smallest element in an unsorted array(quick select)
void kthsml(int arr[],int l,int h,int k)
{
    while(l<=h)
    {
        int p=Lomuto(arr,l,h);
        if(p==k-1)
        {
            cout<<arr[p]<<endl;
            break;
        }else if(k-1 <p)
        {
            h=p-1;
        }
        else
        {
            l=p+1;
        }
    }
}
//function to solve chocolate distribution problem
void chocolatedis(int arr[],int n,int m)
{
    sort(arr,arr+n);
    int res=arr[m-1]-arr[0];
    for(int i=1;i+m-1<n;i++)
    {
        res=min(res,arr[i+m-1]-arr[i]);
    }
    cout<<res<<endl;
}
//function that moves all the negative first and the positive
void negpos(int arr[],int l,int h)
{
    int i=l-1;
    int j=h+1;
    while(true)
    {
        do{
            i++;
        }while(arr[i]<0);
        do{
           j--;
        }while(arr[j]>=0);
        if(i>=j)
        return;
        swap(arr[i],arr[j]);
    }
}

//function to move all even first then all odd numbers
void oddeven(int arr[],int n)
{
    int i=-1;
    int j=n;
    while(true)
    {
        do{
            i++;
        }while(arr[i]%2==0);
        do{
            j--;
        }while(arr[j]%2!=0);
        if(i>=j)
            return;
        swap(arr[i],arr[j]);
    }
}
//hacker rank question for practise
int getTotalX(int a[],int b[],int n,int m)
{
int low=a[n-1];
int high=b[0];
int counter=0;
while(low<high)
{ int flag=0;
    for(int i=0;i<n;i++)
    {
        if(low%a[i]!=0)
        {flag=1;
         break;
        }
    }
    if(flag==1)
    {  low++;
        continue;}
    else{
    for(int i=0;i<m;i++)
    {
        if(b[i]%low!=0)
        {
            flag=1;
            break;
        }
    }
    }
    if(flag==1)
{   low++;
    continue;}
    else
    {
        counter++;
        low++;
    }
}
return counter;
}

//function to sort according three numbers
void sort3(int arr[],int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
                {
                 mid++;
                }
         else{
            swap(arr[mid],arr[high]);
            high--;
         }
         cout<<low<<":"<<mid<<":"<<high<<endl;

}
}

//function to partition the array where pivot have multiple occurences and we want all pivot in the middel
void sort3pivot(int arr[],int n,int p)
{   int pivot=arr[p];
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]<pivot)
        {
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==pivot)
        {
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
//function to partition around a range
void sortrange(int arr[],int n,int s,int e)
{
    int start=arr[s];
    int endd=arr[e];
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]<start)
        {
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]>=start && arr[mid]<=endd)
        {
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

//function to merge overlapping intervals

bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
 return v1[0] < v2[0];
}
int mergeintervals(vector<vector<int>> &arr)
{ int n=arr.size();
 int res=0;
    sort(arr.begin(),arr.end(),sortcol);
    for(int i=1;i<n;i++)
    {
        if(arr[res][1]>=arr[i][0])
        {
            int max_end=max(arr[i][1],arr[res][1]);

            arr[res][1]=max_end;
        }
        else
        {
            res++;
            arr[res]=arr[i];
        }
    }
 return res;
}
//function to implement above code using a structure
struct range{
int start;
int last;
};
bool mycmp1(range r1,range r2)
{
    return r1.start<r2.start;
}
int mergerange(struct range r[],int n)
{
    sort(r,r+n,mycmp1);
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(r[res].last>=r[i].start)
        {
        r[res].last=max(r[res].last,r[i].last);
        }
        else
        {
            res++;
            r[res]=r[i];
        }
    }
return res;
}
//function to find the maximum guests at a given interval
int maxguests(int arr1[],int arr2[],int n)
{ int i=1;
  int j=0;
  sort(arr1,arr1+n);
  sort(arr2,arr2+n);
  int res=1;
  int max_res=1;
    while(i<n && j<n)
    {
        if(arr1[i]<arr2[j])
        {

            res++;
            i++;
        }
        else
        {
            res--;
            j++;
        }
        max_res=max(max_res,res);
    }
    return max_res;
}
//implement cycle sort
void sort_unique(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    { int item=arr[i];
        int pos=i;

         for(int j=i+1;j<n;j++)
             if(arr[j]<item)
                 pos++;
         swap(arr[pos],item);
         while(pos!=i)
         {  pos=i;
             for(int j=i+1;j<n;j++)
                 if(arr[j]<item)
                    pos++;
             swap(arr[pos],item);
         }
    }
}
//function to implement cycle sort with repeated numbers
void cyclesort(int arr[],int n)
{
    for(int cs=0;cs<n-1;cs++)
    {
        int pos=cs;
        int item=arr[cs];
        for(int iter=cs+1;iter<n;iter++)
        {
            if(arr[iter]<=item)
                pos++;
        }
        swap(arr[pos],item);
        while(cs!=pos)
        {
            pos=cs;
            for(int iter=cs+1;iter<n;iter++)
            {
                if(arr[iter]<item)
                pos++;

            }
            swap(arr[pos],item);
        }
    }
}

//function to return least number of swaps to sort an array
int minswap(int arr[],int n)
{ int swaps=0;
    for(int cs=0;cs<n-1;cs++)
    {
        int pos=cs;
        int item=arr[cs];
        for(int i=cs+1;i<n;i++)
        {
                if(arr[i]<=item)
                {
                   pos++;
                }
        }
        swap(arr[pos],item);
        if(pos!=cs)
        {swaps++;}
        while(pos!=cs)
        {
            pos=cs;
            for(int i=cs+1;i<n;i++)
            {
                if(arr[i]<=item)
                {
                    pos++;
                }
            }
            swap(arr[pos],item);
           if(cs!=pos)
            {swaps++;}
        }
    }
    return swaps;
}//function to implement counting sort
void countsort(int arr1[],int n,int k)
{ int temp[k]={0};



        for(int i=0;i<n;i++)
        {
            temp[arr1[i]]++;
        }

    int j=0;
    for(int i=0;i<k;i++)
    {
        while(temp[i]!=0)
        {
            arr1[j]=i;
            j++;
            temp[i]=temp[i]-1;
        }
    }
}
//function to implement counting sort algorithm for general purpose that can be used in objects too
void countsort2(int arr[],int n,int k)
{
    int temp[k]={0};
    for(int i=0;i<n;i++)
    {
        temp[arr[i]]++;
    }
    for(int i=1;i<k;i++)
    {
        temp[i]=temp[i]+temp[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[temp[arr[i]]-1]=arr[i];
        temp[arr[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
//function to implement radix sort
void countingsort(int [],int,int);
void radixsort(int arr[],int n)
{ int max_elem=arr[0];
    for(int i=0;i<n;i++)
    {
        max_elem=max(arr[i],max_elem);
    }
    for(int exp=1;(max_elem/exp)>0;exp*=10)
    {
        countingsort(arr,n,exp);
    }
}
void countingsort(int arr[],int n,int exp)
{
    int counting[10]={0};
    for(int i=0;i<n;i++)
    {
        counting[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++)
    {
        counting[i]=counting[i]+counting[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[counting[(arr[i]/exp)%10]-1]=arr[i];
        counting[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }

}
//function to implement bucket sort
void bucketsort(int arr[],int n,int b)
{
    vector <int> bkt[b];
    int max_elem=arr[0];
    for(int i=1;i<n;i++)
    {
        max_elem=max(max_elem,arr[i]);
    }
    max_elem++;
    for(int i=0;i<n;i++)
    {
        int bi=(b*arr[i])/max_elem;
        bkt[bi].push_back(arr[i]);

    }
    for(int i=0;i<b;i++)
    {
        sort(bkt[i].begin(),bkt[i].end());
    }
    int index=0;
    for(int i=0;i<b;i++)
    {
        for(int j=0;j<(int)bkt[i].size();j++)
        {
            arr[index++]=bkt[i][j];

        }
    }


}
int main()
{ int arr[]={30,40,10,80,33,69,15};
 bucketsort(arr,7,4);
 for(int i=0;i<7;i++)
 {
     cout<<arr[i]<<" ";
 }


}


