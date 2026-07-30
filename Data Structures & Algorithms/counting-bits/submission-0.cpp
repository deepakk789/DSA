class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int cnt=0;
            int i1=i;
            while(i1){
                i1&=i1-1;
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
