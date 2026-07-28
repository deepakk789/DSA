class Solution {
public:
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
        int n=nums.size();
        return solve(n-1,nums);
    }
};
