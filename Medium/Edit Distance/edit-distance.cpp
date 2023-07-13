//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int helper(string s, string t,int ind1,int ind2)
    {
        if(ind1==0)
        {
            return ind2;
        }
        if(ind2==0)
        {
            return ind1;
        }
        if(s[ind1-1]==t[ind2-1])
        {
            return helper(s,t,ind1-1,ind2-1);
        }
        else
        {
            int insert=1+helper(s,t,ind1,ind2-1);
            int delet=1+helper(s,t,ind1-1,ind2);
            int replace=1+helper(s,t,ind1-1,ind2-1);
            return min(insert,min(delet,replace));
        }
    }
    int editDistance(string s, string t) 
    {
        int n=s.length();
        int m=t.length();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>curr(m+1,0),prev(m+1,0);
        // return helper(s,t,n-1,m-1);
        
        for(int ind2=0;ind2<=m;ind2++)
        {
            prev[ind2]=ind2;
        }
        for(int i=1;i<=n;i++)
        {
            curr[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=prev[j-1];
                }
                else
                {
                    curr[j]=1+min(prev[j-1],min(prev[j],curr[j-1]));
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends