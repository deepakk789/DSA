class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int step1=0,step2=0;
        if(n>=1) step1=solve(n-1,dp);
        if(n>=2) step2=solve(n-2,dp);
        cout<<dp[n]<<endl;
        return dp[n]=step1+step2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        return solve(n,dp); 
    }
};
