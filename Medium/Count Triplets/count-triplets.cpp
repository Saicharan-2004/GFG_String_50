//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    Node*temp=head;
    int counter=0;
    vector<int>final;
    while(temp!=NULL)
    {
        final.push_back(temp->data);
        temp=temp->next;
    }
    int n=final.size();
    for(int i=n-1;i>=2;i--)
    {
        int start=0;
        int end=i-1;
        while(start<end)
        {
            int sum=final[start]+final[end]+final[i];
            if(sum==x)
            {
                counter++;
                end--;
                start++;
            }
            else if(sum>x)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
    }
    return counter;
} 