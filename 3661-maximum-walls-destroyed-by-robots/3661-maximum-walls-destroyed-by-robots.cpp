class Solution {
public:
    int cnt_walls(vector<int>&walls, int l, int r)
    {
        int left=lower_bound(walls.begin(),walls.end(),l)-walls.begin();
        int right=upper_bound(walls.begin(),walls.end(),r)-walls.begin();
        return right-left;
    }

    int solve(vector<int>&walls,vector<pair<int,int>>&arr,vector<pair<int,int>>&range,int i, int pdir,vector<vector<int>>&dp)
    {
        int n=arr.size();
        if(i==n) return 0;
        if(dp[i][pdir]!=-1) return dp[i][pdir];

        int left_start=range[i].first;
        if(pdir==1)
        {
            if(i-1>=0) left_start=max(left_start,range[i-1].second+1);
        }

        int left_take=cnt_walls(walls,left_start,arr[i].first)+solve(walls,arr,range,i+1,0,dp);
        int right_take=cnt_walls(walls,arr[i].first,range[i].second)+solve(walls,arr,range,i+1,1,dp);
        return dp[i][pdir]=max(left_take,right_take);
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        vector<pair<int,int>> arr;
        vector<pair<int,int>> range;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        for(int i=0;i<n;i++)
        {
            arr.push_back({robots[i],distance[i]});
        }
        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++)
        {
            int pos=arr[i].first;
            int d=arr[i].second;
            int lr=(i==0)?1:arr[i-1].first+1;
            int ur= (i==n-1)?1e9:arr[i+1].first-1;

            int L=max(pos-d,lr);
            int R=min(pos+d,ur);
            range.push_back({L,R});
        }
        sort(walls.begin(),walls.end());
        return solve (walls,arr,range,0,0,dp);
    }
};