//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {
    
    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << save_gotham(arr, n) << endl;
    }
    
	return 0;
}
// } Driver Code Ends

int mod=1000000001;
int save_gotham(int arr[], int n)
{
    vector<int>greater(n);
    stack<int>temp;
    for(int i=n-1;i>=0;i--)
    {
        if(temp.empty())
        {
            greater[i]=0;
        }
        else
        {
            while(!temp.empty())
            {
                if(temp.top()>arr[i])
                {
                    greater[i]=temp.top();
                    break;
                }
                temp.pop();
            }
            if(temp.empty())
            {
                greater[i]=0;
            }
        }
        temp.push(arr[i]);
    }
    int sum=0;
    for(auto it:greater)
    {
        sum+=it;
    }
    return sum%mod;
}