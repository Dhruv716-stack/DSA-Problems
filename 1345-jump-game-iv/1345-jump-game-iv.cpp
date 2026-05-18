class Solution {
public:
    typedef long long ll;
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        int ans=0;
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int i=q.front();
                q.pop();

                if(i==n-1) return ans;

                if(i+1<n && vis[i+1]==0)
                {
                    q.push(i+1);
                    vis[i+1]=1;
                }

                if(i-1>=0 && vis[i-1]==0)
                {
                    vis[i-1]=1;
                    q.push(i-1);
                }

                for(auto &it:mp[arr[i]])
                {
                    if(it==i) continue;
                    if(vis[it]==0)
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
                mp[arr[i]].clear();
            }
            ans++;
        }
        return -1;

    }
};