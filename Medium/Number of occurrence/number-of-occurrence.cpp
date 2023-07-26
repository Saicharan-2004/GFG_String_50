//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int last(int arr[],int n,int x)
	{
	    int start=0;
	    int end=n-1; 
	    int lastocc=-1;
	    while(start<=end)
	    {
	        int mid=start+end;
	        mid=mid/2;
	        if(arr[mid]==x)
	        {
	            lastocc=mid;
	            start=mid+1;
	        }
	        else
	        {
	            if(arr[mid]<x)
	            {
	                start=mid+1;
	            }
	            else
	            {
	                end=mid-1;
	            }
	        }
	    }
	    return lastocc;
	}
	int first(int arr[],int n,int x)
	{
	    int start=0;
	    int end=n-1; 
	    int firstocc=-1;
	    while(start<=end)
	    {
	        int mid=start+end;
	        mid=mid/2;
	        if(arr[mid]==x)
	        {
	            firstocc=mid;
	            end=mid-1;
	        }
	        else
	        {
	            if(arr[mid]<x)
	            {
	                start=mid+1;
	            }
	            else
	            {
	                end=mid-1;
	            }
	        }
	    }
	    return firstocc;
	}
	int count(int arr[], int n, int x) 
	{
	    //
	    int f=first(arr,n,x);
	    if(f==-1)
	    {
	        return 0;
	    }
	    int l=last(arr,n,x);
	    return l-f+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends