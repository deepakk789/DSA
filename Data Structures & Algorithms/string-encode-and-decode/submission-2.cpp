class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string encoded="";
        for(int i=0;i<n;i++){
            int m=strs[i].size();
            encoded+=to_string(m)+'#';
            encoded+=strs[i];
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int n=s.size();
        string basic="";
        int i=0;
        while(i<n){
            string len="";
            while(s[i]!='#'){
                len+=s[i];
                i++;
            }
            int m=stoi(len);
            int j=0;
            i+=1;
            string each="";
            while(j<m){
                each+=s[i];
                i++;
                j++;
            }
            decoded.push_back(each);
        }
        return decoded;
    }
};