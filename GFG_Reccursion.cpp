#include <iostream>
#include <string>
using namespace std;
//introduction to  recursion printing an number line
int number(int n)
{
    if(n==0)
    {
        return 0;
    }

    cout<<n<<endl;
    return number(n-1);


}

//function to print binary representation
void Binary(int n)
{
    if(n==0)
    {
        return ;
    }
    Binary(n/2);
    cout<<n%2;
}

//function to find factorial of a number
int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*factorial(n-1);
}

//function to find fibonacci nth number
int fibonacci(int n)
{ if(n<=1)
  return n;

     return fibonacci(n-1)+fibonacci(n-2);
}
//function to return sum of first n natural number
int sum(int n)
{
    if(n==0)
        return 0;

    return n+sum(n-1);
}
//function to check a number is palindrome or not
bool palindrome(char arr[],int low,int high)
{
    if(low>=high)
    {
        return true;
    }

     return arr[low]==arr[high] && palindrome(arr,low+1,high-1);
}

//function to find sum of digits
int SumOfDigits(int n)
{
    if(n==0)
    return 0;
    return n%10+SumOfDigits(n/10);
}


//function to find maximum cuts in a rope
int ropeCutting(int n,int a,int b,int c)
{
    if(n<0)
    {
        return -1;
    }
    else if(n==0)
    {
        return 0;
    }

    int res=max(max(ropeCutting(n-a,a,b,c),ropeCutting(n-b,a,b,c)),ropeCutting(n-c,a,b,c));
    if(res<0)
    {
        return -1;
    }else return res+1;


}
//function to find all the subsets of a string
void SubSet(string str,string curr="",int index=0)
{
    if(index == (int)str.length())
    {
        cout<<curr<<" ";
        return;
    }
     SubSet(str,curr+str[index],index+1);
     SubSet(str,curr,index+1);
}

//function to implement tower of hanoi problem
void toh(int n,char a,char b,char c)
{
    if(n==1)
    {
        cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<endl;
        return;
    }
    toh(n-1,a,c,b);
    cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<endl;

    toh(n-1,b,a,c);

}

//function to solve josephus problem

int jojo(int n,int k)
{
   if(n==1)
   {
       return 0;
   }
   return (jojo(n-1,k))%n;
}
int myJos(int n, int k)
{
	return jojo(n, k) + 1;
}

//function to  find sum of subset in an array
int SumSub(int arr[],int n,int sum)
{
    if(n==0)
    {
        return(sum==0)?1:0;
    }
   return SumSub(arr,n-1,sum-arr[n-1])+SumSub(arr,n-1,sum);

}

int main()
{  int n=3;
    int arr[n]={5,10,20};
   cout<<SumSub(arr,n,1);

    return 0;
}
