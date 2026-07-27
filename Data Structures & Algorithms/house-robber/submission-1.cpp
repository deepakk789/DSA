class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>& dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];

        int take=0;
        int not_take=0;
        take=nums[i]+solve(i-2,nums,dp);
        not_take=solve(i-1,nums,dp);

        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        // tc o(n) and sc o(n)
        // int n=nums.size();
        // vector<int> dp(n,-1);
        // return solve(n-1,nums,dp);

        // Tabulation 
        // tc o(n) and sc o(n)
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        if(n>1) dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};
