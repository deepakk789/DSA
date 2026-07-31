/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> v;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            v.push_back({intervals[i].start,0});
            v.push_back({intervals[i].end,1});
        }
        
        sort(v.begin(),v.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            if(a.first<b.first) return true;
            if(a.first==b.first && a.second>b.second) return true;
            return false; 
        });
        int maxcnt=0;
        int cnt=0;
        for(int i=0;i<2*n;i++){
            if(v[i].second==0) cnt++;
            else cnt--;
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt; 
    }
};
