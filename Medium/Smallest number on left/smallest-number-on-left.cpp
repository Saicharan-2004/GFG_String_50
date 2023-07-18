//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[])
    {
        stack<int>temp;
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(temp.empty())
            {
                ans[i]=-1;
            }
            else
            {
                while(!temp.empty())
                {
                    if(temp.top()<arr[i])
                    {
                        ans[i]=temp.top();
                        break;
                    }
                    temp.pop();
                }
                if(temp.empty())
                {
                    ans[i]=-1;
                }
            }
            temp.push(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends