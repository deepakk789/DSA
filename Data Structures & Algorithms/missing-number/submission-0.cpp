class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<=n;i++) cnt^=i;
        for(int i=0;i<n;i++){
            cnt^=nums[i];
        }
        return cnt;
    }
};
