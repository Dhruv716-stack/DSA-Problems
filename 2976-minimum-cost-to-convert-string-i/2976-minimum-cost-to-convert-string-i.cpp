class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& ori, vector<char>& chan, vector<int>& cost) {
        int n=ori.size();
        set<char> st;
        unordered_map<char,int> mp;
        for( auto &i:source) st.insert(i);
        for(auto &i:target) st.insert(i);
        for(int i=0;i<n;i++)
        {
            st.insert(ori[i]);
            st.insert(chan[i]);
        }
        int n1=st.size();
        int idx=0;
        for(auto &it:st)
        {
            mp[it]=idx;
            idx++;
        }
        vector<vector<long long>> mat(n1,vector<long long>(n1,1e8));
        for(int i=0;i<n1;i++) mat[i][i]=0;
        for(int i=0;i<n;i++)
        {
            int u=mp[ori[i]];
            int v=mp[chan[i]];
            int wt=cost[i];
            mat[u][v]=min(1LL*wt,mat[u][v]);
        }
        for(int via=0;via<n1;via++)
        {
            for(int i=0;i<n1;i++)
            {
                for(int j=0;j<n1;j++)
                {
                    if(mat[i][via]<1e8 && mat[via][j]<1e8)
                    {mat[i][j]=min(mat[i][j],(mat[i][via]+mat[via][j]));}
                }
            }
        }
        long long ans=0;
        int n2=source.size();
        for(int i=0;i<n2;i++)
        {
            if((mp.find(source[i])==mp.end()) || (mp.find(target[i])==mp.end())) return -1;
            if(mat[mp[source[i]]][mp[target[i]]]==1e8) return -1;
            ans+=mat[mp[source[i]]][mp[target[i]]];
        }
        return ans;
            
    }
};