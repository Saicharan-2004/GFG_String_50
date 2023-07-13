//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) 
        {
            int countDots=0;
            for(auto it:s)
            {
                if(it=='.')
                {
                    countDots++;
                }
            }
            if(countDots!=3)
            {
                return 0;
            }
            int n=s.length();
            int startIndex=0;
            int i=0;
            while(i<n)
            {
                if(s[i]=='.')
                {
                    if(i==startIndex)
                    {
                        return false;
                    }
                    string e=s.substr(startIndex,i-startIndex);
                    for(auto it:e)
                    {
                        if(it>57||it<48)
                        {
                            return false;
                        }
                    }
                    int r=stoi(e);
                    if(r==0&&e.length()>1)
                        return false;
                    if(0>r||r>255)
                    {
                        return false;
                    }
                    else 
                    {
                        int ew=0;
                        int q=0;
                        while(q<e.length())
                        {
                            if(e[q]!='0')
                            {
                                break;
                            }
                            q++;
                        }
                        if(q!=0&&e.length()!=1)
                            return false;
                    }
                    startIndex=i+1;
                }
                i++;
            }
            string e=s.substr(startIndex,i-startIndex);
            int r=stoi(e);
            if(r==0&&e.length()>1)
                return false;
            if(0>r||r>255)
            {
                return false;
            }
            else
            {
                
                int ew=0;
                int q=0;
                while(q<e.length())
                {
                    if(e[q]!='0')
                    {
                        break;
                    }
                    q++;
                }
                if(q!=0&&e.length()!=1)
                    return false;
            }
            return true;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends