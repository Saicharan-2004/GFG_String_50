//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n=arr.size();
        stack<int>temp;
        vector<int>nextSmaller;
        vector<int>prevSmaller;
        for(int i=0;i<arr.size();i++)
        {
            if(temp.empty())
            {
                prevSmaller.push_back(-1);
            }
            else
            {
                while(!temp.empty())
                {
                    if(arr[temp.top()]<arr[i])
                    {
                        prevSmaller.push_back(temp.top());
                        break;
                    }
                    temp.pop();
                }
                if(temp.empty())
                {
                    prevSmaller.push_back(-1);
                }
            }
            temp.push(i);
        }
        while(!temp.empty())
        {
            temp.pop();
        }
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(temp.empty())
            {
                nextSmaller.push_back(-1);
            }
            else
            {
                while(!temp.empty())
                {
                    if(arr[temp.top()]<arr[i])
                    {
                        nextSmaller.push_back(temp.top());
                        break;
                    }
                    temp.pop();
                }
                if(temp.empty())
                {
                    nextSmaller.push_back(-1);
                }
            }
            temp.push(i);
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<nextSmaller[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<prevSmaller[i]<<" ";
        // }
        // cout<<endl;
        reverse(nextSmaller.begin(),nextSmaller.end());
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nextSmaller[i]==-1&&prevSmaller[i]==-1)
            {
                ans.push_back(-1);
            }
            else if(nextSmaller[i]==-1&&prevSmaller[i]!=-1)
            {
                ans.push_back(prevSmaller[i]);
            }
            else if(nextSmaller[i]!=-1&&prevSmaller[i]==-1)
            {
                ans.push_back(nextSmaller[i]);
            }
            else
            {
                if(abs(i-prevSmaller[i])<abs(i-nextSmaller[i]))
                {
                    ans.push_back(prevSmaller[i]);
                }
                else if(abs(i-prevSmaller[i])>abs(i-nextSmaller[i]))
                {
                    ans.push_back(nextSmaller[i]);
                }
                else
                {
                    if(arr[prevSmaller[i]]<arr[nextSmaller[i]])
                    {
                        ans.push_back(prevSmaller[i]);
                    }
                    else if(arr[prevSmaller[i]]>arr[nextSmaller[i]])
                    {
                        ans.push_back(nextSmaller[i]);
                    }
                    else
                    {
                        ans.push_back(min(nextSmaller[i],prevSmaller[i]));
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends