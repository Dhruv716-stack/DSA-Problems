class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> events;
        for(auto &it:logs)
        {
            events.push_back({it[0],1});
            events.push_back({it[1],-1});
        }
        sort(events.begin(),events.end());
        int ans=2050;
        int mx=0;
        int curr=0;
        for(auto &it:events)
        {
            curr+=it.second;
            if(curr>mx)
            {
                mx=curr;
                ans=it.first;
            }
        }
        return ans;
    }

};