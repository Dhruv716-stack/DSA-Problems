class Solution {
public:
    int diff(string &s1, string &s2){
        int n=s1.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
        }
        return cnt;
    }

    unordered_map<string,vector<string>> make_adj(vector<string> &v){
        int n=v.size();
        int m=v[0].size();
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt=diff(v[i],v[j]);
                if(cnt==1){
                    mp[v[i]].push_back(v[j]);
                    mp[v[j]].push_back(v[i]);
                }
            }
        }

        return mp;
    }

    int bfs(string snode, unordered_map<string,int> &vis, unordered_map<string,vector<string>>&adj, string des){
        queue<pair<string,int>> q;
        q.push({snode,1});
        vis[snode]=1;

        while(!q.empty()){
            string node=q.front().first;
            int d=q.front().second;

            q.pop();
            if(node==des) return d;

            for(auto &it:adj[node]){
                if(vis.find(it)==vis.end()){
                    q.push({it,d+1});
                    vis[it]=1;
                }
            }
        }

        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string,vector<string>> adj;
        adj=make_adj(wordList);

        unordered_map<string,int> vis;
        
        int ans=bfs(beginWord,vis,adj,endWord);
        return ans;

    }
};