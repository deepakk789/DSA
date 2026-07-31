class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;//left
        int b=n-1;//bottom
        int t=0;//top
        int r=m-1;//right
        vector<int> ans;
        while(l<=r && t<=b){
            int i=l;
            while(i<=r){//right move
                ans.push_back(matrix[t][i]);
                i++;
            }
            t++;
            cout<<t<<" "<<r<<" "<<l<<" "<<b<<endl;
            i=t;
            while(i<=b){//right move
                ans.push_back(matrix[i][r]);
                i++;
            }
            r--;
            i=r;
            while(i>=l && t<=b){//right move
                ans.push_back(matrix[b][i]);
                i--;
            }
            b--;
            cout<<b<<endl;
            i=b;
            while(i>=t && l<=r){//right move
                ans.push_back(matrix[i][l]);
                i--;
            }
            l++;
        }
        return ans;
    }
};
