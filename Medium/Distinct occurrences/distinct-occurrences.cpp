//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod=1e9+7;
    int helper(string str1,string str2,int ind1,int ind2)
    {
        if(ind2==0)
        {
            return 1;
        }
        if(ind1==0)
        {
            return 0;
        }
        int nottake=helper(str1,str2,ind1-1,ind2);
        int take=0;
        if(str1[ind1-1]==str2[ind2-1])
        {
            take=helper(str1,str2,ind1-1,ind2-1);
        }
        return take+nottake;
    }
    int subsequenceCount(string str1, string str2)
    {
        int n=str1.length();
        int m=str2.length();
        // return helper(str1,str2,n,m);
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int ind1=0;ind1<=n;ind1++)
        {
            dp[ind1][0]=1;
        }
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=0;ind2<=m;ind2++)
            {
                int nottake=dp[ind1-1][ind2];
                int take=0;
                if(str1[ind1-1]==str2[ind2-1])
                {
                    take=dp[ind1-1][ind2-1];
                }
                dp[ind1][ind2]=(take+nottake)%mod;
            }
        }
        return dp[n][m];
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends