//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str)
		{
		    int n=str.length();
		    string ans="";
		    queue<char>q;
		    unordered_map<char,int>temp;
		    temp[str[0]]++;
		    ans+=str[0];
		    q.push(str[0]);
		    for(int i=1;i<n;i++)
		    {
		        temp[str[i]]++;
		        if(temp[str[i]]==1)
		        {
		            q.push(str[i]);
		        }
		        while(!q.empty() && temp[q.front()]>1)
		        {
		            q.pop();
		        }
		        if(q.empty())
		        {
		            ans+='#';
		        }
		        else
		        {
		            ans+=q.front();
		        }
		    }
		    return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends