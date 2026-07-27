class Solution {
public:
    bool check_pal(int st,int end,string& s,vector<vector<int>>& dp){
        if(st>=end) return true;

        if(dp[st][end]!=-1) return dp[st][end];
        bool t=false;
        if(s[st]==s[end]){
            t=check_pal(st+1,end-1,s,dp);
        }

        return dp[st][end]=t;
    }
    
    string longestPalindrome(string s) {
        // recursive palindrome check will work in the memoization 
        // iterative cannot work
        int n=s.size();
        int starti=0;
        int len=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(len<j-i+1){
                    if(check_pal(i,j,s,dp)){
                        starti=i;
                        len=j-i+1;
                    }
                }
            }
        }
        return s.substr(starti,len);
    }
};