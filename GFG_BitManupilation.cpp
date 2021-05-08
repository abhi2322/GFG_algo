#include <iostream>

using namespace std;

//function to find if kth bit is set or not
bool check_1(int n,int k)
{
    return (n&(1<<(k-1)))!=0?true:false;
}

//function to count number of set bits
int count_setbits(int n)
{
    int counter=0;
    while(n!=0)
    {
        if((n&1)==1)
            {counter++;}        /* can also use n%2==0 to check if last bit is set or not but is more expensive than my method*/
       //res+=(n&1) another clever way


        n=n>>1;   // can also use n=n/2 operator but also expensive

    }
    return counter;
}

//function to check if a number is power 2
bool CheckPower2(int n)
{   if(n==0)
    return false;
    if(n&(n-1))
    {
        return false;
    }
   return true;
}
//function to find two odd occuring number in an array
void find_odd2(int arr[],int n)
{ int res=0;
     for(int i=0;i<n;i++)
     {
          res=res^arr[i];
     }
     int sn=res&(~(res-1));
     int res1=0;
     int res2=0;
     for(int i=0;i<n;i++)
     {
         if((arr[i]&sn)==1)
         {
             res1=res1^arr[i];
         }
         else
         {
             res2=res2^arr[i];
         }
     }
     cout<<res1<<" "<<res2;
}
int main()
{
  int arr[]={2,2,3,3,2,3,4,4,5,5};
  find_odd2(arr,10);


}
