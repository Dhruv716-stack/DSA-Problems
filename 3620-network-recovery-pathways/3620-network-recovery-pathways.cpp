class Solution {
public:
    bool check(vector<vector<pair<int,int>>>&adj, long long k, long long mid){
        int n=adj.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dis(n,LLONG_MAX);
        dis[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();

            if(d>k) return false;
            if(d>dis[node]) continue;
            if(node==n-1) return true;

            for(auto &it:adj[node]){
                int adjnode=it.first;
                int edwt=it.second;

                if(edwt<mid) continue;
                if(d+edwt<dis[adjnode]){
                    dis[adjnode]=d+edwt;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        long long mn=LLONG_MAX,mx=LLONG_MIN;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            mn=min(mn,1LL*wt);
            mx=max(mx,1LL*wt);
            if(online[u]==false || online[v]==false) continue;
            adj[u].push_back({v,wt});
        }

        

        long long l=mn,h=mx;
        long long ans=-1;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(check(adj,k,mid)==true){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }

        return ans;
    }
};