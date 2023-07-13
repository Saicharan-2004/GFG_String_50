//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int i=0;
        int n=s.length();
        int startIndex=0;
        reverse(s.begin(),s.end());
        while(i<n)
        {
            if(s[i]=='.')
            {
                int tempEnd=i-1;
                int tempStart=startIndex;
                while(tempStart<tempEnd)
                {
                    swap(s[tempStart],s[tempEnd]);
                    tempStart++;
                    tempEnd--;
                }
                startIndex=i+1;
            }
            i++;
        }
        int tempEnd=n-1;
        int tempStart=startIndex;
        while(tempStart<tempEnd)
        {
            swap(s[tempStart],s[tempEnd]);
            tempStart++;
            tempEnd--;
        }
        return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends