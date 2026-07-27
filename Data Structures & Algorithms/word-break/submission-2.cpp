class Solution {
   public:
    bool solve(int ind, string s, unordered_set<string>& st,vector<int>& dp) {
        int n=s.size();
        if(ind>=n) return true;
        if(dp[ind]!=-1) return dp[ind];
        for (int i = 1; i <= (n-ind); i++) {
            string x=s.substr(ind,i);
            if(st.find(x)!=st.end() && solve(ind+i,s,st,dp)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = wordDict.size();
        int m=s.size();
        vector<int> dp(m,-1);
        for (int i = 0; i < n; i++) {
            st.insert(wordDict[i]);
        }
        return solve(0, s, st,dp);
    }
};
