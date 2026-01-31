class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> events;
        for(auto &it:trips)
        {
            int del=it[0];
            int from=it[1];
            int to=it[2];
            events.push_back({from,del});
            events.push_back({to,-del});
        }
        sort(events.begin(),events.end());
        int curr=0;
        for(auto &it:events)
        {
            curr+=it.second;
            if(curr>capacity) return false;
        }
        return true;
    }
};