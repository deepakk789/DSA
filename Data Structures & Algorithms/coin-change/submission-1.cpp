class Solution {
public:
    int solve(int ind,int target,vector<vector<int>>& dp,vector<int>& coins){
        if(target<0 || ind<0) return 1e4+1;
        if(target==0) return 0;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int take=1+solve(ind,target-coins[ind],dp,coins);
        int not_take=solve(ind-1,target,dp,coins);
        return dp[ind][target]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); 
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,dp,coins);
        return (ans>=1e4)? -1:ans;
    }
};
