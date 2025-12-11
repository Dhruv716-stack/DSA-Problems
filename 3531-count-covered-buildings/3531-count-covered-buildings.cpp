class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,set<int>> mp1,mp2;
        for(auto i:buildings)
        {
            int x=i[0];
            int y=i[1];
            mp1[x].insert(y);
            mp2[y].insert(x);
        }
        int cnt=0;
        for(auto i:buildings)
        {
            int x=i[0];
            int y=i[1];
            if(*mp1[x].begin()==y || *mp2[y].begin()==x) continue;
            if(*mp1[x].rbegin()==y || *mp2[y].rbegin()==x) continue;
            cnt++;
        }
        return cnt;
    }
};