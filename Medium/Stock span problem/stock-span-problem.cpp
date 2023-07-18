//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       vector<int>ans;
       stack<int>temp;
       for(int i=0;i<n;i++)
       {
           if(temp.empty())
           {
               ans.push_back(1);
           }
           else
           {
               int count=1;
               while(!temp.empty())
               {
                   if(arr[temp.top()]>arr[i])
                   {
                       ans.push_back(i-temp.top());
                       break;
                   }
                   temp.pop();
               }
               if(temp.empty())
               {
                   ans.push_back(i+1);
               }
           }
           temp.push(i);
       }
       return ans;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends