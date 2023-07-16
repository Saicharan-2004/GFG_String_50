//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // int helper(vector<long long>prices,int n,int ind,int buy,vector<vector<int>>&dp)
    // {
    //     if(ind==n)
    //     {
    //         return 0;
    //     }
    //     if(dp[ind][buy]!=-1)
    //     {
    //         return dp[ind][buy];
    //     }
    //     long long profit=0;
    //     if(buy)
    //     {
    //         profit=max(-prices[ind]+helper(prices,n,ind+1,0,dp),helper(prices,n,ind+1,1,dp));
    //     }
    //     else
    //     {
    //         profit=max(prices[ind]+helper(prices,n,ind+2,1,dp),helper(prices,n,ind+1,0,dp));
    //     }
    //     return dp[ind][buy]=profit;
    // }
    long long maximumProfit(vector<long long>&prices, int n) 
    {
        vector<vector<long long >>dp(n+2,vector<long long int>(2,0));
        // return helper(prices,n,0,1,dp);
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    profit=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends