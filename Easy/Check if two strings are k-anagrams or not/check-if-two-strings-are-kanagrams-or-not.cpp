//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

//User function template for C++

class Solution {
  public:
    // int LCS(string str1, string str2,int ind1,int ind2,vector<vector<int>>&dp)
    // {
    //     if(ind1<0||ind2<0)
    //     {
    //         return 0;
    //     }
    //     if(dp[ind1][ind2]!=-1)
    //     {
    //         return dp[ind1][ind2];
    //     }
    //     if(str1[ind1]==str2[ind2])
    //     {
    //         return dp[ind1][ind2]= 1+LCS(str1,str2,ind1-1,ind2-1,dp);
    //     }
    //     else
    //     {
    //         return dp[ind1][ind2]= max(LCS(str1,str2,ind1-1,ind2,dp),LCS(str1,str2,ind1,ind2-1,dp));
    //     }
    // }
    bool areKAnagrams(string str1, string str2, int k) 
    {
        int n=str1.length();
        int m=str2.length();
        if(n!=m)
        {
            return 0;
        }
        vector<int>counter1(26,0);
        vector<int>counter2(26,0);
        for(auto it:str1)
        {
            counter1[it-'a']++;
        }
        for(auto it:str2)
        {
            counter2[it-'a']++;
        }
        int counter=0;
        for(int i=0;i<26;i++)
        {
            counter+=abs(counter1[i]-counter2[i]);
        }
        if(counter<=2*k)
            return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends