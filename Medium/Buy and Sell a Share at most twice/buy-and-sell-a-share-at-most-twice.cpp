//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// int helper(vector<int>prices,int ind,int n,int buy,int trans,vector<vector<vector<int>>>&dp)
// {
//     if(ind==n)
//     {
//         return 0;
//     }
//     if(trans>2)
//     {
//         return 0;
//     }
//     if(dp[ind][buy][trans]!=-1)
//     {
//         return dp[ind][buy][trans];
//     }
//     int profit=0;
//     if(buy&&trans<=2)
//     {
//         profit=max(-prices[ind]+helper(prices,ind+1,n,0,trans+1,dp),helper(prices,ind+1,n,1,trans,dp));
//     }
//     else if(!buy&&trans<=2)
//     {
//         profit=max(prices[ind]+helper(prices,ind+1,n,1,trans,dp),helper(prices,ind+1,n,0,trans,dp));
//     }
//     return dp[ind][buy][trans]= profit;
// }
int maxProfit(vector<int>&prices)
{
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(4,0)));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int trans=2;trans>=0;trans--)
            {
                int profit=0;
                if(buy&&trans<=2)
                {
                    profit=max(-prices[ind]+dp[ind+1][0][trans+1],dp[ind+1][1][trans]);
                }
                else if(!buy&&trans<=2)
                {
                    profit=max(prices[ind]+dp[ind+1][1][trans],dp[ind+1][0][trans]);
                }
                dp[ind][buy][trans]= profit;
            }
        }
    }
    return dp[0][1][0];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends