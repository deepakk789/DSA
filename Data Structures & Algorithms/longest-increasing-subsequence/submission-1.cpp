class Solution {
public:
    int solve(int ind,vector<int> &dp,vector<int>& nums){
        if(ind==0) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int take=1;
        for(int i=ind-1;i>=0;i--){
            if(nums[i]<nums[ind]){
                take=max(take,1+solve(i,dp,nums));
            }
        }
        return dp[ind]=take;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int take=0;
        for(int i=n-1;i>=0;i--) take=max(take,solve(i,dp,nums));
        return take;
    }
};
