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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n<2) return true;
        sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval& b){
            if(a.start<b.start) return true;
            return false; 
        });
        for(int i=1;i<n;i++){
            int st=intervals[i].start;
            int end=intervals[i].end;
            if(intervals[i-1].end>st){
                return false;
            }
        }
        return true;
    }
};
