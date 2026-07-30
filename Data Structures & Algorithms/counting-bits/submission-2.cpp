class Solution {
public:
    vector<int> countBits(int n) {
        // tc o(32n)
        // vector<int> ans;
        // for(int i=0;i<=n;i++){
        //     int cnt=0;
        //     int i1=i;
        //     while(i1){
        //         i1&=i1-1;
        //         cnt++;
        //     }
        //     ans.push_back(cnt);
        // }
        // return ans;

        // // by dynamic programming 1 tc o(n)
        // vector<int> ans(n+1,0);
        // for(int i=1;i<=n;i++){
        //     ans[i]=ans[i&(i-1)]+1; // because we are using previous values of ans , the logic is remove 1 set bit and get the previous count and just add 1 because you removed one
        // }
        // return ans;

        // // by dynamic programming 2 tc o(n)
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i]=ans[i>>1]+(i&1); // i&1 if Righmost is set then 1 otherwise 0 + the ans[i>>1] means the value at ans (right shifted one time) 
        }
        return ans;
    }
};
