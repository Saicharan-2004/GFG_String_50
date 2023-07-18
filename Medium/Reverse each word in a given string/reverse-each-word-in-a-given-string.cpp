//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string arr)
    {
        stack<string>temp;
        int startIndex=0;
        int n=arr.length();
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='.')
            {
                temp.push(arr.substr(startIndex,i-startIndex));
                startIndex=i+1;
            }
        }
        temp.push(arr.substr(startIndex,n-startIndex));
        string str="";
        while(!temp.empty())
        {
            string s=temp.top();
            reverse(s.begin(),s.end());
            str='.'+s+str;
            temp.pop();
        }
        return str.substr(1,str.length()-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends