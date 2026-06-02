class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();

        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int land=landStartTime[i]+landDuration[i];
                int f1=max(land,waterStartTime[j])+waterDuration[j];

                int water=waterStartTime[j]+waterDuration[j];
                int f2=max(water,landStartTime[i])+landDuration[i];

                ans=min({ans,f1,f2});

            }
        }
        return ans;

    }
};