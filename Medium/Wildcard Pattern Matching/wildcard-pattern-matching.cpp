//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool helper(string pattern,string str,int ind1,int ind2,vector<vector<int>>&dp)
    {
        if(ind1==0&&ind2==0)
        {
            return true;
        }
        if(ind1==0&&ind2>0)
        {
            return false;
        }
        if(ind2==0&&ind1>0)
        {
            for(int i=0;i<ind1;i++)
            {
                if(pattern[i]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        if(pattern[ind1-1]==str[ind2-1] || pattern[ind1-1]=='?')
        {
            return dp[ind1][ind2]= helper(pattern,str,ind1-1,ind2-1,dp);
        }
        if(pattern[ind1-1]=='*')
        {
            return dp[ind1][ind2]= helper(pattern,str,ind1-1,ind2,dp)||helper(pattern,str,ind1,ind2-1,dp);
        }
        return dp[ind1][ind2]= false;
            
    }
    int wildCard(string pattern,string str)
    {
        int n=pattern.length();
        int m=str.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(pattern,str,pattern.length(),str.length(),dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends