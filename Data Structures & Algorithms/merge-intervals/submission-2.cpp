class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i=0;
        int maxi=0;
        while(i<n){
            int st=intervals[i][0];
            int end=intervals[i][1];
            if(i==0 || st>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],end);
            }
            i++;
        }
        return ans;
    }
};
