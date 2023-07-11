//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
// 		return helper(s,word1,word2,0,n-1);
        int found1=-1;
        int n=s.size();
	    int found2=-1;
	    int ans=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]==word1)
	        {
	            found1=i;
	            if(found2!=-1)
	                ans=min(ans,abs(found1-found2));
	        }
	        if(s[i]==word2)
	        {
	            found2=i;
	            if(found1!=-1)
	                ans=min(ans,abs(found1-found2));
	        }
	    }
	    return ans;
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
   		int n;
   		cin >> n;

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends