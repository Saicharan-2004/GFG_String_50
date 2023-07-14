//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int mod=1e9+7;
	int distinctSubsequences(string s)
	{
        vector<long long>dp(s.length()+1,0);
        dp[0]=1;
        int n=s.length();
        unordered_map<char,int>temp;
        for(int i=1;i<=s.length();i++)
        {
            dp[i]=2*dp[i-1]%mod;
            if(temp.count(s[i-1])>0)
            {
                dp[i]-=dp[temp[s[i-1]]];
                dp[i]=dp[i]%mod;
            }
            temp[s[i-1]]=i-1;
            dp[i]=dp[i]%mod;
        }
        if(dp[n]<0)
            return mod+=dp[n];
        return dp[s.length()]%mod;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends