class Solution {
public:
    bool solvewithdp(int ind,vector<int>& nums,vector<int>& dp){
        if(ind==0) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind-1;i>=0;i--){
            if(nums[i]>(ind-1)-i && solvewithdp(i,nums,dp)){
                return dp[i]=true;
            }
        }
        return dp[ind]=false;
    }
    bool solve(int ind,vector<int>& nums){
        if(ind==0) return true;
        for(int i=ind-1;i>=0;i--){
            if(nums[i]>(ind-1)-i && solve(i,nums)){
                cout<<i<<endl;
                cout<<ind<<'h'<<endl;
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        // int n=nums.size();
        // return solve(n-1,nums);


        int n=nums.size();
        vector<int> dp(n,-1);
        return solvewithdp(n-1,nums,dp);


    }
};
