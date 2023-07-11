//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        int smallestLen=INT_MAX;
        string str="";
        for(int i=0;i<n;i++)
        {
            if(arr[i].length()<smallestLen)
            {
                str=arr[i];
                smallestLen=arr[i].length();
            }
        }
        string final="";
        for(int i=0;i<str.length();i++)
        {
            char check=str[i];
            int c=0;
            bool che=false;
            for(int j=0;j<n;j++)
            {
                if(arr[j][i]==check)
                {
                    c++;
                }
                else
                {
                    if(final=="")
                    {
                        return "-1";
                    }
                    return final;
                }
            }
            if(c==n)
            {
                final+=check;
            }
        }
        if(final=="")
        {
            return "-1";
        }
        return final;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends