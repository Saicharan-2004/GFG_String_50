//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        int rep=b.length()/a.length();
        rep+=3;
        string d="";
        for(int i=0;i<rep;i++)
        {
            d+=a;
        }
        int breaker=0;
        for(int i=0;i<d.length();i++)
        {
            if(d.substr(i,b.length())==b)
            {
                breaker=i+b.length();
                break;
            }
        }
        if(breaker==0)
        {
            return -1;
        }
        else
        {
            int templen=d.length()-breaker;
            int r=templen/a.length();
            // r--;
            return rep-r;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends