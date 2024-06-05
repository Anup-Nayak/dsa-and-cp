//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int rec(int wt[], int val[], int indx, int w){
        
        //base case
        if(indx==0){
            if(wt[0]<=w){
                return val[0];
            }else{
                return 0;
            }
        }
        
        int include;
        int exclude;
        
        if(wt[indx] <= w){
            include = val[indx]+ rec(wt,val,indx-1,w-wt[indx]);
            exclude = rec(wt,val,indx-1,w);
            return max(include,exclude);
        }else{
            exclude = rec(wt,val,indx-1,w);
            return exclude;
        }
    }
    
    int dp(int wt[], int val[], int indx, int w, vector<vector<int>> &dp){
        
        //base case
        if(indx==0){
            if(wt[0]<=w){
                return val[0];
            }else{
                return 0;
            }
        }
        
        if(dp[indx][w] != -1) return dp[indx][w];

        int include;
        int exclude;
        
        if(wt[indx] <= w){
            include = val[indx]+ rec(wt,val,indx-1,w-wt[indx]);
            exclude = rec(wt,val,indx-1,w);
            return dp[indx][w]= max(include,exclude);
        }else{
            exclude = rec(wt,val,indx-1,w);
            return dp[indx][w]= exclude;
        }
    }
    
    int tab(int wt[], int val[],int n,int w){

        vector<vector<int>> dp(n,vector<int>(w+1,0));

        //base case
        for(int i=wt[0];i<w+1;i++){
            if(wt[0]<= w){
                dp[0][i]=val[0];
            }else{
                dp[0][i]=0;
            }
        }


        //recursive calls
        for(int i=1;i<n;i++){
            for(int j=0;j<w+1;j++){
                int include=0;
                int exclude=0;
                if(wt[i] <= j){
                    include = val[i]+ dp[i-1][j-wt[i]];
                    exclude = dp[i-1][j];
                    dp[i][j]= max(include,exclude);
                }else{
                    exclude = dp[i-1][j];
                    dp[i][j]= exclude;
                }
            }
            
        }
        return dp[n-1][w];
    }


    int knapSack(int W, int wt[], int val[], int n) 
    { 
    // vector<vector<int>> dp1(n,vector<int>(W+1,-1));
    // int ans = dp(wt,val,n-1,W,dp1);
       int ans = tab(wt,val,n,W);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends