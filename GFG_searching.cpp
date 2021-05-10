#include <iostream>
#include<vector>

using namespace std;
//searching using simple method
int simplesearch(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}
//searching using binary search method
int binaryseaarch(int arr[],int n,int x)
{
    int start=0;
    int last=n-1;
    int mid;
    while(start<=last)
    {
        mid=(start+last)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(x>arr[mid])
        {
            start=mid+1;
        }
        else
        {
            last=mid-1;
        }

    }
    return -1;
}

//binary search using recurssion
int BinarySearchRec(int arr[],int first,int last,int target)
{    if(first>last) return -1;

    int mid=(first+last)/2;
    if(arr[mid]==target)
    {
        return mid;
    }
    if(arr[mid]>target)
    return BinarySearchRec(arr,first,mid-1,target);
    else
    return BinarySearchRec(arr,mid+1,last,target);

}
//function to find first occurrence of an element in an array(recursion solution)
int BsFirst(int arr[],int first,int last,int target)
{
    int mid=(first+last)/2;

 if(first>last) return -1;

    if(arr[mid]>target)
    {
       return BsFirst(arr,first,mid-1,target);
    }
    else if(arr[mid]<target)
    {
      return  BsFirst(arr,mid+1,last,target);
    }
    else if(mid==0||arr[mid]!=arr[mid-1])
        {
            return mid;
        }
        else
        {
            return BsFirst(arr,first,mid-1,target);
        }
}
//function to find the index of first index(iterative solution)
int BsFirstI(int arr[],int first,int last,int target)
{ int mid;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(arr[mid]>target)
        {
            last=mid-1;
        }
        else if(arr[mid]<target)
        {
            first=mid+1;
        }
        else if(mid==0||arr[mid]!=arr[mid-1])
        {
            return mid;
        }
        else
        {
            last=mid-1;
        }
    }
    return -1;
}
//function to find the last occurrence of an element in an array
int BsLast(int arr[],int low,int high,int target,int n)
{ int mid;
   while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]>target)
        {
            high=mid-1;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else if(mid==n-1||arr[mid]!=arr[mid+1])
        {
            return mid;
        }
        else
        {
            low=mid+1;
        }
}
return -1;
}
//function to find number of occurrences in an array using above two questions
int BsOcc(int arr[],int low,int high,int target,int n)
{
    int first=BsFirstI(arr,low,high,target);
    if(first==-1)
    {
        return 0;
    }
    return BsLast(arr,low,high,target,n)-first+1;
}
//function to find number of ones in an binary array
int BsOnes(int arr[],int low,int high,int target,int n)
{  int mid;
while(low<=high){
 mid=(low+high)/2;
        if(arr[mid]==0)
        {
            low=mid+1;
        }

        else if(mid==0||arr[mid-1]==0)
        {
            return n-mid;
        }
        else
        {
            high=mid-1;
        }}
        return 0;
    }
//function to find sqrt of an number
int FindSqrt(int x)
{
    int low=1;
    int high=x;
    int mid;
    int mysqrt=0;
    int ans=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        mysqrt=mid*mid;
        if(mysqrt==x)
            return mid;
        if(mysqrt>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
            ans=mid;
        }
    }

    return ans;
}
//function to find an element in an array of infinite lenght
int FindPos(int arr[],int n,int x)
{  if(arr[0]==x)return 0;
 int low=-1;
 int i=1;
 int high=-1;
    while(arr[i]<x)
    {
    if(arr[i]==x)
        return i;
      i=i*2;
    }
    low=(i/2)+1;
    high=i-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==x) return mid;
        if(arr[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;

}
//function to find peak element in a unsorted array
int BsPeak(int arr[],int n)
{
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high)
    {
         mid=(low+high)/2;
         if((mid==0 || arr[mid-1]<arr[mid]) && (mid==n-1 || arr[mid+1]<arr[mid]))
         {
             return mid;
         }
         if(mid>0 && arr[mid-1]>=arr[mid])
         {
             high=mid-1;
         }
         else
         {
             low=mid+1;
         }

    }
    return -1;
}
//function to find pair of given sum in an sorted array(two pointer approach)
void TwoPointer(int arr[],int n,int x)
{
    int low=0;
    int high=n-1;
    while(low<high)
    {
        if(arr[low]+arr[high]==x)
        {
            break;
        }
        if(arr[low]+arr[high]>x)
        {
            high--;
        }
        else
        {
            low++;
        }

    }
    if(low==high)
    {
        cout<<"No such pair";
    }
    else {cout<<low<<endl;
    cout<<high;}

}
//function to find median of two sorted array(naive approach)
int Median(int arr1[],int arr2[],int n,int m)
{ int low=0;
int high=n-1;
   int i1;
   int i2;
    while(low<=high)
    {

        i1=(low+high)/2;
        i2=((n+m+1)/2)-i1;
        int min1=(i1==n)?INT_MAX:arr1[i1];
        int max1=(i1==0)?INT_MIN:arr1[i1-1];
        int min2=(i2==m)?INT_MAX:arr2[i2];
        int max2=(i2==0)?INT_MIN:arr2[i2-1];


       if(min2>=max1 && max2<=min1)
       {
           if((n+m)%2==0)
           {
               return (max(max1,max2)+min(min1,min2))/2;
           }
           else
           {
               return max(max1,max2);
           }
       }
       else if(min1>min2)
       {
           high=i1-1;
       }
       else
       {
           low=i1+1;
       }




    }
    return 0;
}
//function to find one repeated element in an array with some constraints(naive method)
int Repeated(int arr[],int n)
{   int v[n-1]={0};
    for(int i=0;i<n-1;i++)
    { int temp=arr[i];
        if(v[temp]==1)
        {
            return temp;
        }
        else
        {
           v[temp]=1;
        }
    }
    return 0;

}
//function to find one repeated element in an array with some constraints(effective method)
int Repeated2(int arr[],int n)
{
    int slow=arr[0]+1;
    int fast=arr[0]+1;
    do{
        slow=arr[slow]+1;
        fast=arr[arr[fast]+1]+1;
    }while(fast!=slow);
    slow=arr[0]+1;
    while(slow!=fast)
    {
        slow=arr[slow]+1;
        fast=arr[fast]+1;
    }

  return slow-1;//or fast
}
int main()
{
    int n;
    n=7;
    int arr[n]={0,4,1,2,3,3,3};
    cout<<Repeated2(arr,n);





}
