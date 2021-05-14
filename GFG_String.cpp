#include <iostream>
#include <cstring>
#include<unordered_set>
#include <unordered_map>
#include <algorithm>
#include<math.h>

using namespace std;

//function to print frequency of letters in a sorted way in a string
void strfreq(string &str)
{
    int counter[26]={0};
     for(int i=0;i<(int)str.length();i++)
    {
        counter[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(counter[i]>0)
        {
            cout<<char(i+'a')<<":"<<counter[i]<<endl;
        }
    }

}

//function to find if a number is palindrome or not
void check_palindrome(string &str)
{
    int low=0; //pointing to start of string
    int high=(int)str.length()-1;//using length function to find its length and point to last of string
    bool flag=true;//flag to keep track of palindrome
    while(low<high)//works only till low is less than high
     {
        if(str[low]!=str[high])
        {
            flag=false;
            break;
        }
        low++;
        high--;
    }
    if(flag==true)
    {
        cout<<"Palindrome";
    }
    else
    {
        cout<<"Not palindrome";
    }
}

//function to check if string 2 is a subsequence of string 1
bool subsequence(string &str1,string &str2)
{
    int pointer1=0;//pointer for str1
    int pointer2=0;//pointer for str2
    if(str1.length()<str2.length())
        return false;
    while(pointer1<(int)str1.length()&&pointer2<(int)str2.length())
    {
        if(str1[pointer1]==str2[pointer2])
        {
            pointer1++;
            pointer2++;
        }
        else
            pointer1++;
    }
    return(pointer2==(int)str2.length());


}
//recursive solution to find if string 2 is subsequence of string 1
bool rec_subsequence(string &str1,string &str2,int m,int n)
{  if(n==0)
    {return true;}

    if(m==0)
    {return false;
    }
     if(str1[m-1]==str2[n-1])
        return rec_subsequence(str1,str2,m-1,n-1);
     else
        return rec_subsequence(str1,str2,m-1,n);
}

//function to check if an string is an anagram of another string(naive)
bool anagram_naive(string &str1,string &str2,int m,int n)
{
    if(m!=n)
    {
        return false;
    }
    int arr[m];
    std::fill_n(arr,m,1);
    for(int i=0;i<m;i++)
    { bool flag=true;
        for(int j=0;j<n;j++)
        {
            if(str1[i]==str2[j]&&arr[j]==1)
            {
                flag=false;
                arr[j]=0;
                break;
            }
        }
        if(flag)
        return false;

    }
    return true;
}
//function to check of one string is an anagram of another(efficient)
bool anagram_effec(string &str1,string &str2,int m,int n)
{
    if(m!=n)
        return false;
    unordered_map<char,int>hashtable;
    for(int i=0;i<n;i++)
    {
        hashtable[str1[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(hashtable.find(str2[i])!=hashtable.end() && hashtable[str2[i]]>0)
        {
            hashtable[str2[i]]--;
        }
        else
        {
            return false;
        }
    }
    return true;

}

//function to find if an array is an anagram of another string
bool anagram(string &str1,string &str2,int m,int n)
{   if(m!=n)
     return false;

    const int CHAR =256;
    int arr[CHAR]={0};

    for(int i=0;i<n;i++)
    {
        arr[str1[i]-'a']++;
        arr[str2[i]-'a']--;
    }
    for(int i=0;i<CHAR;i++)
    {
        if(arr[i]!=0)
            return false;
    }
    return true;
}

//function left most repeating element an string
int LeftRepeat(string &str)
{
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(str[i]==str[j])
                return i+1;
        }
    }
    return -1;
}
//function to find left most repeating element in a string(effective with hash)
int LeftRepeatEffec(string &str)
{
    int len=str.length();
    unordered_map<char,int>hashtable;
    for(int i=0;i<len;i++)
    {
        hashtable[str[i]]++;
    }
    for(int i=0;i<len;i++)
    {
        if(hashtable[str[i]]>1)
            return i+1;
    }
    return -1;
}
//function to find left most repeating element in a string(effective without hash)
int LeftRepeatEffec2(string &str)
{
    int len=str.length();
    const int CHAR=26;
    int character_array[CHAR]={0};
    for(int i=0;i<len;i++)
    {
        character_array[str[i]-'a']++;
    }
    for(int i=0;i<len;i++)
    {
        if(character_array[str[i]-'a']>1)
            return i+1;
    }
    return -1;


}
//function to find left most repeating element in a string (effective in one trivrsal)
int LeftRepeatEffec3(string &str)
{
    int len=str.length();
    const int CHAR=256;
    int arr[CHAR];
    int res=INT_MAX;
    fill(arr,arr+CHAR,-1);
    for(int i=0;i<len;i++)
    {
        if(arr[(int)str[i]]==-1)
        {
            arr[(int)str[i]]=i;
        }
        else
        {
            res=min(res,arr[(int)str[i]]);
        }
    }
    return(res==INT_MAX)?-1:res;
}
//function to find left most repeating element in a string(effective method in one traversal from right to avoid)
int LeftRepeatEffec4(string &str)
{
    int len=str.length();
    const int CHAR=256;
    int arr[CHAR];
    fill(arr,arr+CHAR,-1);
    int res=-1;;
    for(int i=len-1;i>=0;i--)
    {
        if(arr[(int)str[i]]==-1)
        {
            arr[(int)str[i]]=0;
        }
        else
        {
            res=i;
        }
    }
    return res;
}
//function to find left most non-repeating character in a string
int LeftNonRepeat(string str)
{
    int len=str.length();
    int res=INT_MAX;
    for(int i=0;i<len;i++)
    {bool flag=true;
        for(int j=i+1;j<len;j++)
        {
            if(str[j]==str[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            res=min(res,i);
        }
    }
    return (res==INT_MAX)?-1:res;
}
//function to find the  first left non repeating character in a string
int LeftNonRepeat1(string str)
{
    const int CHAR=26;
    int arr[CHAR]={0};
    for(int i=0;i<(int)str.length();i++)
    {
        arr[str[i]-'a']++;
    }
    for(int i=0;i<(int)str.length();i++)
    {
        if(arr[str[i]-'a']==1)
        {
            return i;
        }
    }
    return -1;
}
//function to find left most non repeating item in a string (my method worst case (nxCHAR))
int LeftNonRepeat2(string str)
{
    const int CHAR=26;
    int arr[CHAR]={0};
    int n=str.length();
    int j=0;
    for(int i=0;i<n;i++)
    {
        arr[str[i]-'a']++;

     while(arr[str[j]-'a']!=1&&j<n)
     {
         j++;
     }

    }

    if(arr[str[j]-'a']==1)
        return j;
    else
        return -1;
}
/*function to find left most non repeating term in an string(effective method by sir on does one traversal of string and a traversal
of an const array whose time complexity we can consider constant*/
int LeftNonRepeat3(string str)
{
    int len=str.length();
    const int CHAR=256;
    int arr[CHAR];
    fill(arr,arr+CHAR,-1);
    for(int i=0;i<len;i++)
    {
        if(arr[(int)str[i]]==-1)
            arr[(int)str[i]]=i;
        else
            arr[(int)str[i]]=-2;
    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++)
    {
        if(arr[i]>0)
            res=min(res,arr[i]);
    }
    return(res==INT_MAX)?-1:res;
}

//function to reverse a string by words having spaces
/* sir has first reversed each word then the string both work same*/
void reversestring(string &str,int low,int high)
{
    while(low<high)
    {
        swap(str[low],str[high]);
        low++;
        high--;
    }
}
void ReverseWords(string &str)
{
    reversestring(str,0,str.length()-1);
    int low=0;
    for(int i=0;i<(int)str.length();i++)
    {
        if(str[i]==' ')
        {
            reversestring(str,low,i-1);
            low=i+1;
        }

    }
    reversestring(str,low,str.length()-1);

}

//function to find index of sub string in a string(string matching)
void substring(string str,string str1)
{
    int len=str.length();
    int len2=str1.length();
    for(int i=0;i<len-len2;i++)
    {
        int j=i;
        int k=0;
        while(k<(int)str1.length() && str[j]==str1[k])
        {
            j++;
            k++;
        }
        if(j-i==(int)str1.length())
        {
            cout<<i<<" ";
        }

    }
}

//function to find index of sub string in a string(sir's more cleaner way)
void substring2(string text,string pattern)
{
    int len1=text.length();
    int len2=pattern.length();
    for(int i=0;i<=(len1-len2);i++)
    { int j;
        for(j=0;j<len2;j++)
        {
            if(text[j+i]!=pattern[j])
            break;
        }
        if(j==len2)
        {
            cout<<i<<" ";
        }
    }
}

//function to find index of sub string in a string if pattern string has only distinct element
void substring3(string text,string pattern)
{
    int len1=text.length();
    int len2=pattern.length();
    for(int i=0;i<=len1-len2;)
    { int j;
        for(j=0;j<len2;j++)
        {
            if(text[j+i]!=pattern[j])
            {
                break;
            }

        }
          if(j==len2)
            {
                cout<<i<<" ";
            }
            if(j==0)
                i++;
            else
            i=i+j;

    }
}
//function to find index of substring in a string Rabin Karp algorithm
void substringRabin(string str1,string str2)
{
    int len1=str1.length();
    int len2=str2.length();
     int h=1;
    const int q=101;
    const int d=256;
    for(int i=1;i<=len2-1;i++)
    {
        h=(h*d)%q;
    }
    int p=0;
    int t=0;
    for(int i=0;i<len2;i++)
    {
        p=(p*d+str2[i])%q;
        t=(t*d+str1[i])%q;

    }

    for(int i=0;i<=len1-len2;i++)
    { cout<<t<<endl;
        if(t==p)
        { bool flag=true;
            for(int j=0;j<len2;j++)
            {
                if(str1[i+j]!=str2[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                {cout<<i<<" ";}

        }
        if(i<len1-len2)
        {
            t=((d*(t-str1[i]*h))+str1[len2+i])%q;

        if(t<0)
        {
            t=t+q;
        }
        }

    }



}

//function to create lps array from kmp algorithm
void lps_array(string str)
{  int len=str.length();
    int arr[len]={0};
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
             int low=0;
             int high=i-j;
             int res=0;
             while(low<=j&&high<=i)
             {
                 if(str[low]!=str[high])
                 {    res=0;
                     break;
                 }
                 else
                 {
                     high++;
                     low++;
                     res++;
                 }


             }
             arr[i]=max(res,arr[i]);
        }
    }
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//function to create a lps array for kmp algorithm (sir's way)
int lpsstring(string str,int n)
{
    for(int i=n-1;i>0;i--) //we have >0 because we are here choosing how many string at a time like 1 string or 2 string
    {
        bool flag=true;
        for(int j=0;j<i;j++)/*like see index 0,1,2 we pass 3 to lpsstring then i=2 i.e maximum 2 length prefix string so
                               but j is indexing so it starts with 0 so i can index only 0,1 since max length of prefix string is
                               2,therefore j<i*/
        {
            if(str[j]!=str[n-i+j])
            {flag=false;
             break;
            }
        }
        if(flag==true)
            return i;
   }
return 0;
}

void lps_array2(string str)
{ int len=str.length();
    for(int i=0;i<len;i++)
    {
        int res=lpsstring(str,i+1);//converting from index to simple numbers like 2 string a a time or 3 string at a time
        cout<<res<<" ";
    }
}

//function to form lps array (effective method)(incompelet method)
void lps_array3(string str)
{ int n=str.length();
 int arr[n]={0};
    for(int i=1;i<n;i++)
    { int low=arr[i-1];
        int high=i;
        if(str[low]==str[high])
        {
            arr[i]=low+1;
        }
        else if(low==0)
        {
            arr[i]=0;
        }

    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//function to form lps array(effective method complete method)
void lps_array4(string str,int *lps)
{
    int n=str.length();
    for(int i=0;i<n;i++)
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<n)
    {
        if(str[i]==str[len])
        {   len++;
            lps[i]=len;
            i++;
        }
        else if(len==0)
        {
            lps[i]=0;
            i++;
        }
        else
        {
            len=lps[len-1];
        }
    }

}

//kmp algorithm
void kmp(string text,string pattern)
{
    int N=text.length();
    int M=pattern.length();
    int lps[M];
    lps_array4(pattern,lps);
    int i=0;
    int j=0;
     while(i<N)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;

        }
        if(j==M)
        {
            cout<<i-j<<" ";
            j=lps[j-1];
        }
        else if(i<N && text[i]!=pattern[j])
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=lps[j-1];
            }
        }

    }



}

//function to check if a string is rotated in comparison to other string
bool rotated(string str1,string str2)
{
    if(str1.length()!=str2.length())
    {
        return false;
    }
    return ((str1+str1).find(str2)!=string::npos);
}


//function to create anagram search

bool check_anagram(string str2,int *arr)
{

   bool flag=false;
   int len=str2.length();
   for(int i=0;i<len;i++)
   {
       if(arr[str2[i]-'a']<1)
       {
           flag=true;
           break;
       }

   }
   if(flag)
      return false;
   else
     return true;


}
bool anagram_search(string text,string pattern)
{
    int N=text.length();
    int M=pattern.length();

    const int MAX=25;
    int charac_array[MAX]={0};
    for(int i=0;i<M;i++)
    {
        charac_array[text[i]-'a']++;
    }
    for(int i=M;i<=N;i++)
    {
        bool res=check_anagram(pattern,charac_array);
        if(res)
        {
            return true;
        }
        else
        {
            charac_array[text[i-M]-'a']--;
            charac_array[text[i]-'a']++;
        }
    }
    return false;

}

//function to find anagram of an string in another string (effective method)
bool anagram_search_effec(string text,string pattern)
{
    const int CHAR=25;
    int N=text.length();
    int M=pattern.length();
    int charac_array[CHAR]={0};
    for(int i=0;i<M;i++)
    {
        charac_array[pattern[i]-'a']--;
        charac_array[text[i]-'a']++;
    }
    for(int i=0;i<=N-M;i++)
    {  bool res=true;

        for(int j=0;j<CHAR;j++)
        {
            if(charac_array[j]!=0)
                {res=false;
                break;}
        }

        if(res)
            {return true;}
        else
        {
            charac_array[text[i]-'a']--;
            charac_array[text[i+M]-'a']++;
        }
    }
    return false;

}

//function to find the rank of a string in lexicographic order
int factorial(int n)
{
    return(n==1||n==0)?1:n*factorial(n-1);
}


int string_rank(string str)
{
    int len=str.length();
    int fact=factorial(len);
    const int CHAR=256;
    int charac_array[CHAR]={0};
    for(int i=0;i<len;i++)
    {
        charac_array[(int)str[i]]++;
    }
    for(int i=1;i<CHAR;i++)
    {
        charac_array[i]+=charac_array[i-1];
    }
    int res=0;
    for(int i=0;i<len-1;i++)
    {
        fact=fact/(len-i);
        res+=(charac_array[str[i]-1])*fact;
        for(int j=str[i];j<256;j++)
        {
            charac_array[j]--;
        }
    }
    return res+1;
}

//function to find longest substring with distinct characters
int Ls_distinct(string str)
{
    int len=str.length();
    int res=0;
    const int CHAR=256;
    for(int i=0;i<len;i++)
    { int chara_array[CHAR]={0};

      int j;
        for(j=i;j<len;j++)
        {
            if(chara_array[(int)str[j]]!=0)
                {
                break;}
                else
                {
                    chara_array[(int)str[j]]=1; // sir wrote here res=max(res,j-i+1) so every time it doesn't break we update the result
                }

        }
        res=max(res,j-i);

    }
    return res;
}
//function to find the longest substring that is distinct(my way not optimised)
int ls_distinct(string str)
{
    int len=str.length();
    int res=0;
    const int CHAR=25;
    int charac_array[CHAR];
    for(int i=0;i<25;i++)
    {
        charac_array[i]=-1;
    }
    int j=0;
    for(int i=0;i<len;i++)
    {
        if(charac_array[str[i]-'a']!=-1)
        {
            if(j<=charac_array[str[i]-'a']) /*this is is important as if we have a element that re-occur very later in the array
                                            and we have discarded the pervious substrings(i.e if we get a value for j that is lesser
                                            current j) so we should no update j and just consider it as first occurrence.
                                            try example abcabdefabacab here c comes much later.*/
            {
                j=charac_array[str[i]-'a']+1;
            }



            charac_array[str[i]-'a']=i;


        }
        else
        {
            charac_array[str[i]-'a']=i;
        }
        /* for(int i=0;i<25;i++)
        {
            cout<<charac_array[i]<<" "; ///for debugging
        }

        cout<<endl;
        */
        res=max(res,i-j+1);
        //cout<<j<<":"<<res<<endl;

    }
    return res;
}
//function to find longest subsequence with distinct character
int ls_distinct2(string str)
{
    int len=str.length();
    int j=0;
    int maxend=0;
    int res=0;
    int const CHAR=256;
    int charac_array[CHAR];
    for(int i=0;i<CHAR;i++)
    {
        charac_array[i]=-1;
    }
    for(int i=0;i<len;i++)
    {
        j=max(j,charac_array[(int)str[i]]+1);
        maxend=i-j+1;
        res=max(res,maxend);
        charac_array[(int)str[i]]=i;
    }
    return res;
}

//function in implement anagram search using XOR
bool anagram_search_XOR(string txt,string pat)
{
    int res=0;
    int len1=txt.length();
    int len2=pat.length();
    for(int i=0;i<len2;i++)
    {
        res=(res^(txt[i]^pat[i]));
    }
    for(int i=0;i<=len1-len2;i++)
    {
        if(res==0)
            {return true;}
        res=(res^(txt[i]^txt[i+len2]));

    }
    return false;
}

int main()
{
  string str1="abcd";
  string str2="a";







}

