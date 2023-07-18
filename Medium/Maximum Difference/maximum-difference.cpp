//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int findMaxDiff(int arr[], int n)
    {
        stack<int>temp;
        vector<int>leftSmaller;
        vector<int>rightSmaller;
        for(int i=n-1;i>=0;i--)
        {
            if(temp.empty())
            {
                rightSmaller.push_back(0);
            }
            else
            {
                while(!temp.empty())
                {
                    if(temp.top()<arr[i])
                    {
                        rightSmaller.push_back(temp.top());
                        break;
                    }
                    temp.pop();
                }
                if(temp.empty())
                {
                    rightSmaller.push_back(0);
                }
            }
            temp.push(arr[i]);
        }
        while(!temp.empty())
        {
            temp.pop();
        }
        for(int i=0;i<n;i++)
        {
            if(temp.empty())
            {
                leftSmaller.push_back(0);
            }
            else
            {
                while(!temp.empty())
                {
                    if(temp.top()<arr[i])
                    {
                        leftSmaller.push_back(temp.top());
                        break;
                    }
                    temp.pop();
                }
                if(temp.empty())
                {
                    leftSmaller.push_back(0);
                }
            }
            temp.push(arr[i]);
        }
        reverse(rightSmaller.begin(),rightSmaller.end());
        int maxDif=INT_MIN;
        // for(int i=0;i<leftSmaller.size();i++)
        // {
        //     cout<<leftSmaller[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<rightSmaller[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<n;i++)
        {
            maxDif=max(maxDif,abs(rightSmaller[i]-leftSmaller[i]));
        }
        return maxDif;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends