class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;

        vector<int> cntt(n,0);
        int t=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target) t++;
            cntt[i]=t;
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                int cnt=0;
                if(i==0 || j==0) cnt=cntt[j];
                else cnt=cntt[j]-cntt[i-1];
                if(cnt>((j-i+1)/2)) ans++;
            }
        }

        return ans;
    }
};