//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<vector<int>>arr,int j1,int j2,int i,int n,int m,vector<vector<vector<int>>>&dp)
    {
        if(j1<0||j2<0||j1>m-1||j2>m-1)
        {
            return -1e8;
        }
        if(i==n-1)
        {
            if(j1==j2)
            {
                return arr[i][j1];
            }
            return arr[i][j1]+arr[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        int maxi=-1e8;
        for(int k=-1;k<=1;k++)
        {
            for(int j=-1;j<=1;j++)
            {
                int val=0;
                if(j1==j2)
                {
                    val=arr[i][j1];
                }
                else
                {
                    val=arr[i][j1]+arr[i][j2];
                }
                val=val+helper(arr,j1+j,j2+k,i+1,n,m,dp);
                maxi=max(maxi,val);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int maxii(int i,int j1,int j2,int r,int c, vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
    {
     if(j1<0||j2<0||j1>=c||j2>=c)
     {
         return -1e8;
     }
     if(i==r-1)
     {
         if(j1==j2)return grid[i][j1];
         else return grid[i][j1]+grid[i][j2];
     }
    
     if(dp[i][j1][j2]!=-1)
     return dp[i][j1][j2];
     //exploring all the path of alice and bob simultenesly
     int maxi=-1e8;
     for(int dj1=-1;dj1<=+1;dj1++)
     {
         for(int dj2=-1;dj2<=+1;dj2++)
         {
             int value=0;
             if(j1==j2)
             return grid[i][j1];
             else 
             value=grid[i][j1]+grid[i][j2];
             value+=maxii(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
             maxi=max(maxi,value);
         }
     }
     return dp[i][j1][j2]= maxi;
    }
    int solve(int n, int m, vector<vector<int>>& arr) 
    {
        vector<vector<vector <int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return maxii(0,0,m-1,n,m,arr,dp);
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;i<m;j++)
        //     {
        //         if(i==j)
        //         {
        //             dp[n-1][j][j]=arr[n-1][j];
        //         }
        //         else
        //         {
        //             dp[n-1][i][j]=arr[n-1][j]+arr[n-1][i];
        //         }
        //     }
        // }
        // for(int i=n-2;i>=0;i--)
        // {
        //     for(int j1=m-1;j1>=0;j1--)
        //     {
        //         for(int j2=0;j2<m;j2++)
        //         {
        //             int maxi=-1e8;
        //             for(int k=-1;k<=1;k++)
        //             {
        //                 for(int j=-1;j<=1;j++)
        //                 {
        //                     int val=0;
        //                     if(j1==j2)
        //                     {
        //                         val=arr[i][j1];
        //                     }
        //                     else
        //                     {
        //                         val=arr[i][j1]+arr[i][j2];
        //                     }
        //                     val=val+dp[i][j1+j][j2+k];
        //                     maxi=max(maxi,val);
        //                 }
        //             }
        //             return dp[i][j1][j2]=maxi;
        //         }
        //     }
        // }
        // return dp[0][0][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends