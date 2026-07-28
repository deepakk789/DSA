class Solution {
   public:
    int solve(int x, int y, vector<vector<int>>& dp) {
        if (x == 0 && y == 0) return 1;
        if (x < 0 || y < 0) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = solve(x - 1, y, dp) + solve(x, y - 1, dp);
    }
    int uniquePaths(int m, int n) {
        // tc o(m*n) and sc o((m*n)+(m+n))
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,dp);

        // tabulation
        // to just reduce recursion stack space
        // tc o(mn) and sc o(mn)
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[0][0] = 1;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0 && j == 0)
        //             dp[i][j] = 1;
        //         else {
        //             int right = 0, bottom = 0;
        //             if (i > 0) bottom = dp[i - 1][j];
        //             if (j > 0) right = dp[i][j - 1];
        //             dp[i][j] = right + bottom;
        //         }
        //     }
        // }
        // return dp[m - 1][n - 1];

        // space optimization
        // to just reduce recursion stack space
        // tc o(mn) and sc o(m+n)
        vector<int> prevrow(n);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n,0);
            int right=0,bottom=0;
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0){
                    temp[j]=1;
                }
                else {
                    int right = 0, bottom = 0;
                    if (i > 0) bottom = prevrow[j];
                    if (j > 0) right = temp[j-1];
                    temp[j] = right + bottom;
                }
            }
            prevrow=temp;
        }
        return prevrow[n-1];
    }
};
