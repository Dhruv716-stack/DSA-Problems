class Solution {
public:
    void dfs(vector<vector<int>> &image,int sr,int sc,int color,int &oc,int &m,int &n)
    {
        if(oc==color) return;
        if(image[sr][sc]!=oc) return;
        image[sr][sc]=color;
        if(sr+1<m) dfs(image,sr+1,sc,color,oc,m,n);
        if(sr-1>=0) dfs(image,sr-1,sc,color,oc,m,n);
        if(sc+1<n) dfs(image,sr,sc+1,color,oc,m,n);
        if(sc-1>=0) dfs(image,sr,sc-1,color,oc,m,n);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc=image[sr][sc];
        int m=image.size();
        int n=image[0].size();
        dfs(image,sr,sc,color,oc,m,n);
        return image;
    }
};