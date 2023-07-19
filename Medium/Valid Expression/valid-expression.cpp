//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    stack<char>temp;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            temp.push(s[i]);
        }
        else if(s[i]=='{')
        {
            temp.push(s[i]);
        }
        else if(s[i]=='[')
        {
            temp.push(s[i]);
        }
        else
        {
            if(temp.empty())
            {
                return false;
            }
            if(temp.top()=='('&&s[i]==')')
            {
                temp.pop();
            }
            else if(temp.top()=='['&&s[i]==']')
            {
                temp.pop();
            }
            else if(temp.top()=='{'&&s[i]=='}')
            {
                temp.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(temp.empty())
        return true;
    return false;
}