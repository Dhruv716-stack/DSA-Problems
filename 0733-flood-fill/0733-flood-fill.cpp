class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int c=image[sr][sc];
        q.push({sr,sc});
        vis[sr][sc]=1;
        image[sr][sc]=color;

        vector<int> del_x={0,1,0,-1};
        vector<int> del_y={1,0,-1,0};

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+del_x[i];
                int ny=y+del_y[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==0 && image[nx][ny]==c){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                    image[nx][ny]=color;
                }
            }
        }

        return image;
    }
};