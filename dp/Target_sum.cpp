#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solrec(vector<int>& nums, int indx, int target, int n){
        
        if(indx == n-1){
            if(target == nums[indx] or -target == nums[indx]){
                return 1;
            }else{
                return 0;
            }
        }

        int inc1 = 0;
        int inc2 = 0;

        inc1 = solrec(nums,indx+1,target-nums[indx],n);
        inc2 = solrec(nums,indx+1,target+nums[indx],n);
        
        return (inc1+inc2);
    }

    int soldp(vector<int>& nums, int indx, int target, int n, vector<vector<int>> &dp, int sum ){
        if(target > 2*sum or target < -2*sum){
            return 0;
        }
        if(indx == n-1){
            if((target - nums[indx] == sum) and (target + nums[indx] == sum)){
                return 2;
            }else if((target - nums[indx] == sum) or (target + nums[indx] == sum)){
                return 1;
            }else{
                return 0;
            }
        }
        

        int inc1 = 0;
        int inc2 = 0;

        if(dp[indx][target] != -1){
            return dp[indx][target];
        }

        inc1 = soldp(nums,indx+1,target-nums[indx],n,dp,sum);
        inc2 = soldp(nums,indx+1,target+nums[indx],n,dp,sum);
        
        return dp[indx][target] = (inc1+inc2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += abs(nums[i]);
        }
        if((target > sum) or (target < -1*sum)){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(sum*2+1,-1));
        
        int ans = soldp(nums,0,sum+target,n,dp,sum);
        return ans;
    }
};