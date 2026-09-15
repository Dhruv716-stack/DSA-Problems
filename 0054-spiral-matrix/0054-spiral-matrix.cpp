class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int l=0;
        int r=n-1,t=0,b=m-1;
        vector<int> ans;
        while(t<=b && l<=r){
            for(int i=l;i<=r;i++) ans.push_back(mat[t][i]);
            t++;

            for(int i=t;i<=b;i++) ans.push_back(mat[i][r]);
            r--;

            if(t<=b){
                for(int i=r;i>=l;i--) ans.push_back(mat[b][i]);
                b--;
            }

            if(l<=r){
                for(int i=b;i>=t;i--) ans.push_back(mat[i][l]);
                l++;
            }
        }

        return ans;
    }
};