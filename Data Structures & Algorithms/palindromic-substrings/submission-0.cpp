class Solution {
public:
    int solve(int st,int end,string& s){
        if(st>end) return 1;
        // if(dp[st][end]!=-1) return dp[st][end];
        int cnt=0;
        if(s[st]==s[end]){
            cnt+=solve(st+1,end-1,s);
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                cnt+=solve(i,j,s);
            }
        }
        return cnt;
    }
};
