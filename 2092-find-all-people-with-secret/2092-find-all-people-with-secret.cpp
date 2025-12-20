class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
         map<int,vector<pair<int,int>>> time_meetings;
         for(auto &it:meetings)
         {
            int t=it[2];
            int u=it[0];
            int v=it[1];
            time_meetings[t].push_back({u,v});
         }

         vector<int> knows_secret(n,0);
         knows_secret[0]=knows_secret[firstPerson]=1;

         for(auto &it:time_meetings)
         {
            int t=it.first;
            vector<pair<int,int>> meets=it.second;

            //Forming adjancey list
            queue<int> q;
            unordered_set<int> already_add;
            unordered_map<int,vector<int>>adj;

            for(auto &i:meets)
            {
                int p1=i.first;
                int p2=i.second;
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);

                if(knows_secret[p1]==1 && already_add.find(p1)==already_add.end())
                {
                    q.push(p1);
                    already_add.insert(p1);
                }

                if(knows_secret[p2]==1 && already_add.find(p2)==already_add.end())
                {
                    q.push(p2);
                    already_add.insert(p2);
                }
            }

            while(!q.empty())
            {
                int person=q.front();
                q.pop();
                for(auto &p:adj[person])
                {
                    if(knows_secret[p]!=1 && already_add.find(p)==already_add.end())
                    {
                        knows_secret[p]=1;
                        q.push(p);
                        already_add.insert(p);
                    }
                }
            }
         }

         vector<int> result;
         for(int i=0;i<n;i++)
         {
            if(knows_secret[i]==1) result.push_back(i);
         }
         return result;







    }
};