#include <iostream>
#include<vector>
using namespace std;
const int R=4;
const int C=4;
//Function to print array in snake pattern
void snake(int arr[R][C])
{
    for(int i=0;i<R;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<C;j++)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        else
        {
            for(int j=C-1;j>=0;j--)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
}
//Function to print boundary of an matrix
void printboundry(int arr[R][C])
{  if(R==1)
     {
        for(int i=0;i<R;i++)
        {
            cout<<arr[0][i];
        }
     }
     else if(C==1)
     {
         for(int i=0;i<C;i++)
         {
             cout<<arr[i][0];




         }
     }
     else{
    for(int i=0;i<C;i++)
    {
        cout<<arr[0][i]<<",";
    }
    for(int i=1;i<R;i++)
    {
        cout<<arr[i][R-1]<<",";
    }
    for(int i=C-2;i>=0;i--)
    {
        cout<<arr[R-1][i]<<",";
    }
    for(int i=R-2;i>0;i--)
    {
        cout<<arr[i][0]<<",";
    }
}
}

//function to find transpose of an matrix
void transpose(int arr[R][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=i+1;j<C;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}
//Function to rotate an array 90 degrees
void nintyarray(int arr[R][C])
{ int mat[R][C];
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j--)
        {
           mat[R-j-1][i]=arr[i][j];
        }
    }
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;i++)
        {
            arr[i][j]=mat[i][j];
        }
    }
}
//Function to rotate an array in 90 degrees(effective way)
void nintyarray2(int arr[R][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=i+1;j<C;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
   for(int i=0;i<R;i++)
   {
       int low=0;
       int high=R-1;
       while(low<high)
       {
           swap(arr[low][i],arr[high][i]);
           low++;
           high--;
       }
   }
}

//function to find an element in sorted 2d array(effective method)
void searching(int arr[R][C])
{ int x=30;
    int r=0;
   int  c=C-1;
    while(r<R && c>=0)
    {
        if(arr[r][c]==x)
        { cout<<r<<":"<<c<<endl;
            return;
        }
        if(arr[r][c]<x)
        {
            r++;
        }
        else
        {
            c--;
        }

    }
    cout<<"NOT FOUND"<<endl;
}
int main()
{   /*
    int m=3,n=2;
    Creating 2D array simple method
      arr[m][n];
    Creating 2D array using double pointer
     int **arr;
    arr=new int *m;
    for(int i=0;i<m;i++)
    {
       arr[i]=new int[n];
    }
    Creating 2D array by creating array of pointers
    int *ar[m];
    for(int i=0;i<m;i++)
    {
     arr[i]=new int[n];
    }

    Creating 2D array using vector as dynamic only row
    vector<int>arra[m];
    for(int i=0;i<m;i++)
    {
        arra[i].push_back(10);
    }
    Creating 2D array using vector as dynamic both row and column
    vector<vector<int>>A;
    for(int i=0;i<m;i++)
    {  vector<int>v
        for(int j=0;j<n;j++)
        {
            v.pusb_back(10);
        }
        A.push_back(v);
    }

    */

     int arr[R][C]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};
     searching(arr);
     for(int i=0;i<R;i++)
     {
         for(int j=0;j<C;j++)
         {
             cout<<arr[i][j]<<",";
         }
     }


    return 0;
}
