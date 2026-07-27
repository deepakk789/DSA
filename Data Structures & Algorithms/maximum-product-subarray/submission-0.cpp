class Solution {
public:
    int solve(int st,int end,vector<vector<int>> &dp,vector<int>& nums){
        if(st==end) return nums[st];
        if(dp[st][end]!=INT_MIN) return dp[st][end];
        return dp[st][end]=nums[end]*solve(st,end-1,dp,nums);
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int lar=INT_MIN;
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                lar=max(lar,solve(i,j,dp,nums));
            }
        }
        return lar;
    }
};
