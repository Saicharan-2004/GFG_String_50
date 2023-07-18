//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long>prevSmaller(n);
        vector<long long>nextSmaller(n);
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
        long long maxi=INT_MIN;
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
                maxi=max(maxi,(nextSmaller[i]-i+i)*arr[i]);
            }
            else
            {
                maxi=max(maxi,(nextSmaller[i]-prevSmaller[i]-1)*arr[i]);
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends