//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int helper(vector<int>arr,int target,int ind,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(target==0&&arr[ind]==0)
            {
                return 2;
            }
            if(target==0||arr[ind]==target)
            {
                return 1;
            }
            return 0;
        }
        if(dp[ind][target+1000]!=-1)
        {
            return dp[ind][target+1000];
        }
        int nottake=helper(arr,target,ind-1,dp);
        int take=0;
        if(target>=arr[ind])
        {
            take=helper(arr,target-arr[ind],ind-1,dp);
        }
        return dp[ind][target+1000]=take+nottake;
    }
    int findTargetSumWays(vector<int>&arr ,int target) 
    {
        int sum=0;
        for(auto it:arr)
        {
            sum+=it;
        }
        if((sum-target)<0||(sum-target)%2!=0)
        {
            return 0;
        }
        else
        {
            int tar=(sum-target)/2;
            vector<vector<int>>dp(arr.size(),vector<int>(tar+1000+1,-1));
            return helper(arr,tar,arr.size()-1,dp);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends