//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
        // unordered_set<char>temp;
        int n=s.length();
        vector<int>temp(26,0);
        for(int i=0;i<s.length();i++)
        {
            temp[s[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            if(temp[s[i]-'a']==1)
            {
                return s[i];
            }
        }
        return '$';
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends