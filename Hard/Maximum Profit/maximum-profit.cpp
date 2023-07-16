//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int prices[]) 
    {
        vector<vector<int>>curr(2,vector<int>(K+1,0)),ahead(2,vector<int>(K+1,0));
        for(int ind=N-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int trans=1;trans<=K;trans++)
                {
                    int profit=0;
                    if(buy&&trans<=K)
                    {
                        profit=max(-prices[ind]+ahead[0][trans],ahead[1][trans]);
                    }
                    else if(!buy&&trans<=K)
                    {
                        profit=max(prices[ind]+ahead[1][trans-1],ahead[0][trans]);
                    }
                    curr[buy][trans] = profit;
                }
                ahead=curr;
            }
        }
        return ahead[1][K];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends