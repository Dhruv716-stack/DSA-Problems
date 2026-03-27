class Solution {
public:
    void right_cycle(vector<int>&arr,int k)
    {
        int n=arr.size();
        k=k%n;
        for(int i=0;i<n;i++)
        {
            arr[(i+k)%n]=arr[i];
        }
        return;
    }

    void left_cycle(vector<int>&arr,int k)
    {
        int n=arr.size();
        k=k%n;
        for(int i=n-1;i>=0;i--)
        {
            arr[((n+i)-k)%n]=arr[i];
        }
        return;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ori=mat;
        for(int i=0;i<m;i++)
        {
            if(i%2==0) left_cycle(mat[i],k);
            else right_cycle(mat[i],k);
        }
        if(ori==mat) return true;
        return false;
    }
};