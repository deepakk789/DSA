class Solution {
   public:
    int solve(int i, int start, vector<int>& nums, vector<int>& dp) {
        if (i < start) return 0;
        if (dp[i] != -1) return dp[i];

        int take = 0;
        int not_take = 0;
        take = nums[i] + solve(i - 2, start, nums, dp);
        not_take = solve(i - 1, start, nums, dp);

        return dp[i] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        // tc o(2n) and sc o(2n+n)
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int x = max(solve(n - 2, 0, nums, dp1), solve(n - 1, 1, nums, dp2));
        return x;
    }
};
