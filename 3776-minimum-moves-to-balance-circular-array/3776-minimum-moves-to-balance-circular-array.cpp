class Solution {
public:
    long long minMoves(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(nums[i]<0) ind=i;
        }
        if(sum<0) return -1;
        if(ind==-1) return 0;
        int j=1;
        long long moves=0;
        while(nums[ind]<0)
        {
            int l=(ind-j+n)%n;
            int r=(ind+j)%n;
            long long t=nums[l]+nums[r];
            if(l==r) t-=nums[l];
            long long mn;
            mn=min(1*llabs(nums[ind]),t);
            moves+=(mn*j);
            nums[ind]+=mn;
            j++;
        }
        return moves;
    }
};