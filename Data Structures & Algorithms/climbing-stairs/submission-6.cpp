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
        // tc o(n) and sc o(n+n)
        // vector<int> dp(n+1,-1);
        // return solve(n,dp); 

        // tabulation
        // tc o(n) and sc o(n)
        // vector<int> dp(n+1,0);
        // dp[1]=1;
        // if(n>1) dp[2]=2; 
        // for(int i=3;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];

        // space optimization
        // tc o(n) and sc o(1)
        int prev=1;
        int prev_prev=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=prev+prev_prev;
            prev_prev=prev;
            prev=ans;
        }
        return ans;
    }
};
