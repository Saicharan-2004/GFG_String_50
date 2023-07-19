//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int getMaxArea(vector<int>arr, int n)
    {
        vector<int>prevSmaller(n);
        vector<int>nextSmaller(n);
        stack<int>temp;
        for(int i=0;i<n;i++)
        {
            if(temp.empty())
            {
                prevSmaller[i]=-1;
            }
            else
            {
                while(!temp.empty())
                {
                    if(arr[temp.top()]<arr[i])
                    {
                        prevSmaller[i]=temp.top();
                        break;
                    }
                    temp.pop();
                }
                if(temp.empty())
                {
                    prevSmaller[i]=-1;
                }
            }
            temp.push(i);
        }
        while(!temp.empty())
        {
            temp.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            if(temp.empty())
            {
                nextSmaller[i]=-1;
            }
            else
            {
                while(!temp.empty())
                {
                    if(arr[temp.top()]<arr[i])
                    {
                        nextSmaller[i]=temp.top();
                        break;
                    }
                    temp.pop();
                }
                if(temp.empty())
                {
                    nextSmaller[i]=-1;
                }
            }
            temp.push(i);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(prevSmaller[i]==-1&&nextSmaller[i]==-1)
            {
                maxi=max(maxi,n*arr[i]);
            }
            else if(prevSmaller[i]!=-1&&nextSmaller[i]==-1)
            {
                maxi=max(maxi,(i-prevSmaller[i]+n-i-1)*arr[i]);
            }
            else if(prevSmaller[i]==-1&nextSmaller[i]!=-1)
            {
                maxi=max(maxi,nextSmaller[i]*arr[i]);
            }
            else
            {
                maxi=max(maxi,(nextSmaller[i]-prevSmaller[i]-1)*arr[i]);
            }
        }
        return maxi;
    }
    int maxArea(int arr[MAX][MAX], int n, int m) 
    {
        vector<int>ans(m);
        for(int i=0;i<m;i++)
        {
            ans[i]=arr[0][i];
        }
        int maxi=getMaxArea(ans,m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==0)
                {
                    ans[j]=0;
                }
                else
                {
                    ans[j]=ans[j]+arr[i][j];
                }
            }
            maxi=max(maxi,getMaxArea(ans,m));
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends