//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) 
    {
        stack<int>five;
        stack<int>ten;
        for(auto it:bills)
        {
            if(it==5)
            {
                five.push(5);
            }
            else if(it==10)
            {
                if(!five.empty())
                {
                    five.pop();
                    ten.push(10);
                }
                else
                {
                    return false;
                }
            }
            else 
            {
                if(!ten.empty())
                {
                    if(!five.empty())
                    {
                        ten.pop();
                        five.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(five.size()>=3)
                    {
                        five.pop();
                        five.pop();
                        five.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends