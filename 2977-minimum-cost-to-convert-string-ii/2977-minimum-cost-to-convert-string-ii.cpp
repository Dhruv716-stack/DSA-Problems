class Solution {
public:
    unordered_map<string,unordered_map<string,long long>> dijikmemo;
    long long dijikstra(string &s,string &t,unordered_map<string,vector<pair<string,long long>>>&adj)
    {
        if(dijikmemo[s].count(t)) return dijikmemo[s][t];

        priority_queue<pair<long long,string>,vector<pair<long long,string>>,greater<pair<long long ,string>>> pq;
        unordered_map<string,long long> dis;              
        for (auto &it : adj) dis[it.first] = 1e18;
        dis[s]=0;
        pq.push({dis[s],s});
        while(!pq.empty())
        {
            long long d=pq.top().first;
            string node=pq.top().second;
            pq.pop();
            if (d > dis[node]) continue;
            for(auto &it:adj[node])
            {
                long long wt=it.second;
                string adjnode=it.first;
                if (!dis.count(adjnode)) dis[adjnode] = 1e18;
                if(d+wt<dis[adjnode])
                {
                    dis[adjnode]=d+wt;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        return dijikmemo[s][t]= dis.count(t) ? dis[t] : 1e18;
    }

    long long solve(int i,string &source, string &target, vector<long long>&dp,vector<int>&len,unordered_map<string,vector<pair<string,long long>>>&adj)
    {
        int n=source.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        const long long INF = 1e18;                        
        long long w1 = INF;
        if(source[i]==target[i]) w1=solve(i+1,source,target,dp,len,adj);
        long long w2=INF;
        for(int j=0;j<len.size();j++)
        {
            int l=len[j];
            string temp_s="",temp_t="";
            if(i+l<=n)
            {
                temp_s=source.substr(i,l);
                temp_t=target.substr(i,l);
                if(adj.count(temp_s)==0) continue;
                long long cost=dijikstra(temp_s,temp_t,adj);
                if(cost==1e18) continue;
                w2=min({w2,cost+solve(i+l,source,target,dp,len,adj)});
            }
            else break;
        }
        return dp[i]=min(w1,w2);
    }
    long long minimumCost(string source, string target, vector<string>& ori, vector<string>& chan, vector<int>& cost) {
        int n=source.size();
        int n1=ori.size();
        set<string> st;
        for(auto &it:ori) st.insert(it);
        for(auto &it:chan) st.insert(it);
        int v=st.size();
        unordered_map<string,vector<pair<string,long long>>> adj;
        for(int i=0;i<n1;i++)
        {
            adj[ori[i]].push_back({chan[i],cost[i]});
        }

        //set for stroing lengths of ori and chan strings
        set<int> st1;
        for(auto &it:ori) st1.insert(it.size());
        for(auto &it:chan) st1.insert(it.size());
        vector<int> len (st1.begin(),st1.end());
        vector<long long> dp(n,-1);
        long long ans= solve(0,source,target,dp,len,adj);
        if(ans==1e18) return -1;
        return ans;

    }
};