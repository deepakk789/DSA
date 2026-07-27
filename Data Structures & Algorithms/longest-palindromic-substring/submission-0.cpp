class Solution {
public:
    int len=0;
    string ans="";
    map<pair<int,int>,bool> mp;
    bool check_pal(int st,int end,string& s){
        int n=end-st+1;
        if(mp.find({st,end})!=mp.end()) return mp[{st,end}];
        string x=s.substr(st,n);
        
        int i=0;
        int j=n-1;
        bool t=true;
        while(i<=j){
            if(x[i]!=x[j]){
                t=false;
                break;
            }
            i++;
            j--;
        }
        mp[{st,end}]=t;
        if(t){
            ans=x;
        }
        return t;
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(len<j-i+1){
                    if(check_pal(i,j,s)){
                        cout<<i<<j<<len<<endl;
                        len=j-i+1;
                    }
                }
            }
        }
        return ans;
    }
};
