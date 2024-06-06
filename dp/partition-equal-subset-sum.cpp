#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rec(vector<int>& nums, int i, int t) {
        if (i == nums.size() - 1) {
            if (nums[i] == t) {
                return true;
            } else {
                return false;
            }
        }
        bool ans = (rec(nums, i + 1, t-nums[i])) or
                   (rec(nums, i + 1, t));

        return ans;
    }

    bool soldp(vector<int>& nums, int i, long long t, vector<vector<int>> &dp) {
        if(t<0) return false;
        if(t==0) return true;
        if (i == nums.size() - 1) {
            if (nums[i] == t) {
                return true;
            } else {
                return false;
            }
        }
        if(dp[i][t]!= -1) return dp[i][t];

        bool ans = (soldp(nums, i + 1, t-nums[i],dp)) or
                   (soldp(nums, i + 1, t,dp));

        return dp[i][t] = ans;
    }
    bool canPartition(vector<int>& nums) {

        
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }

        if(sum%2 != 0) return false;
        else{
            long long t = sum/2;
            vector<vector<int>> dp(nums.size(),vector<int>(t+1,-1));
            bool ans = soldp(nums,0,t,dp);
            return ans;
        }
    }

    
};

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int> nums;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        
        Solution ob;
        //calling method knapSack()
        cout<< ob.canPartition(nums) <<endl;
        
    }
	return 0;
}