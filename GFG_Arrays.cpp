#include <iostream>

using namespace std;
int deleten(int arr[],int n,int item)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==item)
        {
            arr[i]=0;
            break;
        }
    }
    return n;
}
int LargestNumber(int arr[],int n)
{
 int index=0;
    for(int i=1;i<n;i++)
    {
        if(arr[index]<=arr[i])
        {index=i;
        }
    }
    return index;
}

int SecondLargest(int arr[],int n)
{
    int Largest=LargestNumber(arr,n);
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[Largest])
        {  if(index==-1)
            {
                index=i;
            }
            else if(arr[i]>arr[index])
            {
                index=i;
            }


        }
    }
    return index;
}

int SecondLargest2(int arr[],int n)
{ int index=0;
  int index2=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[index]<arr[i])
        {  index2=index;
            index=i;

        }
        else if(arr[i]!=arr[index])
        {

          if(index2==-1 || arr[index2]<arr[i])

            index2=i;
        }

    }
    return index2;
}

bool CheckSorted(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
     if(arr[i] > arr[i+1])
     return false;
    }
    return true;
}
int * ReverseArray(int arr[],int n)
{
    static int ReversedArray[5];
    for(int i=n-1;i>=0;i--)
    {
        ReversedArray[(n-1)-i]=arr[i];
    }
    return ReversedArray;
}
void ReverseArray_effective(int arr[],int n)
{int first,last;
    int low=0;
    int high=n-1;
    while(low<high)
    { int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;

      low++;
      high--;
    }
}
int DeleteDuplicates(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[j]==arr[i]&& i!=j)
            {
                n=deleten(arr,n,arr[j]);
            }
        }
    }
    return n;
}
int main()
{
    int arr[]={2,1,1,8,8};
    int n=5;


   n=DeleteDuplicates(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
    //for function returning an array
    /*int *r;
    r=ReverseArray(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<*(r+i);
    }

    return 0;*/
}
