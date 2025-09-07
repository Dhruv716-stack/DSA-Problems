class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j) dist[i][j]=0;
                    if(dist[i][k]==INT_MAX|| dist[k][j]==INT_MAX) continue;
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
        int cnt_max=n;
        int city_no=-1;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=distanceThreshold) cnt++;
                
            }
            if(cnt<=cnt_max)
            {
                cnt_max=cnt;
                city_no=i;
            }
        }
        return city_no;
    }
};