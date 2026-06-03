class Solution {
public:
    int finish(vector<int>&start1,vector<int>&dur1,vector<int>&start2,vector<int>&dur2)
    {
        int n=start1.size();
        int m=start2.size();
        int f1=INT_MAX;
        for(int i=0;i<n;i++)
        {
            f1=min(f1,start1[i]+dur1[i]);
        }

        int f=INT_MAX;
        for(int i=0;i<m;i++)
        {
            f=min(max(f1,start2[i])+dur2[i],f);
        }
        return f;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int fl=finish(landStartTime,landDuration,waterStartTime,waterDuration);
        int fw=finish(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(fl,fw);
    }
};