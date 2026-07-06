class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
         int n=v.size();
         vector<vector<int>> res;
         auto lambda=[](vector<int>&v1,vector<int>&v2){
            if(v1[0]==v2[0]) return v1[1]>v2[1];
            return v1[0]<v2[0];
         };
         sort(v.begin(),v.end(),lambda);

         res.push_back(v[0]);
         for(int i=1;i<n;i++){
            if(res.back()[0]<=v[i][0] && v[i][1]<=res.back()[1]) continue;
            res.push_back(v[i]);
         }
         return res.size();
         
    }
};