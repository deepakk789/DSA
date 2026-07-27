class Solution {
public:
    int solve(int st,int end,vector<vector<int>> &dp,vector<int>& nums){
        if(st==end) return nums[st];
        if(dp[st][end]!=INT_MIN) return dp[st][end];
        return dp[st][end]=nums[end]*solve(st,end-1,dp,nums);
    }
    int maxProduct(vector<int>& nums) {
        // // tc o(n*n) and sc o(n*n)
        // int n=nums.size();
        // int lar=INT_MIN;
        // vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         lar=max(lar,solve(i,j,dp,nums));
        //     }
        // }
        // return lar;

        // methid 2 with sc o(1) and tc o(n)
        // excellent solution , very easy
        int n=nums.size();
        int prefix=1;
        int suffix=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            prefix*=nums[i];
            suffix*=nums[n-1-i];
            maxi=max(maxi,max(prefix,suffix));
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
        }
        return maxi;
    }
};
