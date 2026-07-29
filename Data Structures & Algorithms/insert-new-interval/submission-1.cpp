class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int x = newInterval[0];
        int y = newInterval[1];
        int mini = x;
        int maxi = y;
        vector<vector<int>> ans;
        bool t = false;
        for (int i = 0; i < n; i++) {
            int x1 = intervals[i][0];
            int y1 = intervals[i][1];
            if (y1 < x)
                ans.push_back({x1, y1});
            else if (x1 > y) {
                if (!t) {
                    ans.push_back({mini, maxi});
                    t = true;
                }
                ans.push_back({x1, y1});
            } else {
                mini = min(mini, x1);
                maxi = max(maxi, y1);
            }
        }
        if (!t) ans.push_back({mini, maxi});
        return ans;
    }
};
