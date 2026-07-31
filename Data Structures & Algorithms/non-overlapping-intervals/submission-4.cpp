class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        if(n==1) return 0;
        int i=0;
        int j=1;
        int cnt=0;
        while(j<n){
            int st=intervals[j][0];
            int end=intervals[j][1]; 
            if(intervals[i][1]<=st){
                i=j;
                j++;
            }
            else if(intervals[i][1]<=end){
                j++;
                cnt++;
            }
            else{
                i=j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};
