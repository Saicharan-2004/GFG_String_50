//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool helper(string str1,string str2,string final,int ind1,int ind2,int gen,vector<vector<int>>&dp)
    {
        if(gen==0)
        {
            return true;
        }
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        bool two,three;
        two=false;
        three=false;
        if(ind1-1>=0&&gen-1>=0&&str1[ind1-1]==final[gen-1])
        {
            two=helper(str1,str2,final,ind1-1,ind2,gen-1,dp);
        }
        if(ind2-1>=0&&gen-1>=0&&str2[ind2-1]==final[gen-1])
        {
            three=helper(str1,str2,final,ind1,ind2-1,gen-1,dp);
        }
        return dp[ind1][ind2]= two||three;
    }
    bool isInterleave(string A, string B, string C) 
    {
        int n=A.length();
        int m=B.length();
        int f=C.length();
        if(n+m!=f)
            return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(A,B,C,n,m,f,dp);
        
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends