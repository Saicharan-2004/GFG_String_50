//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) 
    {
        // sort(arr.begin(),arr.end());
        vector<long long>prefix;
        long long int sum=0;
        // prefix.push_back(arr[0]);
        int count=0;
        for(auto it:arr)
        {
            sum+=it;
            if(sum==0)
            {
                count++;
            }
            prefix.push_back(sum);
        }
        unordered_map<long long,long long int>r;
        long long int final=0;
        for(auto it:prefix)
        {
            r[it]++;
            // cout<<it<<" ";
        }
        for(auto it:r)
        {
            if(it.second>1)
            {
                final+=((it.second)*(it.second-1))/2;
            }
        }
        return final+count;
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
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends